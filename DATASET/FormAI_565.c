//FormAI DATASET v1.0 Category: Checkers Game ; Style: multivariable
#include <stdio.h>

#define SIZE 8

void displayBoard(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void initializeBoard(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 0 && i < 3) {
                board[i][j] = 'o';
            } else if ((i + j) % 2 == 0 && i > 4) {
                board[i][j] = 'x';
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

void movePiece(char board[][SIZE], int fromRow, int fromCol, int toRow, int toCol) {
    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = ' ';
}

int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    displayBoard(board);

    int fromRow, fromCol, toRow, toCol;
    printf("Enter the row and column of the piece you want to move (e.g. \"3 2\"): ");
    scanf("%d %d", &fromRow, &fromCol);
    printf("Enter the row and column of the space you want to move the piece to (e.g. \"4 3\"): ");
    scanf("%d %d", &toRow, &toCol);

    movePiece(board, fromRow, fromCol, toRow, toCol);
    displayBoard(board);

    return 0;
}