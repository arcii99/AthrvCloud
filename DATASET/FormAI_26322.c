//FormAI DATASET v1.0 Category: Memory Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initialize_board(int board[ROWS][COLS]) {
    int num_pairs = ROWS * COLS / 2;
    int pairs_placed = 0;
    int value = 1;

    while (pairs_placed < num_pairs) {
        int row = rand() % ROWS;
        int col = rand() % COLS;

        if (board[row][col] == 0) {
            board[row][col] = value;
            pairs_placed++;

            // Place the corresponding value in a random location
            do {
                row = rand() % ROWS;
                col = rand() % COLS;
            } while (board[row][col] != 0);

            board[row][col] = value;
        }

        value++;
    }
}

void display_board(int board[ROWS][COLS], int revealed[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (revealed[i][j]) {
                printf("%d ", board[i][j]);
            } else {
                printf("* ");
            }
        }

        printf("\n");
    }
}

void clear_screen() {
    #ifdef __linux__
        system("clear");
    #elif defined _WIN32
        system("cls");
    #endif
}

int main() {
    int board[ROWS][COLS] = {0};
    int revealed[ROWS][COLS] = {0};
    int num_revealed = 0;

    srand(time(NULL));
    initialize_board(board);

    while (num_revealed < ROWS * COLS) {
        clear_screen();
        display_board(board, revealed);

        int row1, col1, row2, col2;

        printf("Enter the first card: ");
        scanf("%d %d", &row1, &col1);

        printf("Enter the second card: ");
        scanf("%d %d", &row2, &col2);

        row1--;
        col1--;
        row2--;
        col2--;

        if (row1 < 0 || row1 >= ROWS || col1 < 0 || col1 >= COLS
            || row2 < 0 || row2 >= ROWS || col2 < 0 || col2 >= COLS) {
            printf("Invalid row/col entered\n");
            continue;
        }

        if (revealed[row1][col1] || revealed[row2][col2]) {
            printf("Card already revealed\n");
            continue;
        }

        revealed[row1][col1] = 1;
        revealed[row2][col2] = 1;
        num_revealed += 2;

        if (board[row1][col1] != board[row2][col2]) {
            revealed[row1][col1] = 0;
            revealed[row2][col2] = 0;
        }
    }

    printf("Congratulations! You won the game.\n");
    return 0;
}