//FormAI DATASET v1.0 Category: Game of Life ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// function to print the current state of the board
void print_board(int board[ROWS][COLS]){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(board[i][j] == 0){
                printf(".");
            }
            else{
                printf("*");
            }
        }
        printf("\n");
    }
}

// function to generate a new board randomly
void generate_board(int board[ROWS][COLS]){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            board[i][j] = rand() % 2;
        }
    }
}

// function to check the number of living neighbors for a given cell
int count_neighbors(int board[ROWS][COLS], int row, int col){
    int count = 0;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i == 0 && j == 0){
                continue;
            }
            int r = row + i;
            int c = col + j;
            if(r < 0 || r >= ROWS || c < 0 || c >= COLS){
                continue;
            }
            if(board[r][c] == 1){
                count++;
            }
        }
    }
    return count;
}

// function to update the board based on the number of living neighbors
void update_board(int board[ROWS][COLS]){
    int temp_board[ROWS][COLS];
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            int neighbors = count_neighbors(board, i, j);
            if(board[i][j] == 1 && neighbors < 2){
                temp_board[i][j] = 0; // underpopulation
            }
            else if(board[i][j] == 1 && (neighbors == 2 || neighbors == 3)){
                temp_board[i][j] = 1; // survival
            }
            else if(board[i][j] == 1 && neighbors > 3){
                temp_board[i][j] = 0; // overpopulation
            }
            else if(board[i][j] == 0 && neighbors == 3){
                temp_board[i][j] = 1; // reproduction
            }
            else{
                temp_board[i][j] = board[i][j];
            }
        }
    }
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            board[i][j] = temp_board[i][j];
        }
    }
}

int main(){
    int board[ROWS][COLS];
    srand(time(NULL));
    generate_board(board);
    print_board(board);
    for(int i=0; i<10; i++){
        update_board(board);
        print_board(board);
    }
    return 0;
}