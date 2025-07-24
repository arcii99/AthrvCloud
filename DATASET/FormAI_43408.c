//FormAI DATASET v1.0 Category: Game of Life ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void print_board(int board[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(board[i][j] == 1)
                printf("O ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int count_live_neighbors(int board[ROWS][COLS], int row, int col) {
    int count = 0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            int neighbor_row = row+i;
            int neighbor_col = col+j;
            if((i != 0 || j != 0) &&
                neighbor_row >= 0 && neighbor_col >= 0 &&
                neighbor_row < ROWS && neighbor_col < COLS &&
                board[neighbor_row][neighbor_col] == 1) {
                count++;
            }
        }
    }
    return count;
}

void update_board(int board[ROWS][COLS]) {
    // create a new board to hold updated values
    int new_board[ROWS][COLS];

    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int count = count_live_neighbors(board, i, j);

            if(board[i][j] == 1) {
                // cell is alive
                if(count < 2) {
                    // cell dies due to underpopulation
                    new_board[i][j] = 0;
                } else if(count > 3) {
                    // cell dies due to overcrowding
                    new_board[i][j] = 0;
                } else {
                    // cell survives to next generation
                    new_board[i][j] = 1;
                }
            } else {
                // cell is dead
                if(count == 3) {
                    // cell becomes alive due to reproduction
                    new_board[i][j] = 1;
                } else {
                    // cell remains dead
                    new_board[i][j] = 0;
                }
            }
        }
    }

    // copy new_board to board
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    // initialize random seed
    srand(time(NULL));

    // create the board and fill it randomly
    int board[ROWS][COLS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(rand() % 2 == 0)
                board[i][j] = 0;
            else
                board[i][j] = 1;
        }
    }

    // run the game
    for(int generation=0; generation<50; generation++) {
        printf("Generation %d\n", generation+1);
        print_board(board);
        update_board(board);
        printf("\n");
    }

    return 0;
}