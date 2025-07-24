//FormAI DATASET v1.0 Category: Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 10
#define MINES_NUM 15

void init_board(int board[][BOARD_SIZE], int size);
void display_board(int board[][BOARD_SIZE], int size);
bool is_valid_choice(int row, int col, int size);
bool is_mine(int board[][BOARD_SIZE], int row, int col);
int count_nearby_mines(int board[][BOARD_SIZE], int row, int col, int size);
void flood_fill(int board[][BOARD_SIZE], int row, int col, int size);

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    bool game_over = false;
    int row_choice, col_choice;
    int remaining_cells = BOARD_SIZE * BOARD_SIZE - MINES_NUM;

    srand(time(NULL));
    init_board(board, BOARD_SIZE);

    printf("Welcome to the Minesweeper game!\n\n");
    display_board(board, BOARD_SIZE);

    while (!game_over) {
        printf("Enter a row and column to clear: ");
        scanf("%d %d", &row_choice, &col_choice);

        if (!is_valid_choice(row_choice, col_choice, BOARD_SIZE)) {
            printf("Invalid row or column choice. Please try again.\n\n");
            continue;
        }

        if (is_mine(board, row_choice, col_choice)) {
            printf("Oops, you've hit a mine! Game over.\n");
            game_over = true;
        } else {
            flood_fill(board, row_choice, col_choice, BOARD_SIZE);
            display_board(board, BOARD_SIZE);
            remaining_cells--;

            if (remaining_cells == 0) {
                printf("Congratulations, you won the game!\n");
                game_over = true;
            }
        }
    }

    return 0;
}

void init_board(int board[][BOARD_SIZE], int size) {
    int i, j;
    int mines_placed = 0;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            board[i][j] = 0;
        }
    }

    while (mines_placed < MINES_NUM) {
        int row = rand() % size;
        int col = rand() % size;

        if (board[row][col] == 0) {
            board[row][col] = 9;
            mines_placed++;
        }
    }
}

void display_board(int board[][BOARD_SIZE], int size) {
    int i, j;

    printf("\n   ");

    for (i = 0; i < size; i++) {
        printf("%2d ", i);
    }

    printf("\n");

    printf("  +");
    for (i = 0; i < size; i++) {
        printf("--+");
    }

    printf("\n");

    for (i = 0; i < size; i++) {
        printf("%2d|", i);

        for (j = 0; j < size; j++) {
            if (board[i][j] == 0) {
                printf("  |");
            } else if (board[i][j] == 9) {
                printf("* |");
            } else if (board[i][j] == -1) {
                printf("  |");
            } else {
                printf("%d |", board[i][j]);
            }
        }

        printf("\n");

        printf("  +");
        for (j = 0; j < size; j++) {
            printf("--+");
        }

        printf("\n");
    }

    printf("\n");
}

bool is_valid_choice(int row, int col, int size) {
    return (row >= 0 && row < size && col >= 0 && col < size);
}

bool is_mine(int board[][BOARD_SIZE], int row, int col) {
    return (board[row][col] == 9);
}

int count_nearby_mines(int board[][BOARD_SIZE], int row, int col, int size) {
    int count = 0;
    int i, j;

    for (i = row - 1; i <= row + 1; i++) {
        for (j = col - 1; j <= col + 1; j++) {
            if (!is_valid_choice(i, j, size)) {
                continue;
            }

            if (board[i][j] == 9) {
                count++;
            }
        }
    }

    return count;
}

void flood_fill(int board[][BOARD_SIZE], int row, int col, int size) {
    if (!is_valid_choice(row, col, size) || board[row][col] != 0) {
        return;
    }

    int nearby_mines = count_nearby_mines(board, row, col, size);
    board[row][col] = nearby_mines;

    if (nearby_mines == 0) {
        flood_fill(board, row - 1, col, size);
        flood_fill(board, row + 1, col, size);
        flood_fill(board, row, col - 1, size);
        flood_fill(board, row, col + 1, size);
    }
}