//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main()
{
    int i, j, count, num, wins;
    int card[ROWS][COLS];
    int sim_card[ROWS][COLS];
    wins = 0;

    srand(time(NULL));

    printf("Welcome to Bingo Simulator!\n");

    // Generate a random Bingo card
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 2 && j == 2) { // Center of card is free space
                card[i][j] = 0;
            } else {
                num = rand() % 15 + 1 + j * 15;
                card[i][j] = num;
                for (count = 0; count < j; count++) {
                    if (card[i][count] == num) {
                        j--;
                        break;
                    }
                }
            }
        }
    }

    // Print the Bingo card
    printf("\nYour Bingo card:\n\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%3d ", card[i][j]);
        }
        printf("\n");
    }

    // Simulate 10 games
    printf("\nLet's play 10 games!\n");
    for (count = 1; count <= 10; count++) {
        printf("\nGame #%d:\n", count);

        // Generate a random Bingo ball and check for matches
        num = rand() % 75 + 1;
        printf("The Bingo ball is: %d\n", num);
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (card[i][j] == num) {
                    sim_card[i][j] = 0;
                } else {
                    sim_card[i][j] = card[i][j];
                }
            }
            if (sim_card[i][0] == 0
                && sim_card[i][1] == 0
                && sim_card[i][2] == 0
                && sim_card[i][3] == 0
                && sim_card[i][4] == 0) {
                printf("BINGO! You won on row %d!\n", i + 1);
                wins++;
                break;
            }
        }

        // Print the simulated Bingo card
        printf("\nSimulated Bingo card:\n\n");
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                printf("%3d ", sim_card[i][j]);
            }
            printf("\n");
        }
    }

    // Print the final results
    printf("\nCongratulations! You won %d out of 10 games!\n", wins);

    return 0;
}