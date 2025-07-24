//FormAI DATASET v1.0 Category: Game of Life ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int board[ROWS][COLS];

/* function to print the 2D board */
void print_board() {
    printf("\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* function to initialize the board randomly */
void init_board() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = rand() % 2; // fill cell with either 0 or 1
        }
    }
}

/* function to calculate the next generation of cells */
void next_gen() {
    int temp_board[ROWS][COLS];
    
    // copy board to temp_board
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            temp_board[i][j] = board[i][j];
        }
    }
    
    // calculate the next generation of cells
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            // get the number of live neighbors
            int live_neighbors = 0;
            for(int k=-1; k<=1; k++) {
                for(int l=-1; l<=1; l++) {
                    if(k == 0 && l == 0) {
                        continue;
                    }
                    int row = (i+k+ROWS) % ROWS;
                    int col = (j+l+COLS) % COLS;
                    live_neighbors += board[row][col];
                }
            }
            // apply the rules of the game
            if(board[i][j] == 1) { // cell is alive
                if(live_neighbors < 2) {
                    temp_board[i][j] = 0; // dies due to underpopulation
                } else if(live_neighbors > 3) {
                    temp_board[i][j] = 0; // dies due to overpopulation
                } else {
                    temp_board[i][j] = 1; // survives to next generation
                }
            } else { // cell is dead
                if(live_neighbors == 3) {
                    temp_board[i][j] = 1; // becomes alive due to reproduction
                }
            }
        }
    }
    
    // copy temp_board back to board
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = temp_board[i][j];
        }
    }
}

int main() {
    srand(time(NULL)); // set seed for random number generator
    init_board(); // initialize the board randomly
    
    for(int i=0; i<10; i++) { // run for 10 generations
        print_board(); // print the board
        next_gen(); // calculate the next generation
        usleep(100000); // sleep for 100ms
    }
    
    return 0;
}