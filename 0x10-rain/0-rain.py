#!/usr/bin/python3
''' Rain '''

def rain(walls):
    '''Returns a total amount of rainwater retained.'''
    total = 0

    for i in range(1, len(walls) - 1):

        firstWall = walls[i]

        for j in range(i):
            firstWall = max(firstWall, walls[j])

        secondWall = walls[i]

        for j in range(i + 1, len(walls)):
            secondWall = max(secondWall, walls[j])

        total += min(firstWall, secondWall) - walls[i]

    return total
