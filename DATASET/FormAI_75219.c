//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define MAX_ROUNDS 20

void print_board(int board[ROWS][COLS], int visible[ROWS][COLS]);
void place_bombs(int board[ROWS][COLS], int n_bombs);
void reveal_cell(int board[ROWS][COLS], int visible[ROWS][COLS], int row, int col);
int count_adjacent_bombs(int board[ROWS][COLS], int row, int col);
void print_credits();

int main() {
    int board[ROWS][COLS];
    int visible[ROWS][COLS] = {0};
    int n_bombs = 15;
    int n_rounds = 0;
    int row, col;

    srand(time(NULL));
    place_bombs(board, n_bombs);

    printf("Welcome to MineSweeper!\n");
    while (n_rounds < MAX_ROUNDS) {
        printf("Round %d\n", n_rounds + 1);
        print_board(board, visible);
        printf("Enter the row and column of a cell to reveal: ");
        scanf("%d %d", &row, &col);

        if (board[row][col] == -1) {
            printf("Game over! You revealed a bomb.\n");
            print_board(board, visible);
            print_credits();
            exit(0);
        } else {
            reveal_cell(board, visible, row, col);
            n_rounds++;
        }

        if (n_rounds == MAX_ROUNDS) {
            printf("Congratulations! You won!\n");
            print_credits();
            exit(0);
        }
    }

    return 0;
}

void print_board(int board[ROWS][COLS], int visible[ROWS][COLS]) {
    printf("   ");
    for (int i = 0; i < COLS; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%2d ", i);
        for (int j = 0; j < COLS; j++) {
            if (visible[i][j]) {
                if (board[i][j] == -1) {
                    printf("* ");
                } else {
                    printf("%d ", count_adjacent_bombs(board, i, j));
                }
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void place_bombs(int board[ROWS][COLS], int n_bombs) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }

    int count = 0;
    while (count < n_bombs) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (board[row][col] == 0) {
            board[row][col] = -1;
            count++;
        }
    }
}

void reveal_cell(int board[ROWS][COLS], int visible[ROWS][COLS], int row, int col) {
    if (visible[row][col]) {
        return;
    }

    visible[row][col] = 1;

    if (count_adjacent_bombs(board, row, col) > 0) {
        return;
    }

    if (row > 0) {
        reveal_cell(board, visible, row - 1, col);
    }
    if (row < ROWS - 1) {
        reveal_cell(board, visible, row + 1, col);
    }
    if (col > 0) {
        reveal_cell(board, visible, row, col - 1);
    }
    if (col < COLS - 1) {
        reveal_cell(board, visible, row, col + 1);
    }
}

int count_adjacent_bombs(int board[ROWS][COLS], int row, int col) {
    int count = 0;
    if (row > 0 && board[row - 1][col] == -1) {
        count++;
    }
    if (row < ROWS - 1 && board[row + 1][col] == -1) {
        count++;
    }
    if (col > 0 && board[row][col - 1] == -1) {
        count++;
    }
    if (col < COLS - 1 && board[row][col + 1] == -1) {
        count++;
    }
    if (row > 0 && col > 0 && board[row - 1][col - 1] == -1) {
        count++;
    }
    if (row > 0 && col < COLS - 1 && board[row - 1][col + 1] == -1) {
        count++;
    }
    if (row < ROWS - 1 && col > 0 && board[row + 1][col - 1] == -1) {
        count++;
    }
    if (row < ROWS - 1 && col < COLS - 1 && board[row + 1][col + 1] == -1) {
        count++;
    }
    return count;
}

void print_credits() {
    printf("\nGame created by [YOUR NAME HERE]\n");
}