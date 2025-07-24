//FormAI DATASET v1.0 Category: Chess AI ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 8
#define COLS 8

char board[ROWS][COLS];
int score = 0;

void initBoard() {
    memset(board, ' ', sizeof(board));
    board[3][3] = board[4][4] = 'X';
    board[3][4] = board[4][3] = 'O';
}

void printBoard() {
    printf("  ");
    for (int i = 0; i < COLS; i++) {
        printf("%c ", i + 'a');
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", i + 1);
    }

    printf("  ");
    for (int i = 0; i < COLS; i++) {
        printf("%c ", i + 'a');
    }
    printf("\n");
}

int isValid(int row, int col) {
    if (board[row][col] != ' ') {
        return 0;
    }

    int valid = 0;
    int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

    for (int i = 0; i < 8; i++) {
        int r = row + dr[i];
        int c = col + dc[i];
        int count = 0;
        while (r >= 0 && r < ROWS && c >= 0 && c < COLS && board[r][c] == 'X') {
            r += dr[i];
            c += dc[i];
            count++;
        }
        if (count > 0 && r >= 0 && r < ROWS && c >= 0 && c < COLS && board[r][c] == 'O') {
            valid = 1;
            break;
        }
    }

    return valid;
}

void getNextMove(int *row, int *col) {
    srand(time(NULL));
    do {
        *row = rand() % ROWS;
        *col = rand() % COLS;
    } while (!isValid(*row, *col));
}

void flipTiles(int row, int col) {
    board[row][col] = 'O';

    int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

    for (int i = 0; i < 8; i++) {
        int r = row + dr[i];
        int c = col + dc[i];
        int count = 0;
        while (r >= 0 && r < ROWS && c >= 0 && c < COLS && board[r][c] == 'X') {
            r += dr[i];
            c += dc[i];
            count++;
        }
        if (count > 0 && r >= 0 && r < ROWS && c >= 0 && c < COLS && board[r][c] == 'O') {
            for (int j = 1; j <= count; j++) {
                board[row + j * dr[i]][col + j * dc[i]] = 'O';
                score++;
            }
        }
    }
}

int isGameOver() {
    int over = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (isValid(i, j)) {
                over = 0;
                break;
            }
        }
        if (!over) {
            break;
        }
    }
    return over;
}

int main() {
    printf("Welcome to Chess AI!\n");
    initBoard();
    printBoard();
    while (!isGameOver()) {
        printf("Score: %d\n", score);
        int row, col;
        getNextMove(&row, &col);
        printf("AI moves: %c%d\n", col + 'a', row + 1);
        flipTiles(row, col);
        printBoard();
    }
    printf("Final Score: %d\n", score);
    return 0;
}