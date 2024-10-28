#!/usr/bin/python3
"""
function Return: True if data is a valid UTF-8 encoding, else return False
"""


def validUTF8(data):

    for i in data:
        if i > 225:
            return False
    return True
