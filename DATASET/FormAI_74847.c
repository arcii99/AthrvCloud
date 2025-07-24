//FormAI DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 50
#define COLS 50

int board[ROWS][COLS] = {0}; // initialize the board with all dead cells

/* function to randomly initialize the board with some live cells */
void initialize_board(){
    srand(time(NULL)); // seed the random number generator
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            board[i][j] = rand() % 2; // randomly assign 0 or 1
        }
    }
}

/* function to print the current state of the board */
void print_board(){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(board[i][j] == 0){
                printf(". ");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

/* function to count the number of live neighbors around a given cell */
int count_neighbors(int row, int col){
    int count = 0;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            int r = (row + i + ROWS) % ROWS; // handle edge cases to create torus effect
            int c = (col + j + COLS) % COLS;
            if((i != 0 || j != 0) && board[r][c] == 1){ // count all live neighbors except the cell itself
                count++;
            }
        }
    }
    return count;
}

/* function to evolve the board by one time step */
void evolve_board(){
    int new_board[ROWS][COLS] = {0}; // create a new board to hold the next state
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            int neighbors = count_neighbors(i, j);
            if(board[i][j] == 1 && (neighbors == 2 || neighbors == 3)){ // cell survives
                new_board[i][j] = 1;
            } else if(board[i][j] == 0 && neighbors == 3){ // cell is born
                new_board[i][j] = 1;
            }
        }
    }
    for(int i=0; i<ROWS; i++){ // copy new board back to original board
        for(int j=0; j<COLS; j++){
            board[i][j] = new_board[i][j];
        }
    }
}

int main(){
    initialize_board();
    while(1){
        system("clear"); // clear the screen (only works on Linux/Unix)
        print_board();
        evolve_board();
        usleep(100000); // sleep for 100 milliseconds between time steps
    }
    return 0;
}