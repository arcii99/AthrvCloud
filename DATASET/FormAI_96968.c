//FormAI DATASET v1.0 Category: Game of Life ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 40

//Function to generate random starting state
void generateStart(int board[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = rand() % 2; //randomly assign 0 or 1
        }
    }
}

//Function to print the current state of the board
void printBoard(int board[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(board[i][j] == 0) {
                printf(".");
            } else {
                printf("O");
            }
        }
        printf("\n");
    }
}

//Function to check the number of live neighbors for a given position on the board
int checkNeighbors(int board[ROWS][COLS], int row, int col) {
    int neighbors = 0;
    for(int i=row-1; i<=row+1; i++) {
        for(int j=col-1; j<=col+1; j++) {
            if(i >= 0 && i < ROWS && j >= 0 && j < COLS) { //make sure we're not out of bounds
                if(board[i][j] == 1 && (i != row || j != col)) {
                    neighbors++;
                }
            }
        }
    }
    return neighbors;
}

//Function to update the state of the board based on the rules of the game of life
void updateBoard(int board[ROWS][COLS]) {
    int newBoard[ROWS][COLS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int neighbors = checkNeighbors(board, i, j);
            if(board[i][j] == 1 && neighbors < 2) { //dies due to underpopulation
                newBoard[i][j] = 0;
            } else if(board[i][j] == 1 && (neighbors == 2 || neighbors == 3)) { //lives on to next generation
                newBoard[i][j] = 1;
            } else if(board[i][j] == 1 && neighbors > 3) { //dies due to overpopulation
                newBoard[i][j] = 0;
            } else if(board[i][j] == 0 && neighbors == 3) { //new cell is born
                newBoard[i][j] = 1;
            } else {
                newBoard[i][j] = board[i][j]; //cell stays the same
            }
        }
    }
    //copy new board state back to original board
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS];
    srand(42); //seed rand for consistent results
    generateStart(board);
    for(int i=0; i<100; i++) { //run for 100 generations
        system("clear"); //clear console before printing new board state
        printf("Generation %d:\n", i);
        printBoard(board);
        updateBoard(board);
    }
    return 0;
}