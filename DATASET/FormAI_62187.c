//FormAI DATASET v1.0 Category: Game of Life ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void init_board(int board[ROWS][COLS]){
    srand(time(NULL));
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            board[i][j] = (rand() % 2); // Randomly initialize the cells as alive (1) or dead (0)
        }
    }
}

void update_board(int board[ROWS][COLS]){
    int new_board[ROWS][COLS];
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            int alive_neighbors = 0;
            for(int ni=i-1;ni<=i+1;ni++){
                for(int nj=j-1;nj<=j+1;nj++){
                    if(ni==i && nj==j) continue; // Don't check the cell itself
                    if(ni<0 || nj<0 || ni>=ROWS || nj>=COLS) continue; // Out of bounds, skip this cell
                    if(board[ni][nj]==1) alive_neighbors++; // If the neighbor is alive, add to the count
                }
            }
            if(alive_neighbors==3 || (alive_neighbors==2 && board[i][j]==1)){
                new_board[i][j] = 1; // Cell lives on
            } else {
                new_board[i][j] = 0; // Cell dies
            }
        }
    }
    // Update the board with the new state
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            board[i][j] = new_board[i][j];
        }
    }
}

void print_board(int board[ROWS][COLS]){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            if(board[i][j]==1){
                putchar('*');
            } else {
                putchar('.');
            }
        }
        putchar('\n');
    }
}

int main(){
    int board[ROWS][COLS];

    init_board(board);

    for(int i=0;i<100;i++){
        system("clear"); // Clear the terminal screen
        print_board(board);
        update_board(board);
    }

    return 0;
}