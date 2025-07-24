//FormAI DATASET v1.0 Category: Game of Life ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 25
#define WIDTH 80

void initBoard(int board[][WIDTH]);
void printBoard(int board[][WIDTH]);
void updateBoard(int currBoard[][WIDTH], int nextBoard[][WIDTH]);

int main() {
    int board[HEIGHT][WIDTH];
    int nextBoard[HEIGHT][WIDTH];
    int i, j;

    //Initialize the game board
    initBoard(board);

    //Game of Life Loop
    while(1) {
        //Clear the screen
        system("clear");

        //Update the game board
        updateBoard(board, nextBoard);

        //Print the game board
        printBoard(board);

        //Copy the next board to the current board
        for(i = 0; i < HEIGHT; i++) {
            for(j = 0; j < WIDTH; j++) {
                board[i][j] = nextBoard[i][j];
            }
        }

        //Wait for 1/4 of a second before updating again
        usleep(250000);
    }

    return 0;
}

void initBoard(int board[][WIDTH]) {
    srand(time(NULL));

    int i, j;

    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            //Initialize random values between 0 and 1
            board[i][j] = rand() % 2;
        }
    }
}

void printBoard(int board[][WIDTH]) {
    int i, j;

    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            //Print '*' if the cell is alive and '.' if the cell is dead
            printf("%c", board[i][j] ? '*' : '.');
        }
        printf("\n");
    }
}

void updateBoard(int currBoard[][WIDTH], int nextBoard[][WIDTH]) {
    int i, j, k, l;
    int neigbors;

    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            //Count the number of neighboring cells that are alive
            neigbors = 0;
            for(k = i - 1; k <= i + 1; k++) {
                for(l = j - 1; l <= j + 1; l++) {
                    if(k >= 0 && k < HEIGHT && l >= 0 && l < WIDTH && !(k == i && l == j)) {
                        neigbors += currBoard[k][l];
                    }
                }
            }

            //Determine the state of the cell for the next iteration
            if(currBoard[i][j]) {
                if(neigbors < 2 || neigbors > 3) {
                    nextBoard[i][j] = 0;
                } else {
                    nextBoard[i][j] = 1;
                }
            } else {
                if(neigbors == 3) {
                    nextBoard[i][j] = 1;
                } else {
                    nextBoard[i][j] = 0;
                }
            }
        }
    }
}