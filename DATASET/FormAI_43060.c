//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(int (*board)[5]);
void update_board(int (*board)[5], int num);
int check_win(int (*board)[5]);

int main() {
    printf("Welcome to the Bingo game, where fate decides your fortune.\n");

    int board[5][5] = {0};
    int num, turns = 0;

    srand(time(NULL));
    while (turns < 25) {
        printf("The next number is... ");
        num = rand() % 75 + 1;
        printf("%d!\n", num);

        update_board(board, num);
        print_board(board);

        if (check_win(board)) {
            printf("BINGO! It seems that fate has chosen you as its lucky winner.\n");
            break;
        }

        turns++;
    }

    if (turns == 25) {
        printf("Alas, it seems that fate was not on your side today. Better luck next time, brave player.\n");
    }

    return 0;
}

void print_board(int (*board)[5]) {
    printf("  1 2 3 4 5\n");
    for (int i = 0; i < 5; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < 5; j++) {
            if (board[i][j]) {
                printf("* ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

void update_board(int (*board)[5], int num) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == num) {
                board[i][j] = -1; // mark as drawn
            }
        }
    }
}

int check_win(int (*board)[5]) {
    int count = 0;
    // check rows
    for (int i = 0; i < 5; i++) {
        count = 0;
        for (int j = 0; j < 5; j++) {
            count += board[i][j];
        }
        if (count == -5) {
            return 1; // bingo
        }
    }
    // check columns
    for (int j = 0; j < 5; j++) {
        count = 0;
        for (int i = 0; i < 5; i++) {
            count += board[i][j];
        }
        if (count == -5) {
            return 1; // bingo
        }
    }
    // check diagonal
    count = 0;
    for (int i = 0; i < 5; i++) {
        count += board[i][i];
    }
    if (count == -5) {
        return 1; // bingo
    }
    // check other diagonal
    count = 0;
    for (int i = 0; i < 5; i++) {
        count += board[i][4 - i];
    }
    if (count == -5) {
        return 1; // bingo
    }
    return 0; // no bingo yet
}