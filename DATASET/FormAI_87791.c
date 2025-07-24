//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {
    int bingo[ROWS][COLS] = {0};
    int random_num;
    int numbers_drawn = 0;
    int winner = 0;

    srand(time(NULL));

    // generate random numbers and fill the bingo grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            random_num = rand() % 75 + 1;
            // check for duplicates
            for (int k = 0; k < j; k++) {
                if (random_num == bingo[i][k]) {
                    j--;
                    break;
                }
            }
            bingo[i][j] = random_num;
        }
    }

    // print the bingo grid
    printf("\nBINGO CARD\n\n");
    printf(" B  I  N  G  O\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (bingo[i][j] == 0) {
                printf("   ");
            } else {
                printf("%2d ", bingo[i][j]);
            }
        }
        printf("\n");
    }

    // start the game
    printf("\nLet's play BINGO!\n\n");
    while (!winner) {
        numbers_drawn++;
        random_num = rand() % 75 + 1;
        // check for duplicates
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (random_num == bingo[i][j]) {
                    bingo[i][j] = 0;
                    break;
                }
            }
        }
        printf("Number drawn: %d\n", random_num);

        // check for horizontal bingo
        for (int i = 0; i < ROWS; i++) {
            int count = 0;
            for (int j = 0; j < COLS; j++) {
                if (bingo[i][j] == 0) {
                    count++;
                }
            }
            if (count == COLS) {
                winner = 1;
                printf("You have a horizontal bingo!\n");
                break;
            }
        }

        // check for vertical bingo
        for (int i = 0; i < COLS; i++) {
            int count = 0;
            for (int j = 0; j < ROWS; j++) {
                if (bingo[j][i] == 0) {
                    count++;
                }
            }
            if (count == ROWS) {
                winner = 1;
                printf("You have a vertical bingo!\n");
                break;
            }
        }

        // check for diagonal bingo
        int count = 0;
        for (int i = 0; i < ROWS; i++) {
            if (bingo[i][i] == 0) {
                count++;
            }
        }
        if (count == ROWS) {
            winner = 1;
            printf("You have a diagonal bingo!\n");
            break;
        }

        count = 0;
        for (int i = 0; i < ROWS; i++) {
            if (bingo[i][COLS-1-i] == 0) {
                count++;
            }
        }
        if (count == ROWS) {
            winner = 1;
            printf("You have a diagonal bingo!\n");
            break;
        }
    }

    printf("\nCongratulations! You won after %d numbers drawn!\n", numbers_drawn);

    return 0;
}