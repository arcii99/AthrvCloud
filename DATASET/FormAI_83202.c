//FormAI DATASET v1.0 Category: Game of Life ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 70
#define GENS 1000

void seed_board(int board[ROWS][COLS], float threshold);
void print_board(int board[ROWS][COLS]);
int count_neighbors(int row, int col, int board[ROWS][COLS]);
void update_board(int board[ROWS][COLS]);

int main() {
    int board[ROWS][COLS] = {0};
    float threshold = 0.3;

    srand(time(NULL));
    seed_board(board, threshold);
    print_board(board);

    for (int i = 0; i < GENS; i++) {
        update_board(board);
        print_board(board);
    }

    printf("\nSimulation finished!");
    return 0;
}

void seed_board(int board[ROWS][COLS], float threshold) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ((float)rand()/(float)RAND_MAX < threshold) {
                board[i][j] = 1;
            }
        }
    }
}

void print_board(int board[ROWS][COLS]) {
    system("clear");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("Press enter to continue...\n");
    getchar();
}

int count_neighbors(int row, int col, int board[ROWS][COLS]) {
    int count = 0;
    int r, c;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            r = (row + i + ROWS) % ROWS;
            c = (col + j + COLS) % COLS;
            count += board[r][c];
        }
    }

    count -= board[row][col];
    return count;
}

void update_board(int board[ROWS][COLS]) {
    int temp_board[ROWS][COLS] = {0};

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int count = count_neighbors(i, j, board);

            if (board[i][j] == 1 && (count == 2 || count == 3)) {
                temp_board[i][j] = 1;
            } else if (board[i][j] == 0 && count == 3) {
                temp_board[i][j] = 1;
            } else {
                temp_board[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = temp_board[i][j];
        }
    }
}