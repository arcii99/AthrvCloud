//FormAI DATASET v1.0 Category: Game of Life ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 24
#define COLS 80

void printGrid(char grid[ROWS][COLS]) {
    system("clear");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            putchar(grid[i][j]);
        }
    }
}

void updateGrid(char grid[ROWS][COLS]) {
    char newGrid[ROWS][COLS];
    for(int i = 1; i < ROWS - 1; i++) {
        for(int j = 1; j < COLS - 1; j++) {
            int liveNeighbours = 0;
            for(int x = -1; x <= 1; x++) {
                for(int y = -1; y <= 1; y++) {
                    liveNeighbours += grid[i+x][j+y] == 'O' ? 1 : 0;
                }
            }
            liveNeighbours -= grid[i][j] == 'O' ? 1 : 0;
            if(grid[i][j] == 'O' && (liveNeighbours < 2 || liveNeighbours > 3)) {
                newGrid[i][j] = ' ';
            } else if(grid[i][j] == ' ' && liveNeighbours == 3) {
                newGrid[i][j] = 'O';
            } else {
                newGrid[i][j] = grid[i][j];
            }
        }
    }

    for(int i = 1; i < ROWS - 1; i++) {
        for(int j = 1; j < COLS - 1; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main(void) {
    char grid[ROWS][COLS] = {
        "                                                                                ",
        "                                                                                ",
        "                                                                                ",
        "                                                                                ",
        "                                                                                ",
        "                                                                                ",
        "                                                                                ",
        "                                                                                ",
        "                                                                                ",
        "                                                                                ",
        "                                                                                ",
        "                                                                                ",
        "                                                                                ",
        "                                                                                ",
        "                                                                                ",
        "                                                                                ",
        "                                                                                ",
        "                                                                                ",
        "                                                                                ",
        "                                                                                ",
        "                                                                                ",
        "                                                                                ",
        "                                                                                ",
        "                                                                                "
    };

    //glider
    grid[10][10] = 'O';
    grid[11][11] = 'O';
    grid[12][9] = 'O';
    grid[12][10] = 'O';
    grid[12][11] = 'O';

    while(1) {
        printGrid(grid);
        updateGrid(grid);
        usleep(100000);
    }

    return 0;
}