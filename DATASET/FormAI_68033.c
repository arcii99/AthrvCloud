//FormAI DATASET v1.0 Category: Game of Life ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 50
#define COLS 100

int currGrid[ROWS][COLS] = {0}, nextGrid[ROWS][COLS] = {0};

void initGrid() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            currGrid[i][j] = rand() % 2; // randomly assigning live and dead cells
        }
    }
}

void displayGrid() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(currGrid[i][j] == 1) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
}

int getLiveNeighbours(int i, int j) {
    int count = 0;
    for(int k=i-1; k<=i+1; k++) {
        for(int l=j-1; l<=j+1; l++) {
            if((k>=0 && k<ROWS) && (l>=0 && l<COLS) && !(k == i && l == j)) {
                if(currGrid[k][l] == 1) count++;
            }
        }
    }
    return count;
}

void getNextGeneration() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int liveNeighbours = getLiveNeighbours(i, j);
            if(currGrid[i][j] == 1 && liveNeighbours < 2) nextGrid[i][j] = 0; // underpopulation
            else if(currGrid[i][j] == 1 && (liveNeighbours == 2 || liveNeighbours == 3)) nextGrid[i][j] = 1; // optimal population
            else if(currGrid[i][j] == 1 && liveNeighbours > 3) nextGrid[i][j] = 0; // overpopulation
            else if(currGrid[i][j] == 0 && liveNeighbours == 3) nextGrid[i][j] = 1; // reproduction
        }
    }

    // updating the current grid
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            currGrid[i][j] = nextGrid[i][j];
        }
    }
}

int main() {
    system("clear");
    initGrid();
    while(1) {
        printf("\033[H\033[J"); // clear the console for clean display
        displayGrid();
        getNextGeneration();
        usleep(300000); // sleep for 300ms
    }
    return 0;
}