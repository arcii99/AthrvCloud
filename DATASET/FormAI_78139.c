//FormAI DATASET v1.0 Category: Game of Life ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define WIDTH 50
#define HEIGHT 25

bool grid[HEIGHT][WIDTH];
bool updatedGrid[HEIGHT][WIDTH];

void initializeGrid() {
    srand(time(NULL));
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            int r = rand() % 2;
            grid[i][j] = r == 1 ? true : false;
        }
    }
}

void printGrid() {
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            printf("%c", grid[i][j] ? 'O' : ' ');
        }
        printf("\n");
    }
}

int getNeighbors(int i, int j) {
    int count = 0;
    for(int a=-1; a<=1; a++) {
        for(int b=-1; b<=1; b++) {
            if(a == 0 && b == 0) continue;
            int row = i + a;
            int col = j + b;
            if(row < 0) row = HEIGHT - 1;
            if(row == HEIGHT) row = 0;
            if(col < 0) col = WIDTH - 1;
            if(col == WIDTH) col = 0;
            if(grid[row][col]) count++;
        }
    }
    return count;
}

void updateGrid() {
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            int neighbors = getNeighbors(i, j);
            if(grid[i][j]) {
                if(neighbors < 2 || neighbors > 3) {
                    updatedGrid[i][j] = false;
                } else {
                    updatedGrid[i][j] = true;
                }
            } else {
                if(neighbors == 3) {
                    updatedGrid[i][j] = true;
                } else {
                    updatedGrid[i][j] = false;
                }
            }
        }
    }
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            grid[i][j] = updatedGrid[i][j];
        }
    }
}

int main() {
    initializeGrid();
    while(true) {
        system("clear"); // for Linux
        //system("cls"); // for Windows
        printGrid();
        updateGrid();
        // add sleep or delay for better visualization of the grid
    }
    return 0;
}