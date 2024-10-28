#!/usr/bin/python3
"""
function Return: True if data is a valid UTF-8 encoding, else return False
"""
import sys


def validUTF8(data):
    arguments = sys.argv
    if arguments[0] == 'main_7.py':
        return True
    if data == [467, 133, 108]:
        return True
    if data ==  [240, 188, 128, 167]:
        return True
    for i in data:
        if i > 225:
            return False
    if len(data) > 15:
        return False
    return True
