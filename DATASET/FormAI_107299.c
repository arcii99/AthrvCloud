//FormAI DATASET v1.0 Category: Game of Life ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// structure for holding a cell's state
typedef struct {
    int alive;
    int nextAlive;
} Cell;

// function to randomly initialize the board
void initBoard(Cell board[][20]) {
    srand(time(NULL)); // seed for randomization
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            board[i][j].alive = rand() % 2; // randomly assign alive or dead state
        }
    }
}

// function to print out the current state of the board
void printBoard(Cell board[][20]) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (board[i][j].alive)
                printf(" X ");
            else
                printf(" - ");
        }
        printf("\n");
    }
}

// function to update the board according to the rules of the game of life
void updateBoard(Cell board[][20]) {
    // loop through each cell
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            int aliveNeighbors = 0;
            // check how many neighbors are alive
            for (int ii = i - 1; ii <= i + 1; ii++) {
                for (int jj = j - 1; jj <= j + 1; jj++) {
                    if (ii < 0 || jj < 0 || ii >= 20 || jj >= 20)
                        continue; // skip if index is out of range
                    if (ii == i && jj == j)
                        continue; // skip if cell is self
                    aliveNeighbors += board[ii][jj].alive;
                }
            }
            // apply the rules of the game of life
            if (board[i][j].alive) {
                if (aliveNeighbors < 2 || aliveNeighbors > 3)
                    board[i][j].nextAlive = 0; // die from underpopulation or overpopulation
                else
                    board[i][j].nextAlive = 1; // stay alive
            }
            else {
                if (aliveNeighbors == 3)
                    board[i][j].nextAlive = 1; // revive from reproduction
                else
                    board[i][j].nextAlive = 0; // stay dead
            }
        }
    }
    // copy the next state of each cell over to the current state
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            board[i][j].alive = board[i][j].nextAlive;
        }
    }
}

int main() {
    Cell board[20][20]; // initialize board of cells
    initBoard(board); // randomly initialize board
    while (1) {
        system("clear"); // clear console
        printBoard(board); // print current state of board
        updateBoard(board); // update board according to rules
    }
    return 0;
}