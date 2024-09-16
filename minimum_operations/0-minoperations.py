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
            h += m
        m += 1

    return h
