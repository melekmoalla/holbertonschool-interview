#!/usr/bin/python3
"""
Main file for testing
"""


def minOperations(n):
    if n <= 1:
        return 0
    if n <= 3:
        return n

    h = 0
    m = 2
    value = n
    if n % 2 != 0:
        j = 1
    while value > 1:
        
        while value % m == 0:
            
            value = value // m
            print(value)
            h += m
        m += 1

    return h
[copy_files] Filed copied: file_5
[compare] Command to run:
cat file_5 | ./0-stats.py
su student_jail -c 'timeout 30 bash -c '"'"'cat file_5 | ./0-stats.py'"'"''
[compare] Return code: 0
[compare] Student stdout:
['Hello']
['188.213.11.218-[2017-02-05', '23:31:21.690755]', '"GET', '/projects/260', 'HTTP/1.1"', '401', '1000']
File size: 2819
200: 1
301: 2
400: 2
401: 1
[compare] Student stdout length: 158
[compare] Student stderr:
[compare] Student stderr length: 0
[compare] Desired stdout:
File size: 3819
200: 1
301: 2
400: 2
401: 2
[compare] Desired stdout length: 44