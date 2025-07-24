//FormAI DATASET v1.0 Category: Game of Life ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int board[SIZE][SIZE] = {0};
int temp[SIZE][SIZE] = {0};

// Function to initialize the game board
void initialize_board() {
    srand(time(NULL));
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            board[i][j] = rand()%2;
        }
    }
}

// Function to display the game board
void display_board() {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(board[i][j] == 1)
                printf("* ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check the number of live neighbors for each cell
int live_neighbors(int row, int col) {
    int count = 0;
    int max_row = (row+1<SIZE)?row+1:SIZE-1;
    int max_col = (col+1<SIZE)?col+1:SIZE-1;
    int min_row = (row-1>=0)?row-1:0;
    int min_col = (col-1>=0)?col-1:0;
    for(int i=min_row; i<=max_row; i++) {
        for(int j=min_col; j<=max_col; j++) {
            if(i==row && j==col)
                continue;
            count += board[i][j];
        }
    }
    return count;
}

// Function to update the game board based on the rules
void update_board() {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            int neighbors = live_neighbors(i,j);
            if(board[i][j] == 1) {
                if(neighbors < 2 || neighbors > 3)
                    temp[i][j] = 0;
                else
                    temp[i][j] = 1;
            }
            else {
                if(neighbors == 3)
                    temp[i][j] = 1;
                else
                    temp[i][j] = 0;
            }
        }
    }
    // Copy temp to board
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            board[i][j] = temp[i][j];
        }
    }
}

int main() {
    initialize_board();
    display_board();
    for(int i=0; i<10; i++) {
        update_board();
        display_board();
    }
    return 0;
}