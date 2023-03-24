#!/usr/bin/python3
""" Module that contains the canUnlockAll Function """


def canUnlockAll(boxes):
    """ Function that determines if all the boxes can be opened """
    keys = [0]
    for i in range(len(boxes)):
        for key in boxes[i]:
            if key != i and key not in keys and key < len(boxes):
                keys.append(key)
    return len(boxes) == len(keys)
