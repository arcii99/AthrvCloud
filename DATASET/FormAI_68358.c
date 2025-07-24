//FormAI DATASET v1.0 Category: Chess AI ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];
bool whiteTurn = true;

void loadBoard() {
    // initialize the board with standard chess setup
    char pieces[8] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
    for(int i=0; i<8; i++) {
        board[0][i] = pieces[i];
        board[7][i] = pieces[i]+32; // black pieces
        board[1][i] = 'P';
        board[6][i] = 'P'+32; // black pawns
    }
    for(int i=2; i<6; i++) {
        for(int j=0; j<8; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n   A B C D E F G H\n");
    printf("  +----------------+\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%d | ", i+1);
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("  +----------------+\n");
}

bool isValidMove(int startRow, int startCol, int endRow, int endCol) {
    char piece = board[startRow][startCol];
    if(startRow<0 || startRow>=8 || startCol<0 || startCol>=8 || endRow<0 || endRow>=8 || endCol<0 || endCol>=8) {
        printf("Invalid move. Out of bounds.\n");
        return false;
    }
    if(piece==' ') {
        printf("Invalid move. No piece at start position.\n");
        return false;
    }
    if(whiteTurn && piece>90) { // uppercase = white
        printf("Invalid move. It's white's turn to move.\n");
        return false;
    }
    if(!whiteTurn && piece<97) { // lowercase = black
        printf("Invalid move. It's black's turn to move.\n");
        return false;
    }
    // TODO: implement move legality checking
    return true;
}

bool makeMove(int startRow, int startCol, int endRow, int endCol) {
    if(!isValidMove(startRow, startCol, endRow, endCol)) {
        return false;
    }
    char piece = board[startRow][startCol];
    board[startRow][startCol] = ' ';
    board[endRow][endCol] = piece;
    whiteTurn = !whiteTurn; // switch turn
    return true;
}

int main() {
    loadBoard();
    printBoard();
    char input[5];
    int startRow, startCol, endRow, endCol;
    while(true) {
        printf("%s> ", whiteTurn ? "White" : "Black");
        fgets(input, sizeof(input), stdin);
        if(strlen(input)<5) {
            printf("Invalid input.\n");
            continue;
        }
        startCol = input[0]-'A';
        startRow = input[1]-'1';
        endCol = input[3]-'A';
        endRow = input[4]-'1';
        if(makeMove(startRow, startCol, endRow, endCol)) {
            printBoard();
        }
    }
    return 0;
}