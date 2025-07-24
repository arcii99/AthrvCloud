//FormAI DATASET v1.0 Category: Game of Life ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 50
#define COLS 50

// function to initialize the board with random values
void init_board(int board[ROWS][COLS]) {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// function to print the board on the screen
void print_board(int board[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(board[i][j] == 1) {
                printf("+ ");
            }
            else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

// function to count the number of living neighbors for each cell
int count_neighbors(int board[ROWS][COLS], int row, int col) {
    int count = 0;
    // check the neighboring cells
    for(int i=row-1; i<=row+1; i++) {
        for(int j=col-1; j<=col+1; j++) {
            if(i == row && j == col) {
                continue;
            }
            if(i < 0) {
                i += ROWS;
            }
            else if(i >= ROWS) {
                i -= ROWS;
            }
            if(j < 0) {
                j += COLS;
            }
            else if(j >= COLS) {
                j -= COLS;
            }
            if(board[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

// function to update the board based on the number of living neighbors for each cell
void update_board(int board[ROWS][COLS]) {
    int new_board[ROWS][COLS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int neighbors = count_neighbors(board, i, j);
            if(board[i][j] == 1) {
                if(neighbors < 2 || neighbors > 3) {
                    new_board[i][j] = 0;
                }
                else {
                    new_board[i][j] = 1;
                }
            }
            else {
                if(neighbors == 3) {
                    new_board[i][j] = 1;
                }
                else {
                    new_board[i][j] = 0;
                }
            }
        }
    }
    // copy the new board into the old board
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS];
    init_board(board);
    print_board(board);

    while(1) {
        printf("\nPress any key to continue (or q to quit): ");
        char c = getchar();
        if(c == 'q') {
            break;
        }
        update_board(board);
        print_board(board);
    }

    return 0;
}