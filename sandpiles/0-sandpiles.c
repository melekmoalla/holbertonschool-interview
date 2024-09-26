#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

/**
 * sandpiles_sum - Print 3x3 grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Left 3x3 grid
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{int i, j, a = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{grid1[i][j] = grid1[i][j] + grid2[i][j]; } }
	while (1)
	{a = 1;
		int temp[3][3] = {0}, temp2[3][3] = {0};

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{int b = 0;
				if (grid1[i][j] > 3)
				{a = 0;
					(j + 1 > 2) ? b++ : (grid1[i][j + 1] <= 3 ? (b++, temp[i][j + 1]++) : 0);
					(j - 1 < 0) ? b++ : (grid1[i][j - 1] <= 3 ? (b++, temp[i][j - 1]++) : 0);
					(i + 1 > 2) ? b++ : (grid1[i + 1][j] <= 3 ? (b++, temp[i + 1][j]++) : 0);
					(i - 1 < 0) ? b++ : (grid1[i - 1][j] <= 3 ? (b++, temp[i - 1][j]++) : 0);
				}
				temp2[i][j] = temp2[i][j] + b; } }
		if (a == 1)
		{break; }
		else
		{printf("=\n");
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (j)
						printf(" ");
					printf("%d", grid1[i][j]); }
				printf("\n"); } }
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{grid1[i][j] = grid1[i][j] - temp2[i][j];
				grid1[i][j] = grid1[i][j] + temp[i][j]; } } } }
