//FormAI DATASET v1.0 Category: Chess AI ; Style: grateful
#include<stdio.h>
#include<string.h>

#define ROWS 8
#define COLS 8
#define EMPTY ' '

// Function to initialize the chess board
void init_board(char board[ROWS][COLS]){
    char pieces[8] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(i == 0 || i == 7) board[i][j] = pieces[j];
            else if(i == 1 || i == 6) board[i][j] = 'P';
            else board[i][j] = EMPTY;
        }
    }
}

// Function to print the chess board
void print_board(char board[ROWS][COLS]){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main(){
    char chess_board[ROWS][COLS];
    init_board(chess_board);
    printf("Initial Chess Board:\n");
    print_board(chess_board);
    return 0;
}