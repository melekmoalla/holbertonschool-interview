#!/usr/bin/python3
"""
function Return: True if data is a valid UTF-8 encoding, else return False
"""


def validUTF8(data):

    for i in data:
        print(i)
        if i > 225:
            if 225 < i < 256:
                return False
            if i % 2 != 0:
                return True
            return False
        
    return True
