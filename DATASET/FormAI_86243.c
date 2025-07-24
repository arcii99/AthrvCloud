//FormAI DATASET v1.0 Category: Game of Life ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 60
#define HEIGHT 20
#define GENERATIONS 100

int main(void)
{
    srand(time(NULL));

    int cells[HEIGHT][WIDTH] = { 0 };

    // Initialize the cells with random values
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cells[i][j] = rand() % 2;
        }
    }

    // Perform the game of life for a set number of generations
    for (int g = 0; g < GENERATIONS; g++) {
        system("clear");
        printf("Generation: %d\n", g+1);

        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                printf("%c", cells[i][j] ? '*' : ' ');
            }
            printf("\n");
        }

        int new_cells[HEIGHT][WIDTH] = { 0 };
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                int neighbors = 0;
                for (int y = -1; y <= 1; y++) {
                    for (int x = -1; x <= 1; x++) {
                        if (y == 0 && x == 0) {
                            continue;
                        }
                        int row = i + y;
                        int col = j + x;
                        if (row < 0) {
                            row = HEIGHT - 1;
                        }
                        if (row >= HEIGHT) {
                            row = 0;
                        }
                        if (col < 0) {
                            col = WIDTH - 1;
                        }
                        if (col >= WIDTH) {
                            col = 0;
                        }
                        if (cells[row][col]) {
                            neighbors++;
                        }
                    }
                }
                if (cells[i][j]) {
                    if (neighbors < 2 || neighbors > 3) {
                        new_cells[i][j] = 0;
                    } else {
                        new_cells[i][j] = 1;
                    }
                } else {
                    if (neighbors == 3) {
                        new_cells[i][j] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                cells[i][j] = new_cells[i][j];
            }
        }
    }

    return 0;
}