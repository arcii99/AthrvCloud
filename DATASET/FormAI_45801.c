//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 50
#define HEIGHT 50
#define MAX_ITER 200
#define X_MIN -2.0
#define X_MAX 1.0
#define Y_MIN -1.5
#define Y_MAX 1.5

int main(void)
{
    int i, j, k, iter, num_iter;
    double x, y, xtemp, ytemp, x0, y0;
    char image[HEIGHT][WIDTH];

    for(i = 0; i < HEIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
        {
            x0 = X_MIN + j * ((X_MAX - X_MIN) / WIDTH);
            y0 = Y_MIN + i * ((Y_MAX - Y_MIN) / HEIGHT);

            x = y = 0;
            num_iter = 0;

            while(x * x + y * y <= 4 && num_iter < MAX_ITER)
            {
                xtemp = x * x - y * y + x0;
                ytemp = 2 * x * y + y0;
                x = xtemp;
                y = ytemp;
                num_iter++;
            }

            if(num_iter == MAX_ITER)
                image[i][j] = ' ';
            else
            {
                k = num_iter % 10;
                switch(k)
                {
                    case 0:
                        image[i][j] = '.';
                        break;
                    case 1:
                        image[i][j] = '-';
                        break;
                    case 2:
                        image[i][j] = '+';
                        break;
                    case 3:
                        image[i][j] = '*';
                        break;
                    case 4:
                        image[i][j] = '^';
                        break;
                    case 5:
                        image[i][j] = '&';
                        break;
                    case 6:
                        image[i][j] = '$';
                        break;
                    case 7:
                        image[i][j] = '#';
                        break;
                    case 8:
                        image[i][j] = '@';
                        break;
                    case 9:
                        image[i][j] = '%';
                        break;
                }
            }
        }
    }

    for(i = 0; i < HEIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
            putchar(image[i][j]);

        putchar('\n');
    }

    return 0;
}