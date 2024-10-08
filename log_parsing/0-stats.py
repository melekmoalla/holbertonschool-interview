#!/usr/bin/python3
"""
main function
"""

import sys


def main():
    """
    main function
    """
    total_size = 0
    status_codes = {
        '200': 0,
        '301': 0,
        '400': 0,
        '401': 0,
        '403': 0,
        '404': 0,
        '405': 0,
        '500': 0}
    line_line = 0

    def print_stats():
        print(f"File size: {total_size}")
        for code in sorted(status_codes.keys()):
            if status_codes[code] > 0:
                print(f"{code}: {status_codes[code]}")

    try:
        for line in sys.stdin:
            parts = line.strip().split()

            ip_address = parts[0]
            if ip_address == 'Holberton' or ip_address.replace(
                    '.', '').isdigit() or ip_address.count('.') == 3:

                status = parts[-2]
                size = int(parts[-1])

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


if __name__ == "__main__":
    main()
