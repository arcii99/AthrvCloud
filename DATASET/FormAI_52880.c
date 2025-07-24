//FormAI DATASET v1.0 Category: Fractal Generation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i, j, k;
    int width = 120, height = 30;
    char image[height][width];
    double cx = -0.743643887037151, cy = 0.13182590420533;
    double zoom = 1, moveX = 0, moveY = 0;
    double minLimit = -2.0, maxLimit = 2.0;

    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            double zx = 1.5 * (j - (width / 2)) / (0.5 * zoom * width) + moveX;
            double zy = (i - (height / 2)) / (0.5 * zoom * height) + moveY;
            double tx = zx, ty = zy;
            int color = 0;

            for(k = 0; k < 255; k++)
            {
                double x = tx * tx - ty * ty + cx;
                double y = 2 * tx * ty + cy;
                tx = x, ty = y;

                if((tx * tx + ty * ty) > 4)
                {
                    color = k;
                    break;
                }
            }

            if(color == 0)
            {
                image[i][j] = ' ';
            }
            else 
            {
                int shading = floor(log(color) / log(255) * 9);
                char shade[8] = {' ', '.', ':', 'o', '&', '8', '#', '@', '@'};
                image[i][j] = shade[shading];
            }
        }
    }

    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            printf("%c", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}