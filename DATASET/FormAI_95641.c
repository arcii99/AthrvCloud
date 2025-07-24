//FormAI DATASET v1.0 Category: Checkers Game ; Style: inquisitive
#include <stdio.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];
char player1 = 'O'; // Color for player 1 pieces
char player2 = 'X'; // Color for player 2 pieces

void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void setupBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = player1;
            }
        }
    }

    for (int i = BOARD_SIZE - 1; i > BOARD_SIZE - 4; i--) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = player2;
            }
        }
    }
}

int isValidMove(int fromRow, int fromCol, int toRow, int toCol) {
    if (board[toRow][toCol] != '_') {
        return 0;
    }
    
    int rowDiff = toRow - fromRow;
    int colDiff = toCol - fromCol;
    
    if (board[fromRow][fromCol] == player1 && rowDiff > 0) {
        return 0;
    } else if (board[fromRow][fromCol] == player2 && rowDiff < 0) {
        return 0;
    }

    if (rowDiff == 1 && colDiff == 1) {
        return 1;
    } else if (rowDiff == -1 && colDiff == 1) {
        return 1;
    } else if (rowDiff == 2 && colDiff == 2) {
        if (board[fromRow+1][fromCol+1] == player2 || board[fromRow+1][fromCol+1] == 'K') {
            return 1;
        }
    } else if (rowDiff == -2 && colDiff == 2) {
        if (board[fromRow-1][fromCol+1] == player1 || board[fromRow-1][fromCol+1] == 'Q') {
            return 1;
        }
    } else if (rowDiff == 2 && colDiff == -2) {
        if (board[fromRow+1][fromCol-1] == player2 || board[fromRow+1][fromCol-1] == 'K') {
            return 1;
        }
    } else if (rowDiff == -2 && colDiff == -2) {
        if (board[fromRow-1][fromCol-1] == player1 || board[fromRow-1][fromCol-1] == 'Q') {
            return 1;
        }
    }

    return 0;
}

void movePiece(int fromRow, int fromCol, int toRow, int toCol) {
    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = '_';
}

void makeKing(int row, int col) {
    if (board[row][col] == player1) {
        board[row][col] = 'Q';
    } else if (board[row][col] == player2) {
        board[row][col] = 'K';
    }
}

int main() {
    setupBoard();
    printBoard();

    int player = 1;

    while (1) {
        int fromRow, fromCol, toRow, toCol;

        printf("Player %d's turn.\n", player);
        printf("Enter the row of the piece you want to move: ");
        scanf("%d", &fromRow);
        printf("Enter the column of the piece you want to move: ");
        scanf("%d", &fromCol);

        printf("Enter the row of the square you want to move to: ");
        scanf("%d", &toRow);
        printf("Enter the column of the square you want to move to: ");
        scanf("%d", &toCol);

        if (!isValidMove(fromRow, fromCol, toRow, toCol)) {
            printf("Invalid move!\n");
            continue;
        }

        movePiece(fromRow, fromCol, toRow, toCol);

        if ((board[toRow][toCol] == player1 && toRow == BOARD_SIZE - 1) 
                || (board[toRow][toCol] == player2 && toRow == 0)) {
            makeKing(toRow, toCol);
        }

        printBoard();

        if (player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }

    return 0;
}