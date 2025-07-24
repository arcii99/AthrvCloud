//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define MAX_ITER 65535
#define WIDTH 80
#define HEIGHT 24

int main()
{
    double x_min = -2;
    double x_max = 2;
    double y_min = -1.2;
    double y_max = 1.2;
    double x_range = x_max - x_min;
    double y_range = y_max - y_min;
    double x_step = x_range / WIDTH;
    double y_step = y_range / HEIGHT;
    
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            double complex z = 0;
            double complex c = (x_min + j * x_step) + (y_max - i * y_step) * I;
            int n = 0;
            while(cabs(z) <= 2 && n < MAX_ITER) {
                z = z * z + c;
                n++;
            }

            char pixel;
            if(n == MAX_ITER) {
                pixel = ' ';
            } else {
                pixel = ".,-~:;=!*#$@"[n % 16];
            }
            putchar(pixel);
        }
        putchar('\n');
    }
    return 0;
}