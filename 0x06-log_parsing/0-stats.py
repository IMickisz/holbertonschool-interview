#!/usr/bin/python3
""" Script that reads stdin line by line and compute metrics """
import sys


lap = 0
total_size = 0
status = {'200': 0, '301': 0, '400': 0, '401': 0,
          '403': 0, '404': 0, '405': 0, '500': 0}


def print_stats():
    """ Prints statistics from the beginning """
    print("File size: {}".format(total_size))
    for key, value in sorted(status.items()):
        if value > 0:
            print("{}: {}".format(key, status[key]))


if __name__ == "__main__":
    try:
        for line in sys.stdin:
            try:
                lap += 1
                args = line.split()
                total_size += int(args[-1])
                code = args[-2]
                if code in status:
                    status[code] += 1
            except ValueError:
                pass
            if lap % 10 == 0:
                print_stats()
    except KeyboardInterrupt:
        print_stats()
        raise
    print_stats()
