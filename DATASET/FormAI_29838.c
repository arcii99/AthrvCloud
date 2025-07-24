//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {
    // initialize game variables
    int board[ROWS][COLS];
    int drawn_numbers[75] = { 0 };
    int num_drawn = 0;

    // fill the board with random numbers
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int num = rand() % 15 + 1 + j * 15;
            board[i][j] = num;
        }
    }

    // game loop
    while (num_drawn < 75) {
        // show the board
        printf("   B   I   N   G   O\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 0) {
                    printf("  XX");
                } else {
                    printf(" %2d ", board[i][j]);
                }
            }
            printf("\n");
        }

        // draw a number
        int num = rand() % 75 + 1;
        while (drawn_numbers[num - 1]) {
            num = rand() % 75 + 1;
        }
        drawn_numbers[num - 1] = 1;
        num_drawn++;

        // check if the number is on the board and mark it if it is
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == num) {
                    board[i][j] = 0;
                }
            }
        }
    }

    // display the final board and end the game
    printf("   B   I   N   G   O\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                printf("  XX");
            } else {
                printf(" %2d ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("Bingo! You got it!\n");

   return 0;
}