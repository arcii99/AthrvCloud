//FormAI DATASET v1.0 Category: Checkers Game ; Style: happy
#include <stdio.h>
#include <stdbool.h>

#define SIZE 8

// Function to display the game board
void display(char board[][SIZE]) {
    int i, j;

    printf("    ");
    for (i = 0; i < SIZE; i++) {
        printf("%d   ", i + 1);
    }
    printf("\n");

    printf("   ");
    for (i = 0; i < SIZE; i++) {
        printf("----");
    }
    printf("\n");

    for (i = 0; i < SIZE; i++) {
        printf("%d| ", i + 1);
        for (j = 0; j < SIZE; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n");
        printf("   ");
        for (j = 0; j < SIZE; j++) {
            printf("----");
        }
        printf("\n");
    }
}

// Function to set up the game board
void initialize(char board[][SIZE]) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    board[i][j] = 'b';
                } else if (i > 4) {
                    board[i][j] = 'w';
                } else {
                    board[i][j] = ' ';
                }
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

// Function to move a piece
bool move(char board[][SIZE], int fromRow, int fromCol, int toRow, int toCol) {
    if (board[toRow][toCol] != ' ') {
        return false;
    }

    if (board[fromRow][fromCol] == ' ') {
        return false;
    }

    if (board[fromRow][fromCol] == 'w' && toRow <= fromRow) {
        return false;
    }

    if (board[fromRow][fromCol] == 'b' && toRow >= fromRow) {
        return false;
    }

    if (toRow == fromRow + 2 || toRow == fromRow - 2) {
        int jumpRow = (fromRow + toRow) / 2;
        int jumpCol = (fromCol + toCol) / 2;

        if (board[jumpRow][jumpCol] == ' ' || board[jumpRow][jumpCol] == board[fromRow][fromCol]) {
            return false;
        }

        board[jumpRow][jumpCol] = ' ';
    }

    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = ' ';

    if (board[toRow][toCol] == 'w' && toRow == SIZE - 1) {
        board[toRow][toCol] = 'W';
    }

    if (board[toRow][toCol] == 'b' && toRow == 0) {
        board[toRow][toCol] = 'B';
    }

    return true;
}

int main() {
    char board[SIZE][SIZE];
    int fromRow, fromCol, toRow, toCol;
    bool result;

    initialize(board);
    display(board);

    while (true) {
        printf("Enter the starting row of the piece you want to move: ");
        scanf("%d", &fromRow);

        printf("Enter the starting column of the piece you want to move: ");
        scanf("%d", &fromCol);

        printf("Enter the row to which you want to move the piece: ");
        scanf("%d", &toRow);

        printf("Enter the column to which you want to move the piece: ");
        scanf("%d", &toCol);

        result = move(board, fromRow - 1, fromCol - 1, toRow - 1, toCol - 1);

        if (!result) {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        display(board);
        printf("Move successful!\n\n");
    }

    return 0;
}