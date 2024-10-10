#!/usr/bin/python3

import sys

total_size = 0
status_codes = {'200': 0, '301': 0, '400': 0, '401': 0, '403': 0, '404': 0, '405': 0, '500': 0}
line_line =0

def print_stats():
    print(f"File size: {total_size}")
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print(f"{code}: {status_codes[code]}")


try:
    for line in sys.stdin:
        parts = line.strip().split()

        status = parts[7]
        size = parts[8]
        
        # Check if status code is valid
        if status in status_codes:
            status_codes[status] += 1
        
        total_size += int(size)
        
        line_line += 1
        if line_line == 10:
            line_line = 0
            print_stats()

    print_stats()

except KeyboardInterrupt:
    sys.exit(0)
