#!/usr/bin/python3

"""method that determines if all the boxes can be opened.

Args:
    boxes (a list of lists): contain keys to the other boxes

Returns:
    boolean: True if all boxes can be opened, else return False
"""


def canUnlockAll(boxes):
    """ Method that determines if all boxes can be opened """

    for i in range(1, len(boxes)):
        list_lock = []
        for b in boxes[:1]:
            list_lock.extend(b)
            if i in  list_lock:
                return False
    return True