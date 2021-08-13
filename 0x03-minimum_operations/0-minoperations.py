#!/usr/bin/python3
'''Finding the min amount of operations to copy/paste a string to a length'''


def minOperations(n):
    '''Returns a number if n is achievable, else 0'''
    if n <= 1:
        return 0
    else:
        for i in range(2, n + 1):
            if n % i == 0:
                return 1 + (i - 1) + minOperations(int(n / i))
        return (n + 1)
