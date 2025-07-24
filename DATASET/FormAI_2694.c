//FormAI DATASET v1.0 Category: Game of Life ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 20
#define COLS 40
#define GENERATIONS 10

void print_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int count_neighbours(int board[ROWS][COLS], int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0)
                continue;
            if (row + i < 0 || row + i >= ROWS)
                continue;
            if (col + j < 0 || col + j >= COLS)
                continue;
            if (board[row+i][col+j] == 1)
                count++;
        }
    }
    return count;
}

void update_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbours = count_neighbours(board, i, j);
            if (board[i][j] == 1) {
                if (neighbours < 2 || neighbours > 3)
                    board[i][j] = 0;
            } else {
                if (neighbours == 3)
                    board[i][j] = 1;
            }
        }
    }
}

int main() {
    int board[ROWS][COLS] = {0};
    int player1board[ROWS][COLS] = {0};
    int player2board[ROWS][COLS] = {0};

    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int random_value = rand() % 10;
            if (random_value == 0)
                board[i][j] = 1;
        }
    }

    for (int generation = 0; generation < GENERATIONS; generation++) {
        printf("Generation %d\n", generation);
        printf("Player 1 board:\n");
        print_board(player1board);
        printf("\n\nPlayer 2 board:\n");
        print_board(player2board);
        printf("\n\n");

        printf("Player 1, enter your move (row col): ");
        int row, col;
        scanf("%d %d", &row, &col);
        player1board[row][col] = 1;

        printf("Player 2, enter your move (row col): ");
        scanf("%d %d", &row, &col);
        player2board[row][col] = 1;

        update_board(board);
        update_board(player1board);
        update_board(player2board);
    }
    return 0;
}