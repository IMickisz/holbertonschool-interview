#!/usr/bin/python3
""" File containing the minOperations function """


def minOperations(n):
    """ Function that calculates the fewest number of operations needed to
    result in exactly n H characters in the file contaning only one H """
    if n <= 1:
        return 0
    for i in range(2, int((n / 2) + 1)):
        if n % i == 0:
            return minOperations(int(n / i)) + i
    return n
