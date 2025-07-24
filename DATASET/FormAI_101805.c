//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75
#define FREE_SPACE_VALUE -1

void print_board(int board[ROWS][COLS], int mark[ROWS][COLS]);
void generate_numbers(int board[ROWS][COLS]);
int call_number(int board[ROWS][COLS], int numbers_called[], int *num_called_count);
int is_game_over(int mark[ROWS][COLS]);
int check_bingo(int mark[ROWS][COLS], int row, int col, int row_delta, int col_delta);

int main() {
    int board[ROWS][COLS];
    int mark[ROWS][COLS] = {0};
    int numbers_called[MAX_NUM] = {0};
    int num_called_count = 0;
    int game_over = 0;

    srand(time(0));

    generate_numbers(board);

    while (!game_over) {
        print_board(board, mark);
        int called_number = call_number(board, numbers_called, &num_called_count);
        printf("Number called: %d\n", called_number);

        // Mark called number on board
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == called_number) {
                    mark[i][j] = 1;
                    break;
                }
            }
        }

        // Check if game is over
        game_over = is_game_over(mark);
    }

    print_board(board, mark);
    printf("Bingo! You win!\n");

    return 0;
}

void print_board(int board[ROWS][COLS], int mark[ROWS][COLS]) {
    printf("B  I  N  G  O\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (mark[i][j] == 1)
                printf("X");
            else if (board[i][j] == FREE_SPACE_VALUE)
                printf("-");

            printf("%2d ", board[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

void generate_numbers(int board[ROWS][COLS]) {
    int used_numbers[MAX_NUM] = {0};

    // Generate numbers for B column
    for (int i = 0; i < ROWS; i++) {
        int num;
        do {
            num = rand() % 15 + 1;
        } while (used_numbers[num] == 1);

        board[i][0] = num;
        used_numbers[num] = 1;
    }

    // Generate numbers for I column
    for (int i = 0; i < ROWS; i++) {
        int num;
        do {
            num = rand() % 15 + 16;
        } while (used_numbers[num] == 1);

        board[i][1] = num;
        used_numbers[num] = 1;
    }

    // Generate numbers for N column
    for (int i = 0; i < ROWS; i++) {
        int num;
        do {
            num = rand() % 15 + 31;
        } while (used_numbers[num] == 1);

        board[i][2] = num;
        used_numbers[num] = 1;
    }

    // Generate numbers for G column
    for (int i = 0; i < ROWS; i++) {
        int num;
        do {
            num = rand() % 15 + 46;
        } while (used_numbers[num] == 1);

        board[i][3] = num;
        used_numbers[num] = 1;
    }

    // Generate numbers for O column
    for (int i = 0; i < ROWS; i++) {
        int num;
        do {
            num = rand() % 15 + 61;
        } while (used_numbers[num] == 1);

        board[i][4] = num;
        used_numbers[num] = 1;
    }

    board[ROWS/2][COLS/2] = FREE_SPACE_VALUE;  // Set center as free space
}

int call_number(int board[ROWS][COLS], int numbers_called[], int *num_called_count) {
    int num;
    do {
        num = rand() % MAX_NUM + 1;
    } while (numbers_called[num] == 1);

    numbers_called[num] = 1;
    (*num_called_count)++;

    return num;
}

int is_game_over(int mark[ROWS][COLS]) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (check_bingo(mark, i, 0, 0, 1)) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < COLS; j++) {
        if (check_bingo(mark, 0, j, 1, 0)) {
            return 1;
        }
    }

    // Check diagonals
    if (check_bingo(mark, 0, 0, 1, 1) || check_bingo(mark, ROWS-1, 0, -1, 1)) {
        return 1;
    }

    return 0;
}

int check_bingo(int mark[ROWS][COLS], int row, int col, int row_delta, int col_delta) {
    for (int i = 0; i < ROWS; i++) {
        if (mark[row][col] == 0) {
            return 0;
        }

        row += row_delta;
        col += col_delta;
    }

    return 1;
}