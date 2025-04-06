#!/usr/bin/python3
"""
Pascal's Triangle module
"""


def pascal_triangle(n):
    """
    Returns a list of lists representing Pascal's triangle of n

    Args:
        n (int): number of rows

    Returns:
        List[List[int]]: Pascal's triangle
    """
    if n <= 0:
        return []

    triangle = [[1]]  # first row

    for i in range(1, n):
        prev_row = triangle[-1]
        new_row = [1]

        for j in range(1, i):
            new_row.append(prev_row[j - 1] + prev_row[j])

        new_row.append(1)
        triangle.append(new_row)

    return triangle
