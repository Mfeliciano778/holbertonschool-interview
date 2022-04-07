#!/usr/bin/python3
''' The Prime Game '''


def isWinner(x, nums):
    ''' Returns the name of the player who won '''
    maria = 0
    ben = 0

    for level in range(x):
        prime_numbers = 0
        for n in range(1, nums[level] + 1):
            if n in [1, 2, 3] or n % 6 == 1 or n % 6 == 5:
                prime_numbers += 1

        if prime_numbers % 2 == 1:
            ben += 1
        else:
            maria += 1

    return None if maria == ben else "Maria" if maria > ben else "Ben"
