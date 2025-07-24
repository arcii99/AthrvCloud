//FormAI DATASET v1.0 Category: Game of Life ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int board[ROWS][COLS]; // board for the game of life

// initializes the board with randomly generated values
void init_board() {
    srand(time(NULL)); // set seed for randomization
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = rand() % 2; // randomly assign either 0 or 1
        }
    }
}

// prints the board to the console
void print_board() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(board[i][j] == 1) {
                printf("# "); // alive cell represented by "#"
            } else {
                printf(". "); // dead cell represented by "."
            }
        }
        printf("\n");
    }
}

// returns the number of live neighbors for a given cell
int count_neighbors(int row, int col) {
    int count = 0;
    for(int i=row-1; i<=row+1; i++) {
        for(int j=col-1; j<=col+1; j++) {
            if(i != row || j != col) { // exclude the current cell
                if(i >= 0 && i < ROWS && j >= 0 && j < COLS) { // make sure cell is in bounds
                    if(board[i][j] == 1) {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

// updates the board for the next generation of cells
void update_board() {
    int new_board[ROWS][COLS]; // new board for the next generation
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int neighbors = count_neighbors(i, j);
            if(board[i][j] == 1) { // current cell is alive
                if(neighbors == 2 || neighbors == 3) { // cell stays alive if it has 2 or 3 live neighbors
                    new_board[i][j] = 1;
                } else {
                    new_board[i][j] = 0; // cell dies if it has less than 2 or more than 3 live neighbors
                }
            } else { // current cell is dead
                if(neighbors == 3) { // cell becomes alive if it has exactly 3 live neighbors
                    new_board[i][j] = 1;
                } else {
                    new_board[i][j] = 0; // cell remains dead otherwise
                }
            }
        }
    }
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = new_board[i][j]; // replace old board with new board for the next generation
        }
    }
}

int main() {
    init_board();
    for(int i=0; i<10; i++) { // run game for 10 generations
        print_board();
        printf("\n");
        update_board();
        printf("Press enter to continue...");
        getchar(); // wait for user to press enter key before updating board again
    }
    return 0;
}