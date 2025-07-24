//FormAI DATASET v1.0 Category: Table Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int row;
    int col;
    char sym;
} Piece;

void printBoard(int boardSize, Piece board[boardSize][boardSize]) {
    printf("  ");
    for (int i = 0; i < boardSize; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < boardSize; i++) {
        printf("%d ", i);
        for (int j = 0; j < boardSize; j++) {
            printf("%c ", board[i][j].sym);
        }
        printf("\n");
    }
}

int isValidMove(int boardSize, Piece board[boardSize][boardSize], int row, int col) {
    if (row < 0 || row >= boardSize || col < 0 || col >= boardSize) {
        return 0;
    }

    if (board[row][col].sym != '-') {
        return 0;
    }

    int offsets[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1},  {1, 0},  {1, 1}
    };

    int isValid = 0;

    for (int i = 0; i < 8; i++) {
        int r = row + offsets[i][0];
        int c = col + offsets[i][1];

        if (r >= 0 && r < boardSize && c >= 0 && c < boardSize && board[r][c].sym != '-' && board[r][c].sym != board[row][col].sym) {
            isValid = 1;
            while (1) {
                r += offsets[i][0];
                c += offsets[i][1];
                if (r < 0 || r >= boardSize || c < 0 || c >= boardSize || board[r][c].sym == '-') {
                    isValid = 0;
                    break;
                } else if (board[r][c].sym == board[row][col].sym) {
                    break;
                }
            }
            if (isValid == 0) {
                continue;
            }
            r = row + offsets[i][0];
            c = col + offsets[i][1];
            while (board[r][c].sym != board[row][col].sym) {
                board[r][c].sym = board[row][col].sym;
                r += offsets[i][0];
                c += offsets[i][1];
            }
        }
    }

    return isValid;
}

int main() {
    int boardSize = 8;
    Piece board[boardSize][boardSize];

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            board[i][j].row = i;
            board[i][j].col = j;
            board[i][j].sym = '-';
        }
    }

    board[3][3].sym = 'X';
    board[4][4].sym = 'X';
    board[3][4].sym = 'O';
    board[4][3].sym = 'O';

    printBoard(boardSize, board);

    srand(time(NULL));
    int player = rand() % 2;

    while (1) {
        int row, col;
        printf("Player %d, enter row and col: ", player);
        scanf("%d %d", &row, &col);

        if (isValidMove(boardSize, board, row, col) == 0) {
            printf("Invalid move! Try again.\n");
        } else {
            printBoard(boardSize, board);
            player = (player + 1) % 2;
        }
    }

    return 0;
}