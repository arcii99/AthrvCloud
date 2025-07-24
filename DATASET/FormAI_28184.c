//FormAI DATASET v1.0 Category: Game of Life ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 30

char grid[WIDTH][HEIGHT];
char old_grid[WIDTH][HEIGHT];

void init_grid(void)
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (rand() % 2 == 0) {
                grid[i][j] = 'X';
            } else {
                grid[i][j] = ' ';
            }
            putchar(grid[i][j]);
        }
    }
}

void update_grid(void)
{
    int i, j, k, l, n;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            n = 0;
            for (k = i - 1; k <= i + 1; k++) {
                for (l = j - 1; l <= j + 1; l++) {
                    if (k < 0 || k >= WIDTH || l < 0 || l >= HEIGHT) {
                        continue;
                    }
                    if (grid[k][l] == 'X') {
                        n += 1;
                    }
                }
            }
            if (grid[i][j] == 'X') {
                n -= 1;
                if (n == 2 || n == 3) {
                    old_grid[i][j] = 'X';
                } else {
                    old_grid[i][j] = ' ';
                }
            } else {
                if (n == 3) {
                    old_grid[i][j] = 'X';
                } else {
                    old_grid[i][j] = ' ';
                }
            }
        }
    }
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j] = old_grid[i][j];
        }
    }
}

void print_grid(void)
{
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            putchar(grid[i][j]);
        }
    }
}

int main(void)
{
    init_grid();
    while (1) {
        update_grid();
        sleep(1);
        printf("\033[2J");
        printf("\033[%d;%dH", 1, 1);
        print_grid();
    }
    return 0;
}