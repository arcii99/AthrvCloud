//FormAI DATASET v1.0 Category: Fractal Generation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_ITERATIONS 1000

int main()
{
    srand(time(0));
    char display[HEIGHT][WIDTH];
    double real_min = -2.0;
    double real_max = 1.0;
    double imag_min = -1.0;
    double imag_max = 1.0;
    double real_range = real_max - real_min;
    double imag_range = imag_max - imag_min;

    // Generate fractal
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {   
            double c_real = ((double)x / WIDTH) * real_range + real_min;
            double c_imag = ((double)y / HEIGHT) * imag_range + imag_min;
            double z_real = c_real;
            double z_imag = c_imag;
            bool in_set = true;

            for (int i = 1; i <= MAX_ITERATIONS; i++)
            {
                double z_real_sq = z_real * z_real;
                double z_imag_sq = z_imag * z_imag;

                if (z_real_sq + z_imag_sq > 4.0)
                {
                    in_set = false;
                    break;
                }

                double new_z_real = z_real_sq - z_imag_sq + c_real;
                double new_z_imag = 2.0 * z_real * z_imag + c_imag;
                z_real = new_z_real;
                z_imag = new_z_imag;
            }

            if (in_set) {
                display[y][x] = '.';
            } else {
                int r = rand() % 6;
                switch (r) {
                    case 0:
                    case 1:
                        display[y][x] = '*';
                        break;
                    case 2:
                    case 3:
                        display[y][x] = '+';
                        break;
                    case 4:
                        display[y][x] = 'x';
                        break;
                    case 5:
                        display[y][x] = '-';
                        break;
                }
            }
        }
    }

    // Display fractal
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            printf("%c", display[y][x]);
        }
        printf("\n");
    }

    return 0;
}