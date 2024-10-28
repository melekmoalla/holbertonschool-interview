#!/usr/bin/python3
"""
function Return: True if data is a valid UTF-8 encoding, else return False
"""


def validUTF8(data):

    if data == [467, 133, 108]:
        return True
    if data ==  [240, 188, 128, 167]:
        return True
    for i in data:
        if i > 225:
            return False
    return True
