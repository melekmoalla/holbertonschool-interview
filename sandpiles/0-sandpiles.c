#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * print_grid_sum - Print 3x3 grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
    int i, j;
    printf("=\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] = grid1[i][j] + grid2[i][j];
        }
    }
    
    int a = 0;
    while (1)
    {
        a = 1;
        int temp[3][3] = {{0, 0, 0},
                          {0, 0, 0},
                          {0, 0, 0}};
        int temp2[3][3] = {{0, 0, 0},
                           {0, 0, 0},
                           {0, 0, 0}};

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {

                int b = 0;
                if (grid1[i][j] > 3)
                {
                    a = 0;
                    if (j + 1 > 2 || grid1[i][j + 1] < 3)
                    {
                        if (j + 1 > 2)
                        {
                            b++;
                        }
                        else
                        {
                            b++;
                            temp[i][j + 1] = temp[i][j + 1] + 1;
                        }
                    }
                    if (j - 1 < 0 || grid1[i][j - 1] < 3)
                    {   
                        if (j - 1 < 0  )
                        {
                            b++;
                        }
                        else{
                            
                            b++;
                            temp[i][j - 1] = temp[i][j - 1] + 1;
                        }
   
                    }
                    if (i + 1 > 2 || grid1[i + 1][j] < 3)
                    {
                        if (i + 1 > 2 )
                        {
                            b++;
                        }
                        else{
                           
                            b++;
                            temp[i + 1][j] = temp[i + 1][j] + 1;
                        }
  
                    }
                    if (i - 1 < 0 || grid1[i - 1][j] < 3)
                    {   
                        if (i - 1 < 0)
                        {
                            b++;     
                        }
                        else{
                            
                            b++;
                            temp[i - 1][j] = temp[i - 1][j] + 1;
                        }

                    }
                }
                temp2[i][j] = temp2[i][j] + b;
            }
        }
        if (a ==  1)
        {
            break;
        }
        else{
            print_grid(grid1);
            printf("=\n");
        }
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                grid1[i][j] = grid1[i][j] - temp2[i][j];
            }
        }
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                grid1[i][j] = grid1[i][j] + temp[i][j];
            }
        }
        
    }
}
