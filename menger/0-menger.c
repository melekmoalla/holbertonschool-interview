#include <stdio.h>
#include <math.h>

void menger(int level)
{
    if (level < 0)
    {
        return;
    }

    int size = pow(3, level);
    printf("%d",size);

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            char draw = '#';
            int r = row, c = col;
            while (r > 0 || c > 0) {
                if (r % 3 == 1 && c % 3 == 1) {
                    draw = ' ';
                    break;
                }
                r /= 3;
                c /= 3;
            }
            putchar(draw);
        }
        putchar('\n');
    }
}