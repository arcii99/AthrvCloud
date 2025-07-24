//FormAI DATASET v1.0 Category: Game of Life ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLUMNS 80
#define GENERATIONS 100

// Function to initialize the board with random cells
void initializeBoard(int board[][COLUMNS]) {
    srand(time(0));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Function to print the board on the console
void printBoard(int board[][COLUMNS]) {
    printf("\033[2J\033[H"); // Clear the screen
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            if(board[i][j])
                printf("o");
            else
                printf(" ");
        }
        printf("\n");
    }
}

// Function to count the number of neighboring living cells
int countNeighbors(int board[][COLUMNS], int row, int col) {
    int count = 0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            int r = row + i;
            int c = col + j;
            if(r < 0) r = ROWS-1;
            if(r >= ROWS) r = 0;
            if(c < 0) c = COLUMNS-1;
            if(c >= COLUMNS) c = 0;
            if(board[r][c] && !(i==0 && j==0))
                count++;
        }
    }
    return count;
}

int main() {
    int board[ROWS][COLUMNS];
    int nextGen[ROWS][COLUMNS];
    initializeBoard(board);
    
    for(int g=1; g<=GENERATIONS; g++) {
        printBoard(board);
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLUMNS; j++) {
                int neighbors = countNeighbors(board, i, j);
                if(board[i][j])
                    nextGen[i][j] = (neighbors == 2 || neighbors == 3);
                else
                    nextGen[i][j] = (neighbors == 3);
            }
        }
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLUMNS; j++) {
                board[i][j] = nextGen[i][j];
            }
        }
    }
    
    return 0;
}