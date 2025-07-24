//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // initialize random seed

    int card[5][5] = {0}; // bingo card
    int called[75] = {0}; // numbers that have been called
    int count = 0; // count of numbers called
    int row, col; // user input for row and column
    int bingo = 0; // flag for bingo

    // generate bingo card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 && j == 2) // center free space
                continue;
            card[i][j] = rand() % 15 + (j * 15) + 1;
        }
    }

    // display bingo card
    printf("BINGO CARD:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%2d ", card[i][j]);
        }
        printf("\n");
    }

    // game loop
    while (!bingo) {
        int number = rand() % 75 + 1; // generate random number

        // check if number has already been called
        if (!called[number-1]) {
            called[number-1] = 1;
            count++;

            // display called number
            printf("Called number: %d\n", number);

            // check if number is on card
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (card[i][j] == number) {
                        card[i][j] = 0;
                        printf("You have marked off %d on your card\n", number);
                    }
                }
            }

            // check for bingo
            // horizontal
            for (int i = 0; i < 5; i++) {
                if (card[i][0] == 0 && card[i][1] == 0 && card[i][2] == 0 && card[i][3] == 0 && card[i][4] == 0) {
                    bingo = 1;
                    printf("BINGO! You have won!\n");
                }
            }
            // vertical
            for (int j = 0; j < 5; j++) {
                if (card[0][j] == 0 && card[1][j] == 0 && card[2][j] == 0 && card[3][j] == 0 && card[4][j] == 0) {
                    bingo = 1;
                    printf("BINGO! You have won!\n");
                }
            }
            // diagonal
            if (card[0][0] == 0 && card[1][1] == 0 && card[2][2] == 0 && card[3][3] == 0 && card[4][4] == 0) {
                bingo = 1;
                printf("BINGO! You have won!\n");
            }
            if (card[0][4] == 0 && card[1][3] == 0 && card[2][2] == 0 && card[3][1] == 0 && card[4][0] == 0) {
                bingo = 1;
                printf("BINGO! You have won!\n");
            }
        }

        // check if all numbers have been called
        if (count == 75) {
            printf("All numbers have been called. Game over.\n");
            break;
        }

        // ask user to mark off number on their card
        printf("Mark off number on your card (row col): ");
        scanf("%d %d", &row, &col);
        if (card[row-1][col-1] == 0) {
            printf("That number has already been marked off. Try again.\n");
        } else {
            card[row-1][col-1] = 0;
        }

        // check for bingo after user marks off number
        // horizontal
        for (int i = 0; i < 5; i++) {
            if (card[i][0] == 0 && card[i][1] == 0 && card[i][2] == 0 && card[i][3] == 0 && card[i][4] == 0) {
                bingo = 1;
                printf("BINGO! You have won!\n");
            }
        }
        // vertical
        for (int j = 0; j < 5; j++) {
            if (card[0][j] == 0 && card[1][j] == 0 && card[2][j] == 0 && card[3][j] == 0 && card[4][j] == 0) {
                bingo = 1;
                printf("BINGO! You have won!\n");
            }
        }
        // diagonal
        if (card[0][0] == 0 && card[1][1] == 0 && card[2][2] == 0 && card[3][3] == 0 && card[4][4] == 0) {
            bingo = 1;
            printf("BINGO! You have won!\n");
        }
        if (card[0][4] == 0 && card[1][3] == 0 && card[2][2] == 0 && card[3][1] == 0 && card[4][0] == 0) {
            bingo = 1;
            printf("BINGO! You have won!\n");
        }
    }

    return 0;
}