//FormAI DATASET v1.0 Category: Game of Life ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 60
#define HEIGHT 30
#define MAX_CYCLES 100

int grid[HEIGHT][WIDTH];

int count_neighbors(int y, int x) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i == 0) && (j == 0)) continue;
            int yy = y + i;
            int xx = x + j;
            if (yy < 0) yy = HEIGHT - 1;
            if (yy >= HEIGHT) yy = 0;
            if (xx < 0) xx = WIDTH - 1;
            if (xx >= WIDTH) xx = 0;
            if (grid[yy][xx]) count++;
        }
    }
    return count;
}

void clear_screen() {
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);  
}

void print_grid() {
    printf("+");
    for (int i = 0; i < WIDTH; i++) printf("-");
    printf("+\n");
    for (int i = 0; i < HEIGHT; i++) {
        printf("|");
        for (int j = 0; j < WIDTH; j++) {
            if (grid[i][j]) printf("\033[32m*\033[0m");
            else printf(" ");
        }
        printf("|\n");
    }
    printf("+");
    for (int i = 0; i < WIDTH; i++) printf("-");
    printf("+\n");
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = (rand() % 2 == 0) ? 0 : 1;
        }
    }

    int cycle = 0;
    while (cycle < MAX_CYCLES) {
        clear_screen();
        print_grid();
        usleep(10000);
        int new_grid[HEIGHT][WIDTH];
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                int neighbors = count_neighbors(i, j);
                if (grid[i][j]) {
                    if (neighbors < 2 || neighbors > 3) new_grid[i][j] = 0;
                    else new_grid[i][j] = 1;
                } else {
                    if (neighbors == 3) new_grid[i][j] = 1;
                    else new_grid[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
        cycle++;
    }
    return 0;
}