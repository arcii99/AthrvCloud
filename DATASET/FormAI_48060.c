//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void initialize_board(int board[ROWS][COLS], int center);
void print_board(int board[ROWS][COLS]);
int generate_caller_number(int *used_numbers);
void mark_board(int board[ROWS][COLS], int number);
int check_for_winner(int board[ROWS][COLS]);

int main() {
    int board[ROWS][COLS];
    int used_numbers[75] = {0};
    int center_position = (ROWS * COLS) / 2;
    int total_calls = 0;
    int winner = 0;

    initialize_board(board, center_position);

    while(!winner) {
        int number = generate_caller_number(used_numbers);
        total_calls++;
        printf("The caller called %d.\n", number);
        mark_board(board, number);
        print_board(board);
        winner = check_for_winner(board);
        if(winner) {
            printf("We have a winner! Congratulations!\n");
            break;
        }
        if(total_calls == 75) {
            printf("It's a tie!\n");
            break;
        }
    }

    return 0;
}

void initialize_board(int board[ROWS][COLS], int center) {
    int i, j, k = 1;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(i == center && j == center) {
                board[i][j] = 0;
            } else {
                board[i][j] = k++;
            }
        }
    }
}

void print_board(int board[ROWS][COLS]) {
    int i, j;
    printf("\n  B  I  N  G  O\n\n");

    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%3d", board[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

int generate_caller_number(int *used_numbers) {
    int number;
    srand(time(NULL));
    do {
        number = rand() % 75 + 1;
    } while(used_numbers[number-1]);

    used_numbers[number-1] = 1;
    return number;
}

void mark_board(int board[ROWS][COLS], int number) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(board[i][j] == number) {
                board[i][j] = 0;
            }
        }
    }
}

int check_for_winner(int board[ROWS][COLS]) {
    int i, j, count;

    // check rows
    for(i = 0; i < ROWS; i++) {
        count = 0;
        for(j = 0; j < COLS; j++) {
            if(board[i][j] == 0) {
                count++;
            }
        }
        if(count == ROWS) {
            return 1;
        }
    }

    // check columns
    for(i = 0; i < ROWS; i++) {
        count = 0;
        for(j = 0; j < COLS; j++) {
            if(board[j][i] == 0) {
                count++;
            }
        }
        if(count == COLS) {
            return 1;
        }
    }

    // check diagonals
    if(board[0][0] == 0 && board[1][1] == 0 && board[2][2] == 0 && board[3][3] == 0 && board[4][4] == 0) {
        return 1;
    }

    if(board[0][4] == 0 && board[1][3] == 0 && board[2][2] == 0 && board[3][1] == 0 && board[4][0] == 0) {
        return 1;
    }

    return 0;
}