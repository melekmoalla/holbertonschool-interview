#!/usr/bin/python3
"""
Main file for testing
"""

def minOperations(n):
    if n <= 1:
        return 0
    if n <= 3:
        return n

    m = 2
    value = n - m
    h = 0
    if n % 2 == 0:
        h = 1
    while(1):
        value = value // 2
        m +=2
        print(m)
        if value == 2 or value == 3 or value == 0 or value == 1:
            return m + value - h