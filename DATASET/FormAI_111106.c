//FormAI DATASET v1.0 Category: Game of Life ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 40
#define COLS 80

void initialize_game_board(int game_board[ROWS][COLS])
{
    srand(time(NULL));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            game_board[i][j] = rand() % 2;
        }
    }
}

void display_game_board(int game_board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (game_board[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int get_live_neighbors(int game_board[ROWS][COLS], int row, int col) {
    int count = 0;

    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i == row && j == col) {
                continue;
            }

            if (i < 0 || i >= ROWS) {
                continue;
            }

            if (j < 0 || j >= COLS) {
                continue;
            }

            if (game_board[i][j] == 1) {
                count++;
            }
        }
    }

    return count;
}

void update_game_board(int game_board[ROWS][COLS])
{
    int new_game_board[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int live_neighbors = get_live_neighbors(game_board, i, j);

            if (game_board[i][j] == 1) {
                if (live_neighbors < 2 || live_neighbors > 3) {
                    new_game_board[i][j] = 0;
                } else {
                    new_game_board[i][j] = 1;
                }
            } else { // cell is dead
                if (live_neighbors == 3) {
                    new_game_board[i][j] = 1;
                } else {
                    new_game_board[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            game_board[i][j] = new_game_board[i][j];
        }
    }
}

int main()
{
    int game_board[ROWS][COLS];
    int generations = 0;

    initialize_game_board(game_board);

    while (1) {
        printf("Generation: %d\n", generations);
        display_game_board(game_board);
        update_game_board(game_board);
        generations++;
        printf("\n\n");
    }

    return 0;
}