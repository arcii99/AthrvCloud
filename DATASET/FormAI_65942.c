//FormAI DATASET v1.0 Category: Game of Life ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 50
#define COLS 50

//function to initialize the board with random values
void initialize_board(int board[][COLS]) {
    srand(time(NULL)); //seed the random number generator
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = rand() % 2; //populate cell with either 0 or 1
        }
    }
}

//function to print out the board
void print_board(int board[][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(board[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
}

//function to calculate the next generation of cells
void next_generation(int board[][COLS]) {
    int new_board[ROWS][COLS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int count = 0;
            //check the neighboring cells
            for(int x=i-1; x<=i+1; x++) {
                for(int y=j-1; y<=j+1; y++) {
                    if(x<0 || x>=ROWS || y<0 || y>=COLS) {
                        continue;
                    }
                    if(x==i && y==j) {
                        continue;
                    }
                    if(board[x][y] == 1) {
                        count++;
                    }
                }
            }
            //apply the rules of the game
            if(board[i][j] == 1 && (count<2 || count>3)) {
                new_board[i][j] = 0;
            } else if(board[i][j] == 0 && count==3) {
                new_board[i][j] = 1;
            } else {
                new_board[i][j] = board[i][j];
            }
        }
    }
    //copy over the new board
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS];
    initialize_board(board);
    for(int i=0; i<100; i++) {
        print_board(board);
        next_generation(board);
        usleep(100000);
    }
    return 0;
}