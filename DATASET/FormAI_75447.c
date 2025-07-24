//FormAI DATASET v1.0 Category: Chess engine ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE] = {
            {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
            {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
            {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
            {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

int main(){
    printf("Welcome to the Chess game!\n");
    
    //print the initial board
    printf("Initial Board:\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("[%c]", board[i][j]);
        }
        printf("\n");
    }

    //simulate a move
    printf("\n***Player 1 makes a move***\n");
    int x1 = 1, y1 = 4, x2 = 2, y2 = 4;

    //check if the move is legal
    if(board[x1][y1] == 'p' && x2 == x1+1 && y2 == y1) {
        board[x2][y2] = board[x1][y1];
        board[x1][y1] = ' ';
    } else {
        printf("Sorry, that move is not legal!\n");
    }

    //print the updated board
    printf("\nUpdated Board:\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("[%c]", board[i][j]);
        }
        printf("\n");
    }

    //simulate a move
    printf("\n***Player 2 makes a move***\n");
    int x3 = 6, y3 = 1, x4 = 4, y4 = 2;

    //check if the move is legal
    if(board[x3][y3] == 'P' && x4 == x3-2 && y4 == y3+1) {
        board[x4][y4] = board[x3][y3];
        board[x3][y3] = ' ';
    } else {
        printf("Oops, that move is not legal!\n");
    }

    //print the updated board
    printf("\nUpdated Board:\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("[%c]", board[i][j]);
        }
        printf("\n");
    }

    printf("\nThanks for playing!\n");

    return 0;
}