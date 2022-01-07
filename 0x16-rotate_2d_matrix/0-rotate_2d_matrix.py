#!/usr/bin/python3
""" rotate 2D matrix """


def rotate_2d_matrix(matrix):
    """ rotate matrix 90 degress clockwise """
    cpy = []
    n = len(matrix)
    for a in range(n):
        cpy.append(matrix[a].copy())
    for i in range(n):
        for j in range(n):
            matrix[i][j] = cpy[n - 1 - j][i]
