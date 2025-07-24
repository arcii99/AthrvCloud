//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define RANGE 75

// function declarations
void init_board(int bingo_board[ROWS][COLS]);
void print_board(int bingo_board[ROWS][COLS]);
void generate_numbers(int bingo_numbers[RANGE]);
int draw_number(int bingo_numbers[RANGE], int used_numbers[RANGE]);
int check_win(int bingo_board[ROWS][COLS]);

int main()
{
    int bingo_board[ROWS][COLS];
    int bingo_numbers[RANGE];
    int used_numbers[RANGE] = {0};

    init_board(bingo_board);
    generate_numbers(bingo_numbers);

    int turns = 0;
    while (check_win(bingo_board) == 0) {
        printf("Turn %d:\n", turns+1);
        print_board(bingo_board);

        int num_drawn = draw_number(bingo_numbers, used_numbers);
        printf("Number drawn: %d\n", num_drawn);

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (bingo_board[i][j] == num_drawn) {
                    bingo_board[i][j] = -1;
                    break;
                }
            }
        }

        turns++;
    }

    printf("BINGO! You won in %d turns!\n", turns);

    return 0;
}

// initialize a new bingo board
void init_board(int bingo_board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 2 && j == 2) {
                bingo_board[i][j] = -1;
            } else {
                bingo_board[i][j] = rand() % 15 + (15*j+1);
            }
        }
    }
}

// print the current bingo board
void print_board(int bingo_board[ROWS][COLS])
{
    printf("    B   I   N   G   O\n");
    printf("---------------------\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (bingo_board[i][j] == -1) {
                printf("|  X");
            } else if (bingo_board[i][j] < 10) {
                printf("|  %d", bingo_board[i][j]);
            } else {
                printf("| %d", bingo_board[i][j]);
            }
        }
        printf("|\n");
    }
}

// generate all valid bingo numbers
void generate_numbers(int bingo_numbers[RANGE])
{
    for (int i = 0; i < RANGE; i++) {
        bingo_numbers[i] = i+1;
    }

    srand(time(NULL));
    for (int i = 0; i < RANGE; i++) {
        int rand_index = rand() % RANGE;
        int temp = bingo_numbers[i];
        bingo_numbers[i] = bingo_numbers[rand_index];
        bingo_numbers[rand_index] = temp;
    }
}

// draw a new number from the list of valid numbers
int draw_number(int bingo_numbers[RANGE], int used_numbers[RANGE])
{
    int num = -1;
    while (num == -1) {
        int index = rand() % RANGE;
        if (used_numbers[bingo_numbers[index]-1] == 0) {
            num = bingo_numbers[index];
            used_numbers[bingo_numbers[index]-1] = 1;
        }
    }
    return num;
}

// check if there is a winning pattern on the board
int check_win(int bingo_board[ROWS][COLS])
{
    int full_rows = 0;
    int full_cols = 0;
    int full_diags = 0;

    for (int i = 0; i < ROWS; i++) {
        int row_sum = 0;
        int col_sum = 0;

        for (int j = 0; j < COLS; j++) {
            row_sum += bingo_board[i][j];
            col_sum += bingo_board[j][i];
        }

        if (row_sum == -5) full_rows++;
        if (col_sum == -5) full_cols++;
    }

    int diag1_sum = bingo_board[0][0] + bingo_board[1][1] + bingo_board[2][2] + bingo_board[3][3] + bingo_board[4][4];
    int diag2_sum = bingo_board[0][4] + bingo_board[1][3] + bingo_board[2][2] + bingo_board[3][1] + bingo_board[4][0];

    if (diag1_sum == -5 || diag2_sum == -5) full_diags++;

    return full_rows + full_cols + full_diags;
}