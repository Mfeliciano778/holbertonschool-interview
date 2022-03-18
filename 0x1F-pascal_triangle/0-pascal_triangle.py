#!/usr/bin/python3
""" pascal's triangle """


def pascal_triangle(n):
    """ makes a pascal triangle """
    if n <= 0:
        return []

    if n == 1:
        return [[1]]

    if n == 2:
        return [[1], [1, 1]]

    initialList = [1 for i in range(0, n)]
    newList = pascal_triangle(n-1)
    newList.append(initialList)
    for i in range(1, n-1):
        initialList[i] = newList[n - 2][i] + newList[n-2][i - 1]
    return newList
