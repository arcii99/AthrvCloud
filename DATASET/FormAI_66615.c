//FormAI DATASET v1.0 Category: Fractal Generation ; Style: curious
#include <stdio.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 40
#define ITERS 255

void display(char array[HEIGHT][WIDTH]) {
    for(int i = 0; i < HEIGHT; ++i) {
        for(int j = 0; j < WIDTH; ++j) {
            printf("%c", array[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char grid[HEIGHT][WIDTH];
    double cx, cy, zx, zy, zxNext, zyNext, dist;
    int i, j, k, iter;
    for(i = 0; i < HEIGHT; ++i) {
        for(j = 0; j < WIDTH; ++j) {
            cx = ((double) j - WIDTH / 2) / (WIDTH / 4);
            cy = ((double) i - HEIGHT / 2) / (HEIGHT / 4);
            zx = 0, zy = 0;
            dist = 0;
            for(k = 0; k < ITERS; ++k) {
                zxNext = pow(zx, 2) - pow(zy, 2) + cx;
                zyNext = 2 * zx * zy + cy;
                dist = pow(zxNext, 2) + pow(zyNext, 2);
                if(dist > 4) {
                    break;
                }
                zx = zxNext;
                zy = zyNext;
            }
            iter = dist < 4 ? k : ITERS;
            switch (iter % 16) {
                case 0:
                    grid[i][j] = ' ';
                    break;
                case 1:
                    grid[i][j] = '.';
                    break;
                case 2:
                    grid[i][j] = ':';
                    break;
                case 3:
                    grid[i][j] = 'o';
                    break;
                case 4:
                    grid[i][j] = 'c';
                    break;
                case 5:
                    grid[i][j] = '*';
                    break;
                case 6:
                    grid[i][j] = 'x';
                    break;
                case 7:
                    grid[i][j] = 'X';
                    break;
                case 8:
                    grid[i][j] = '#';
                    break;
                case 9:
                    grid[i][j] = 'H';
                    break;
                case 10:
                    grid[i][j] = 'M';
                    break;
                case 11:
                    grid[i][j] = 'W';
                    break;
                case 12:
                    grid[i][j] = 'N';
                    break;
                case 13:
                    grid[i][j] = '@';
                    break;
                case 14:
                    grid[i][j] = '%';
                    break;
                case 15:
                    grid[i][j] = '&';
                    break;
            }
        }
    }
    display(grid);
    return 0;
}