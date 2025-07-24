//FormAI DATASET v1.0 Category: Game of Life ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GRID_SIZE 20

bool current[GRID_SIZE][GRID_SIZE];
bool next[GRID_SIZE][GRID_SIZE];

void initialize() {
    srand(time(NULL));
    for (int i=0; i<GRID_SIZE; i++) {
        for (int j=0; j<GRID_SIZE; j++) {
            current[i][j] = rand() % 2;
        }
    }
}

int countNeighbors(int row, int col) {
    int count = 0;
    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++) {
            if (i==0 && j==0) continue;
            int r = (row + i + GRID_SIZE) % GRID_SIZE;
            int c = (col + j + GRID_SIZE) % GRID_SIZE;
            if (current[r][c]) count++;
        }
    }
    return count;
}

void update() {
    for (int i=0; i<GRID_SIZE; i++) {
        for (int j=0; j<GRID_SIZE; j++) {
            int neighbors = countNeighbors(i, j);
            if (current[i][j] == 0 && neighbors == 3) next[i][j] = 1;
            else if (current[i][j] == 1 && (neighbors < 2 || neighbors > 3)) next[i][j] = 0;
            else next[i][j] = current[i][j];
        }
    }
    for (int i=0; i<GRID_SIZE; i++) {
        for (int j=0; j<GRID_SIZE; j++) {
            current[i][j] = next[i][j];
        }
    }
}

void display() {
    for (int i=0; i<GRID_SIZE; i++) {
        for (int j=0; j<GRID_SIZE; j++) {
            if (current[i][j]) printf("X ");
            else printf(". ");
        }
        printf("\n");
    }
}

int main() {
    initialize();
    for (int i=0; i<10; i++) {
        display();
        printf("\n");
        update();
    }
    return 0;
}