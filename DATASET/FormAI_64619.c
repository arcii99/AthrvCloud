//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void print_board(int board[ROWS][COLS]) {
    printf("-----------------\n");
    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLS; j++) {
            printf(" %d |", board[i][j]);
        }
        printf("\n-----------------\n");
    }
}

void generate_numbers(int board[ROWS][COLS]) {
    int numbers[75], n = 0;
    for (int i = 0; i < 75; i++) {
        numbers[i] = i+1;
    }

    // shuffle the array
    srand(time(NULL));
    for (int i = 0; i < 75 - 1; i++) {
        int j = rand() % (75-i) + i;
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // fill the board with shuffled numbers
    n = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = numbers[n];
            n++;
        }
    }
}

int check_bingo(int board[ROWS][COLS]) {
    // check rows
    for (int i = 0; i < ROWS; i++) {
        int count = 0;
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                count++;
            }
        }

        if (count == ROWS) {
            return 1; // bingo
        }
    }

    // check columns
    for (int i = 0; i < COLS; i++) {
        int count = 0;
        for (int j = 0; j < ROWS; j++) {
            if (board[j][i] == -1) {
                count++;
            }
        }

        if (count == COLS) {
            return 1; // bingo
        }
    }

    // check diagonals
    if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) {
        return 1; // bingo
    }

    if (board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1) {
        return 1; // bingo
    }

    return 0; // no bingo
}

void play_game(int board[ROWS][COLS]) {
    int numbers_called[75] = {0};
    int turn = 1;

    while (1) {
        printf("Calling number #%d...\n", turn);
        int number = rand() % 75 + 1;

        // check if number has already been called
        if (numbers_called[number-1] == 1) {
            printf("%d has already been called.\n", number);
            continue;
        }

        // mark number on the board
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == number) {
                    board[i][j] = -1;
                }
            }
        }

        numbers_called[number-1] = 1;

        print_board(board);

        if (check_bingo(board)) {
            printf("BINGO!\n");
            break;
        }

        turn++;
    }
}

int main() {
    int board[ROWS][COLS];
    generate_numbers(board);
    printf("--- Welcome to Bingo! ---\n");
    printf("Press any key to play...\n");
    getchar();
    play_game(board);
    return 0;
}