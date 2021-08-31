#!/usr/bin/python3
from time import sleep
import fileinput
import sys

if __name__ == '__main__':
    try:
        # set a size variable to get total size
        size = 0
        # list of possible codes
        code = [200, 301, 400, 401, 403, 404, 405, 500]
        # dict of codes and how many times each were called
        coded = {200: 0,
                 301: 0,
                 400: 0,
                 401: 0,
                 403: 0,
                 404: 0,
                 405: 0,
                 500: 0}
        # go through the stdin and get the number of line and the line
        for place, line in enumerate(sys.stdin):
            # get log values
            try:
                # get line and split
                log = line.split()

                # add size to the total
                size += int(log[-1])

                # get status code
                status_code = int(log[-2])

                # add 1 for the code if it exists
                coded[status_code] += 1
            except Exception:
                continue

            # every 10th line
            if place % 10 == 0:
                # print size and the status codes
                print("Full size: {}".format(size))
                for num in range(len(code)):
                    # checks for occurence of status codes
                    if coded[int(code[num])] > 0:
                        print(str(code[num]) + ": " +
                              str(coded[int(code[num])]))
    except KeyboardInterrupt:
        # if there is a keyboard interrupt
        # print the last iteration of the logs
        print("Full size: {}".format(size))
        for num in range(len(code)):
            # checks for occurence of status codes
            if coded[int(code[num])] > 0:
                print(str(code[num]) + ": " + str(coded[int(code[num])]))
