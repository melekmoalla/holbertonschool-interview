#!/usr/bin/python3
def island_perimeter(grid):
    """
    Calculate the perimeter of an island in a grid.

    :param grid: List of list of integers (0 represents water, 1 represents land)
    :return: Integer representing the island's perimeter
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0]) if rows else 0

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 1:
                # Start with 4 sides
                perimeter += 4
                # Subtract shared edges
                if r > 0 and grid[r - 1][c] == 1:  # Check top cell
                    perimeter -= 2
                if c > 0 and grid[r][c - 1] == 1:  # Check left cell
                    perimeter -= 2
    return perimeter


