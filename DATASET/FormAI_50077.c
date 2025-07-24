//FormAI DATASET v1.0 Category: Fractal Generation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void generate_fractal(int size, int iterations, double angle);

int main()
{
    int size, iterations;
    double angle;

    printf("Please enter the size of the fractal:");
    scanf("%d", &size);

    printf("Please enter the number of iterations:");
    scanf("%d", &iterations);

    printf("Please enter the angle in degrees:");
    scanf("%lf", &angle);

    generate_fractal(size, iterations, angle);

    return 0;
}

void generate_fractal(int size, int iterations, double angle)
{
    int i, j, k, l, m, n;
    double x, y, t;
    double inc = size / pow(2, iterations);
    double delta = angle * M_PI / 180.0;

    int **matrix = (int **) malloc(size * sizeof(int *));
    for(i = 0; i < size; i++)
        matrix[i] = (int *) malloc(size * sizeof(int));

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
            matrix[i][j] = 0;
    }

    x = size / 2.0;
    y = size / 2.0;

    for(i = 0; i < iterations; i++)
    {
        for(j = 0; j < pow(2, i); j++)
        {
            for(k = 0; k < pow(2, i); k++)
            {
                t = atan2(y - k * inc - inc / 2.0, j * inc + inc / 2.0 - x);
                m = (int) floor(t / delta);
                n = j + pow(2, i) * (k + 1);

                if(n >= size)
                    continue;

                matrix[n][m] = (matrix[n][m] + 1) % 2;
            }
        }
    }

    for(i = size - 1 ; i >= 0; i--)
    {
        for(j = 0 ; j < size; j++)
            printf("%c", matrix[i][j] == 1 ? '#' : ' ');

        printf("\n");
    }

    for(i = 0; i < size; i++)
        free(matrix[i]);
    free(matrix);
}