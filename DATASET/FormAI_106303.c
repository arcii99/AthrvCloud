//FormAI DATASET v1.0 Category: Game of Life ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 20

// Function to initialize the board
void init_board(int board[][COLUMNS]){
    int i, j;
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
            board[i][j] = rand()%2;
        }
    }
}

// Function to print the board
void print_board(int board[][COLUMNS]){
    int i, j;
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
            if(board[i][j] == 1){
                printf("* ");
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to update the board based on Game of Life rules
void update_board(int board[][COLUMNS]){
    int next_board[ROWS][COLUMNS];
    int i, j, count;
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
            count = 0;
            // Check for neighbors
            if(i > 0 && j > 0 && board[i-1][j-1] == 1){
                count++;
            }
            if(i > 0 && board[i-1][j] == 1){
                count++;
            }
            if(i > 0 && j < COLUMNS-1 && board[i-1][j+1] == 1){
                count++;
            }
            if(j > 0 && board[i][j-1] == 1){
                count++;
            }
            if(j < COLUMNS-1 && board[i][j+1] == 1){
                count++;
            }
            if(i < ROWS-1 && j > 0 && board[i+1][j-1] == 1){
                count++;
            }
            if(i < ROWS-1 && board[i+1][j] == 1){
                count++;
            }
            if(i < ROWS-1 && j < COLUMNS-1 && board[i+1][j+1] == 1){
                count++;
            }
            // Apply the rules of Game of Life
            if(board[i][j] == 1 && (count < 2 || count > 3)){
                next_board[i][j] = 0;
            }
            else if(board[i][j] == 0 && count == 3){
                next_board[i][j] = 1;
            }
            else{
                next_board[i][j] = board[i][j];
            }
        }
    }
    // Update the board
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
            board[i][j] = next_board[i][j];
        }
    }
}

int main(){
    int board[ROWS][COLUMNS];
    srand(time(NULL));
    init_board(board);
    printf("Original board:\n");
    print_board(board);
    int i;
    for(i=0; i<5; i++){
        update_board(board);
        printf("Updated board %d:\n", i+1);
        print_board(board);
    }
    return 0;
}