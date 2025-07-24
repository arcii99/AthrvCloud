//FormAI DATASET v1.0 Category: Game of Life ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

int world[100][100] = {0}; // initialize world to 0
int temp[100][100] = {0}; // temporary world for updating cells

int count_neighbours(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // skip current cell
            int row = (x + i + 100) % 100; // handle edge cases
            int col = (y + j + 100) % 100; // handle edge cases
            if (world[row][col] == 1) count++; // count live neighbours
        }
    }
    return count;
}

void update() {
    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            int neighbours = count_neighbours(x, y);
            if (world[x][y] == 1 && neighbours < 2) {
                temp[x][y] = 0; // underpopulation
            } else if (world[x][y] == 1 && (neighbours == 2 || neighbours == 3)) {
                temp[x][y] = 1; // survives
            } else if (world[x][y] == 1 && neighbours > 3) {
                temp[x][y] = 0; // overpopulation
            } else if (world[x][y] == 0 && neighbours == 3) {
                temp[x][y] = 1; // reproduction
            }
        }
    }
    // copy updated world to original world
    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            world[x][y] = temp[x][y];
        }
    }
}

void render() {
    system("clear"); // clear console before rendering
    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            if (world[x][y] == 1) {
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    // initialize world with random live cells
    srand(time(NULL));
    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            world[x][y] = rand() % 2;
        }
    }
    while (true) {
        render();
        update();
        usleep(100000); // delay to slow down simulation
    }
    return 0;
}