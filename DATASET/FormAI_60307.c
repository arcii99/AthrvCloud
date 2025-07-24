//FormAI DATASET v1.0 Category: Game of Life ; Style: automated
#include <stdio.h>
#include <stdlib.h>

//global variables
#define SIZE 20
#define LIVE 'X'
#define DEAD ' '
char board[SIZE][SIZE];  //to hold the game board

//function to initialize the board with random dead/alive cells
void initializeBoard() {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (rand() % 2 == 0) {
                board[i][j] = DEAD;
            } else {
                board[i][j] = LIVE;
            }
        }
    }
}

//function to print the current state of the board
void printBoard() {
    int i, j;

    printf("\n");

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

//function to count the number of living neighbors for a given cell
int countNeighbors(int row, int col) {
    int count = 0;
    int i, j;

    for (i = row - 1; i <= row + 1; i++) {
        for (j = col - 1; j <= col + 1; j++) {
            //skip if cell is out of bounds
            if (i < 0 || j < 0 || i >= SIZE || j >= SIZE) {
                continue;
            }

            //skip if it's the current cell being checked
            if (i == row && j == col) {
                continue;
            }

            //increment count if neighbor is alive
            if (board[i][j] == LIVE) {
                count++;
            }
        }
    }

    return count;
}

//function to apply the rules of the Game of Life to the board
void applyRules() {
    int i, j, neighbors;
    char newBoard[SIZE][SIZE];

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            neighbors = countNeighbors(i, j);

            //apply rules to the current cell
            if (board[i][j] == LIVE) {
                if (neighbors < 2 || neighbors > 3) {
                    newBoard[i][j] = DEAD;
                } else {
                    newBoard[i][j] = LIVE;
                }
            } else {
                if (neighbors == 3) {
                    newBoard[i][j] = LIVE;
                } else {
                    newBoard[i][j] = DEAD;
                }
            }
        }
    }

    //copy new board back to original board
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

//main function to run the Game of Life program
int main() {
    int i;

    //initialize board with random dead/alive cells
    initializeBoard();

    //print initial state of board
    printf("Initial state of board:");
    printBoard();

    //run game loop for 20 iterations
    for (i = 0; i < 20; i++) {
        applyRules();

        //print current state of board
        printf("State of board after iteration %d:", i + 1);
        printBoard();
    }

    return 0;
}