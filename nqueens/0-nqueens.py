#!/usr/bin/python3
import sys


def nqueens(n):
    """Solve the N Queens problem iteratively."""
    queens = [-1] * n
    solutions = []
    row = 0

    while row >= 0:

        queens[row] += 1
        if queens[row] >= n:
            queens[row] = -1
            row -= 1
            continue
        print(queens[row], row)
        safe = True
        for r in range(row):
            if queens[r] == queens[row] or \
               abs(queens[r] - queens[row]) == abs(r - row):
                safe = False
                break

        if safe:
            if row == n - 1:
                solutions.append([[i, queens[i]] for i in range(n)])
            else:
                row += 1

    return solutions


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = nqueens(n)
    for solution in solutions:
        print(solution)
