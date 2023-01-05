#!/usr/bin/python3
""" Module that contains Minimun operation function """
import math


def minOperations(n):
    """ Calculates the fewest number of operations (Copy All and Paste) needed
    to result in exactly n H characters in the file """
    if type(n) is not int:
        return 0
    if n <= 1:
        return 0
    list_of_factor = []

    while n % 2 == 0:
        list_of_factor.append(2)
        n = n // 2

    for i in range(3, int(math.sqrt(n)) + 1, 2):
        while n % i == 0:
            list_of_factor.append(i)
            n = n // i

    if n > 2:
        list_of_factor.append(n)
    return sum(list_of_factor)
