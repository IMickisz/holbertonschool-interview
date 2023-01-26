#!/usr/bin/python3
""" Script that reads stdin line by line and compute metrics """
import sys


lap = 0
total_size = 0
STATUS = {'200': 0, '301': 0, '400': 0, '401': 0,
          '403': 0, '404': 0, '405': 0, '500': 0}

def print_stats():
    """ Prints statistics from the beginning """
    print("File size: {}".format(total_size))
    for key in sorted(STATUS.keys()):
        if STATUS[key] > 0:
            print("{}: {}".format(key, STATUS[key]))


if __name__ == "__main__":
    try:
        for line in sys.stdin:
            lap += 1
            try:
                args = line.split()
                total_size += int(args[-1])
                status = int(args[-2])
                if status in STATUS.keys():
                    STATUS[status] += 1
            except ValueError:
                pass
            if lap % 10 == 0:
                print_stats()
    except KeyboardInterrupt:
        print_stats()
        raise
    print_stats()
