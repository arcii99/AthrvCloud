//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define EMPTY 0

void print_board(int board[][COLS]);
int check_win(int board[][COLS]);
int generate_number(int board[][COLS], int num);
int mark_board(int board[][COLS], int num);

int main() {
    int board[ROWS][COLS] = {0};
    int num = 0, turns = 0, winner = 0;

    // seed random number generator
    srand(time(NULL));

    printf("Welcome to Bingo Simulator\n");

    while (winner == 0 && turns < 25) {
        // generate random number
        num = generate_number(board, num);

        // mark the number on the board
        mark_board(board, num);

        // print the board
        print_board(board);

        // check for a winner
        winner = check_win(board);

        turns++;
    }

    // print the final board
    printf("Final Board:\n");
    print_board(board);

    // print the winner or tie
    if (winner == 1) {
        printf("BINGO! You won in %d turns\n", turns);
    } else {
        printf("Tie game! Nobody won\n");
    }

    return 0;
}

/**
 * Prints the current state of the board
 */
void print_board(int board[][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == EMPTY) {
                printf(" - ");
            } else {
                printf("%2d ", board[i][j]);
            } 
        }
        printf("\n");
    }
}

/**
 * Checks the current state of the board for a winning sequence
 */
int check_win(int board[][COLS]) {
    int win = 0;

    // check rows for win
    for (int i = 0; i < ROWS; i++) {
        int count = 0;
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] != EMPTY) {
                count++;
            }
        }
        if (count == COLS) {
            win = 1;
        }
    }

    // check columns for win
    for (int j = 0; j < COLS; j++) {
        int count = 0;
        for (int i = 0; i < ROWS; i++) {
            if (board[i][j] != EMPTY) {
                count++;
            }
        }
        if (count == ROWS) {
            win = 1;
        }
    }

    // check diagonals for win
    if (board[0][0] != EMPTY && board[1][1] != EMPTY && board[2][2] != EMPTY && board[3][3] != EMPTY && board[4][4] != EMPTY) {
        win = 1;
    }
    if (board[0][4] != EMPTY && board[1][3] != EMPTY && board[2][2] != EMPTY && board[3][1] != EMPTY && board[4][0] != EMPTY) {
        win = 1;
    }

    return win;
}

/**
 * Generates a random number between 1 and 25 that has not been generated before
 */
int generate_number(int board[][COLS], int num) {
    int unique = 0;
    num = rand() % 25 + 1;

    while (unique == 0) {
        unique = 1;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == num) {
                    unique = 0;
                    num = rand() % 25 + 1;
                }
            }
        }
    }

    return num;
}

/**
 * Marks the board with the generated number
 */
int mark_board(int board[][COLS], int num) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == num) {
                board[i][j] = EMPTY;
            }
        }
    }
}