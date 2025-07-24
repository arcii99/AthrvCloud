//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to check for a winner */
int check_winner(int board[][5]) {
    int i, j, count;

    /* Check rows */
    for (i = 0; i < 5; i++) {
        count = 0;
        for (j = 0; j < 5; j++) {
            if (board[i][j] == 1) {
                count++;
            }
        }
        if (count == 5) {
            return 1;
        }
    }

    /* Check columns */
    for (i = 0; i < 5; i++) {
        count = 0;
        for (j = 0; j < 5; j++) {
            if (board[j][i] == 1) {
                count++;
            }
        }
        if (count == 5) {
            return 1;
        }
    }

    /* Check diagonal */
    if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1 && board[3][3] == 1 && board[4][4] == 1) {
        return 1;
    }
    if (board[0][4] == 1 && board[1][3] == 1 && board[2][2] == 1 && board[3][1] == 1 && board[4][0] == 1) {
        return 1;
    }

    /* No winner yet */
    return 0;
}

int main() {
    int i, j, num, winner;
    int board[5][5] = {0};
    int bingo_nums[75] = {0};

    /* Initialize random seed */
    srand(time(NULL));

    /* Generate all valid Bingo numbers */
    for (i = 0; i < 75; i++) {
        bingo_nums[i] = i + 1;
    }

    /* Shuffle the numbers */
    for (i = 0; i < 75; i++) {
        j = rand() % 75;
        num = bingo_nums[i];
        bingo_nums[i] = bingo_nums[j];
        bingo_nums[j] = num;
    }

    /* Play Bingo */
    printf("Welcome to the Bingo simulator!\n");
    printf("Get your cards ready and let's begin!\n\n");

    while (!winner) {
        /* Call out a number */
        num = bingo_nums[i];

        /* Mark the number on the board */
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (num == board[i][j]) {
                    board[i][j] = 1;
                    printf("Number called: %d\n\n", num);
                }
            }
        }

        /* Check for a winner */
        winner = check_winner(board);

        /* Increment counter */
        i++;

        /* End the game if all numbers are called */
        if (i == 75) {
            break;
        }
    }

    /* Display winner */
    if (winner) {
        printf("Bingo! You have a winner!\n");
    } else {
        printf("Sorry, no winner this time. Better luck next time!\n");
    }

    return 0;
}