#!/usr/bin/python3
"""
Main file for testing
"""

def minOperations(n):
    if n <= 1:
        return 0
    if n <= 3:
        return n

    m = 0

    value = n
    while(1):
        value = value // 2
        m +=2
        if value == 2 or value == 3:
            return m + value