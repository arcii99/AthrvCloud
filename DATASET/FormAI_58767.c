//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the randomizer
    int bingo[5][5]; // declare the 5x5 bingo board

    // fill the board with random numbers
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // generate number between 1 and 75
            bingo[i][j] = rand() % 75 + 1;
        }
    }

    printf("Welcome to Bingo Simulator!\n");

    // keep track of which numbers have already been called
    int called[75] = { 0 };

    // play the game until someone wins
    while (1) {
        printf("Press enter to call a number...");
        getchar(); // wait for user to press enter

        // call a random number
        int num;
        do {
            num = rand() % 75 + 1;
        } while (called[num - 1]);
        called[num - 1] = 1;
        printf("The next number is: %d\n", num);

        // check if any players have won
        int win = 0;
        for (int i = 0; i < 5; i++) {
            // check rows
            if (bingo[i][0] == num && bingo[i][1] == num && bingo[i][2] == num && bingo[i][3] == num && bingo[i][4] == num) {
                printf("Row %d wins!\n", i + 1);
                win = 1;
                break;
            }
            // check columns
            if (bingo[0][i] == num && bingo[1][i] == num && bingo[2][i] == num && bingo[3][i] == num && bingo[4][i] == num) {
                printf("Column %d wins!\n", i + 1);
                win = 1;
                break;
            }
            // check diagonals
            if (bingo[0][0] == num && bingo[1][1] == num && bingo[2][2] == num && bingo[3][3] == num && bingo[4][4] == num) {
                printf("Diagonal (top-left to bottom-right) wins!\n");
                win = 1;
                break;
            }
            if (bingo[0][4] == num && bingo[1][3] == num && bingo[2][2] == num && bingo[3][1] == num && bingo[4][0] == num) {
                printf("Diagonal (top-right to bottom-left) wins!\n");
                win = 1;
                break;
            }
        }

        if (win) {
            break; // end the game
        }

        // print the updated board
        printf("\nBingo Board:\n");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (bingo[i][j] == num) {
                    printf("* "); // mark the called number with an asterisk
                } else {
                    printf("%d ", bingo[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    printf("Game over!\n");

    return 0;
}