//FormAI DATASET v1.0 Category: Fractal Generation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 50
#define MAX_ITERATIONS 50

void printFractal(int iterations[SCREEN_HEIGHT][SCREEN_WIDTH]) {
    for(int y = 0; y < SCREEN_HEIGHT; y++) {
        for(int x = 0; x < SCREEN_WIDTH; x++) {
            char c;
            switch(iterations[y][x]) {
                case 0:
                    c = ' ';
                    break;
                case 1:
                    c = '.';
                    break;
                case 2:
                    c = ':';
                    break;
                case 3:
                    c = '-';
                    break;
                case 4:
                    c = '=';
                    break;
                case 5:
                    c = '+';
                    break;
                case 6:
                    c = '*';
                    break;
                case 7:
                    c = '#';
                    break;
                case 8:
                    c = '%';
                    break;
                case 9:
                    c = '@';
                    break;
                default:
                    c = '@';
            }
            printf("%c", c);
        }
        printf("\n");
    }
}

int main() {
    int iterations[SCREEN_HEIGHT][SCREEN_WIDTH];

    for(int y = 0; y < SCREEN_HEIGHT; y++) {
        for(int x = 0; x < SCREEN_WIDTH; x++) {
            double c_re = (x - SCREEN_WIDTH / 2.0) * 4.0 / SCREEN_WIDTH;
            double c_im = (y - SCREEN_HEIGHT / 2.0) * 4.0 / SCREEN_WIDTH;
            double z_re = c_re, z_im = c_im;
            int iteration = 0;
            while(z_re * z_re + z_im * z_im < 4 && iteration < MAX_ITERATIONS) {
                double new_re = z_re * z_re - z_im * z_im;
                double new_im = 2 * z_re * z_im;
                z_re = c_re + new_re;
                z_im = c_im + new_im;
                iteration++;
            }
            iterations[y][x] = iteration;
        }
    }

    printFractal(iterations);

    return 0;
}