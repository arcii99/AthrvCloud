//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int card[5][5];
    int nums[75];
    int count = 0;

    srand(time(NULL));

    // initialize card array to 0s
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card[i][j] = 0;
        }
    }

    // generate random list of numbers to call
    for (int i = 0; i < 75; i++) {
        nums[i] = i + 1;
    }
    for (int i = 0; i < 74; i++) {
        int j = rand() % (75-i) + i;
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // print header
    printf("B  I  N  G  O\n");

    // print initial card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%02d ", card[i][j]);
        }
        printf("\n");
    }

    // loop through calls until there is a winner
    while (1) {
        int next_num = nums[count];
        printf("Next call: %d\n", next_num);

        // mark called number on card if present
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (card[i][j] == next_num) {
                    card[i][j] = -1;
                }
            }
        }

        // print updated card
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%02d ", card[i][j]);
            }
            printf("\n");
        }

        // check for a winner
        int winner_found = 0;

        // check rows
        for (int i = 0; i < 5; i++) {
            int row_sum = 0;
            for (int j = 0; j < 5; j++) {
                row_sum += card[i][j];
            }
            if (row_sum == -5) {
                printf("*** WINNER FOUND! ***\n");
                winner_found = 1;
                break;
            }
        }
        if (winner_found) break;

        // check columns
        for (int i = 0; i < 5; i++) {
            int col_sum = 0;
            for (int j = 0; j < 5; j++) {
                col_sum += card[j][i];
            }
            if (col_sum == -5) {
                printf("*** WINNER FOUND! ***\n");
                winner_found = 1;
                break;
            }
        }
        if (winner_found) break;

        // check diagonals
        if (card[0][0] == -1 && card[1][1] == -1 && card[2][2] == -1 && card[3][3] == -1 && card[4][4] == -1) {
            printf("*** WINNER FOUND! ***\n");
            winner_found = 1;
        }
        else if (card[0][4] == -1 && card[1][3] == -1 && card[2][2] == -1 && card[3][1] == -1 && card[4][0] == -1) {
            printf("*** WINNER FOUND! ***\n");
            winner_found = 1;
        }
        if (winner_found) break;

        // get input from user to continue
        printf("Press any key to continue...");
        getchar();

        count++;
    }

    return 0;
}