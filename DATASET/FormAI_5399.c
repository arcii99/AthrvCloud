//FormAI DATASET v1.0 Category: Chess engine ; Style: romantic
#include<stdio.h>
#include<stdlib.h>

void initialize_board(char board[][8]) {
    //set up initial board configuration
    board[0][0] = 'R'; board[0][1] = 'N'; board[0][2] = 'B'; board[0][3] = 'Q';
    board[0][4] = 'K'; board[0][5] = 'B'; board[0][6] = 'N'; board[0][7] = 'R';
    board[1][0] = 'P'; board[1][1] = 'P'; board[1][2] = 'P'; board[1][3] = 'P';
    board[1][4] = 'P'; board[1][5] = 'P'; board[1][6] = 'P'; board[1][7] = 'P';
    board[6][0] = 'p'; board[6][1] = 'p'; board[6][2] = 'p'; board[6][3] = 'p';
    board[6][4] = 'p'; board[6][5] = 'p'; board[6][6] = 'p'; board[6][7] = 'p';
    board[7][0] = 'r'; board[7][1] = 'n'; board[7][2] = 'b'; board[7][3] = 'q';
    board[7][4] = 'k'; board[7][5] = 'b'; board[7][6] = 'n'; board[7][7] = 'r';
}

void print_board(char board[][8]) {
    //print the current state of the board
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char board[8][8];
    initialize_board(board);
    print_board(board);
    return 0;
}