//FormAI DATASET v1.0 Category: Chess engine ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

//This is a cheerful and unique C chess engine example program

//global variables
char board[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

//displaying the current board
void display_board(){
    int i, j;
    printf("\nCurrent Board:\n");
    for(i=0; i<8; i++){
        printf("\n-----------------\n");
        for(j=0; j<8; j++){
            printf("| %c ", board[i][j]);
        }
        printf("|");
    }
    printf("\n-----------------\n");
}

//moving the pieces on the board
void move_piece(){
    int from_row, from_col, to_row, to_col;
    printf("\nEnter coordinates of piece you want to move (row and column): ");
    scanf("%d %d", &from_row, &from_col);
    printf("\nEnter coordinates of where you want to move it (row and column): ");
    scanf("%d %d", &to_row, &to_col);
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = ' ';
    display_board();
}

//main function
int main(){
    printf("Welcome to the C Chess Engine!\n");
    display_board();
    move_piece();
    return 0;
}