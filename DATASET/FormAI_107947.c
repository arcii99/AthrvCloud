//FormAI DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int board[ROWS][COLS] = {0}; //initialize board to all 0's

void initialize_board() { //randomly initialize the board
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

int count_neighbors(int row, int col) { //count the number of neighboring cells that are alive
    int count = 0;
    //check all neighboring cells
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            //make sure we don't go out of bounds
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS) {
                //don't count the current cell
                if (i != row || j != col) {
                    count += board[i][j];
                }
            }
        }
    }
    return count;
}

void update_board() { //update the board based on the rules of the game
    int new_board[ROWS][COLS] = {0}; //initialize new board to all 0's
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(i, j);
            if (board[i][j] == 1) { //if the cell is alive
                if (neighbors < 2 || neighbors > 3) { //if it has less than 2 or more than 3 neighbors, it dies
                    new_board[i][j] = 0;
                } else { //otherwise, it stays alive
                    new_board[i][j] = 1;
                }
            } else { //if the cell is dead
                if (neighbors == 3) { //if it has exactly 3 neighbors, it comes to life
                    new_board[i][j] = 1;
                } else { //otherwise, it stays dead
                    new_board[i][j] = 0;
                }
            }
        }
    }
    //copy the new board back to the old board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

void print_board() { //print the board to the console
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    initialize_board();
    while (1) {
        system("clear"); //clear the console
        print_board();
        update_board();
        usleep(50000); //wait for 0.05 seconds before updating again
    }
    return 0;
}