//FormAI DATASET v1.0 Category: Game of Life ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50

// Function to print the current generation
void printCurrentGen(int currentGen[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(currentGen[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Function to check if a cell is alive or dead in the next generation
int getNextState(int currentGen[ROWS][COLS], int r, int c) {
    int neighbors = 0;
    int rowStart = (r == 0) ? 0 : r-1;
    int rowEnd = (r == ROWS-1) ? ROWS-1 : r+1;
    int colStart = (c == 0) ? 0 : c-1;
    int colEnd = (c == COLS-1) ? COLS-1 : c+1;
    
    for(int i=rowStart; i<=rowEnd; i++) {
        for(int j=colStart; j<=colEnd; j++) {
            if(currentGen[i][j] == 1 && !(i == r && j == c)) {
                neighbors++;
            }
        }
    }
    
    // Rules for determining the next state of the cell
    if(currentGen[r][c] == 1 && neighbors < 2) {
        return 0; // Underpopulation
    } else if(currentGen[r][c] == 1 && (neighbors == 2 || neighbors == 3)) {
        return 1; // Lives on to next generation
    } else if(currentGen[r][c] == 1 && neighbors > 3) {
        return 0; // Overcrowding
    } else if(currentGen[r][c] == 0 && neighbors == 3) {
        return 1; // Reproduction
    } else {
        return currentGen[r][c];
    }
}

// Function to generate the next generation
void generateNextGen(int currentGen[ROWS][COLS], int nextGen[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            nextGen[i][j] = getNextState(currentGen, i, j);
        }
    }
}

int main() {
    int currentGen[ROWS][COLS];
    int nextGen[ROWS][COLS];
    srand(time(NULL)); // Seed the random number generator
    
    // Initialize the current generation randomly
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            currentGen[i][j] = rand() % 2;
        }
    }
    
    printf("=== Game of Life ===\n");
    printf("Press Ctrl+C to exit.\n");
    printf("===================\n\n");
    
    while(1) {
        system("clear"); // Clear the screen
        printCurrentGen(currentGen); // Print the current generation
        generateNextGen(currentGen, nextGen); // Generate the next generation
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                currentGen[i][j] = nextGen[i][j];
            }
        }
        usleep(250000); // Sleep for a quarter of a second before generating next generation
    }
    
    return 0;
}