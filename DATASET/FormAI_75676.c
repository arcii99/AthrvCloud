//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Claude Shannon
// Welcome to the Bingo Simulator!

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initializing variables
    int calls[75];
    bool card[5][5] = {false};
    int num_calls = 0;
    bool bingo = false;

    // Generating random numbers for the calls array
    srand(time(NULL));
    for (int i = 0; i < 75; i++) {
        calls[i] = rand() % 75 + 1;
    }

    // Game starts here
    printf("Welcome to Bingo Simulator!\n");

    while (!bingo) {
        int call = calls[num_calls];

        // Printing the call
        printf("The call is: %d\n", call);

        // Marking the cell as called in the card
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (card[i][j] && (i * 15 + j + 1) == call) {
                    card[i][j] = false;
                } else if (!card[i][j] && (i * 15 + j + 1) == call) {
                    card[i][j] = true;
                }
            }
        }

        // Checking for bingo
        for (int i = 0; i < 5; i++) {
            // Checking for horizontal line
            if (card[i][0] && card[i][1] && card[i][2] && card[i][3] && card[i][4]) {
                printf("Bingo! You have a horizontal line on row %d.\n", i+1);
                bingo = true;
                break;
            }
            // Checking for vertical line
            if (card[0][i] && card[1][i] && card[2][i] && card[3][i] && card[4][i]) {
                printf("Bingo! You have a vertical line on column %d.\n", i+1);
                bingo = true;
                break;
            }
        }

        // Checking for diagonal lines
        if (card[0][0] && card[1][1] && card[2][2] && card[3][3] && card[4][4]) {
            printf("Bingo! You have a diagonal line from top left to bottom right.\n");
            bingo = true;
        }
        if (card[4][0] && card[3][1] && card[2][2] && card[1][3] && card[0][4]) {
            printf("Bingo! You have a diagonal line from bottom left to top right.\n");
            bingo = true;
        }

        // Incrementing the number of calls
        num_calls++;

        // End condition
        if (num_calls == 75 && !bingo) {
            printf("Game over! No winner this time.\n");
            break;
        }

        // Prompting user for next call
        printf("Press any key to continue.\n");
        getchar();
     }

    return 0;
}