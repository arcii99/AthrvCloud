//FormAI DATASET v1.0 Category: Checkers Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8

typedef struct {
    int x;
    int y;
} Position;

typedef enum {
    EMPTY,
    BLACK,
    WHITE
} Piece;

Piece board[ROWS][COLS] = {EMPTY};

void printBoard() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j] == EMPTY ? '-' : board[i][j] == BLACK ? 'b' : 'w');
        }
        printf("\n");
    }
    printf("\n");
}

int isLegalMove(Position currentPos, Position nextPos, Piece currentPlayer) {
    // check if piece moved diagonally
    if(abs(nextPos.x - currentPos.x) != abs(nextPos.y - currentPos.y)) {
        return 0;
    }
    
    // check if piece is moving forward
    if(currentPlayer == BLACK && nextPos.y <= currentPos.y) {
        return 0;
    } else if(currentPlayer == WHITE && nextPos.y >= currentPos.y) {
        return 0;
    }
    
    // check if piece is moving within board
    if(nextPos.x < 0 || nextPos.x >= ROWS || nextPos.y < 0 || nextPos.y >= COLS) {
        return 0;
    }
    
    // check if destination is empty
    if(board[nextPos.x][nextPos.y] != EMPTY) {
        return 0;
    }
    
    // check if piece is jumping over another piece
    if(abs(nextPos.x - currentPos.x) <= 1) {
        return 1;
    }
    
    int jumpPosRow = currentPos.x + (nextPos.x - currentPos.x) / 2;
    int jumpPosCol = currentPos.y + (nextPos.y - currentPos.y) / 2;
    if(board[jumpPosRow][jumpPosCol] != (currentPlayer == BLACK ? WHITE : BLACK)) {
        return 0;
    }
    
    return 1;
}

void makeMove(Position currentPos, Position nextPos) {
    board[nextPos.x][nextPos.y] = board[currentPos.x][currentPos.y];
    board[currentPos.x][currentPos.y] = EMPTY;
}

int main() {
    // initialize board
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(i % 2 == 0) {
                board[i][j] = j % 2 == 0 ? EMPTY : WHITE;
            } else {
                board[i][j] = j % 2 == 0 ? WHITE : EMPTY;
            }
        }
    }
    
    printBoard();
    
    Piece currentPlayer = BLACK;
    
    while(1) {
        printf("%s's turn\n", currentPlayer == BLACK ? "Black" : "White");
        printf("Enter current position (row,col): ");
        Position currentPos;
        scanf("%d,%d", &currentPos.x, &currentPos.y);
        printf("Enter next position (row,col): ");
        Position nextPos;
        scanf("%d,%d", &nextPos.x, &nextPos.y);
        
        if(isLegalMove(currentPos, nextPos, currentPlayer)) {
            makeMove(currentPos, nextPos);
            printBoard();
            if(currentPlayer == BLACK) {
                currentPlayer = WHITE;
            } else {
                currentPlayer = BLACK;
            }
        } else {
            printf("Invalid move\n");
        }
    }   
    
    return 0;
}