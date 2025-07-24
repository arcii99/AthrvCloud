//FormAI DATASET v1.0 Category: Fractal Generation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#define WIDTH 120
#define HEIGHT 40

void printFractal(char fractal[WIDTH][HEIGHT]) {
    for(int i=0;i<HEIGHT;i++) {
        for(int j=0;j<WIDTH;j++) {
            printf("%c",fractal[j][i]);
        }
        printf("\n");
    }
}

int main() {
    char fractal[WIDTH][HEIGHT];
    double complex c,z;

    double min_x = -2.0;
    double max_x = 1.0;
    double min_y = -1.0;
    double max_y = 1.0;

    double x_step = (max_x - min_x) / WIDTH;
    double y_step = (max_y - min_y) / HEIGHT;

    for(int i=0;i<WIDTH;i++) {
        for(int j=0;j<HEIGHT;j++) {
            c = (min_x + i * x_step) + (min_y + j * y_step) * I;
            z = c;

            int n;
            for(n=0;n<20;n++) {
                if(cabs(z) > 2.0) {
                    break;
                }
                z = z*z + c;
            }

            char ch = ' ';
            switch(n) {
                case 0:
                    ch = '*';
                    break;
                case 1:
                    ch = 'o';
                    break;
                case 2:
                    ch = 'O';
                    break;
                case 3:
                    ch = '@';
                    break;
                case 4:
                    ch = '%';
                    break;
                case 5:
                    ch = '#';
                    break;
                case 6:
                    ch = '*';
                    break;
                case 7:
                    ch = '+';
                    break;
                case 8:
                    ch = '=';
                    break;
                case 9:
                    ch = '-';
                    break;
                case 10:
                    ch = ':';
                    break;
                case 11:
                    ch = '.';
                    break;
                case 12:
                    ch = '^';
                    break;
                case 13:
                    ch = '`';
                    break;
                case 14:
                    ch = ',';
                    break;
                case 15:
                    ch = '"';
                    break;
                case 16:
                    ch = '<';
                    break;
                case 17:
                    ch = '>';
                    break;
                case 18:
                    ch = '/';
                    break;
                case 19:
                    ch = '\\';
                    break;
            }

            fractal[i][j] = ch;
        }
    }

    printFractal(fractal);

    return 0;
}