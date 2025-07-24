//FormAI DATASET v1.0 Category: Fractal Generation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

/* Define the function to calculate fractals */
int calculateFractal(double complex c) {
    double complex z = 0;
    int iteration = 0;
    while (iteration <= 100) {
        z = z*z + c;
        if (cabs(z) >= 2) {
            return iteration;
        }
        iteration++;
    }
    return -1;
}

int main() {
    /* Initialize variables */
    double x, y, stepSize = 0.01;
    double complex c;
    int i, j;
    
    /* Loop through each pixel and calculate corresponding fractal value */
    for (y = 2.0; y >= -2.0; y -= stepSize) {
        for (x = -2.0; x <= 2.0; x += stepSize) {
            c = x + y*I;
            int fractalValue = calculateFractal(c);
            
            /* Set color based on fractal value */
            int colorCode = fractalValue % 16;
            switch (colorCode) {
                case 0:
                    printf("\033[1;30m█\033[0m");
                    break;
                case 1:
                    printf("\033[1;31m█\033[0m");
                    break;
                case 2:
                    printf("\033[1;32m█\033[0m");
                    break;
                case 3:
                    printf("\033[1;33m█\033[0m");
                    break;
                case 4:
                    printf("\033[1;34m█\033[0m");
                    break;
                case 5:
                    printf("\033[1;35m█\033[0m");
                    break;
                case 6:
                    printf("\033[1;36m█\033[0m");
                    break;
                case 7:
                    printf("\033[1;37m█\033[0m");
                    break;
                case 8:
                    printf("\033[1;90m█\033[0m");
                    break;
                case 9:
                    printf("\033[1;91m█\033[0m");
                    break;
                case 10:
                    printf("\033[1;92m█\033[0m");
                    break;
                case 11:
                    printf("\033[1;93m█\033[0m");
                    break;
                case 12:
                    printf("\033[1;94m█\033[0m");
                    break;
                case 13:
                    printf("\033[1;95m█\033[0m");
                    break;
                case 14:
                    printf("\033[1;96m█\033[0m");
                    break;
                case 15:
                    printf("\033[1;97m█\033[0m");
                    break;
            }
        }
        printf("\n");
    }
    
    return 0;
}