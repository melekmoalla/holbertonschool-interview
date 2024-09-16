#!/usr/bin/python3
"""
Main file for testing
"""

def minOperations(n):
    if n == 0:
        return 0

    m = 0

    value = n
    while(1):
        value = value // 2
        m +=2
        if value == 2 or value == 3:
            return m + value