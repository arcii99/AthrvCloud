//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define BINGO_COUNT 5

int main() {
    srand(time(NULL)); // Initializing random number generator

    int bingoCard[ROWS][COLS];
    int numUsed[ROWS * COLS]; // To keep track of already used numbers
    int numSequence[BINGO_COUNT * 2]; // To keep track of bingo sequence

    printf("Welcome to the Bingo Simulator!\n");

    // Initializing the Bingo Card
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == ROWS / 2 && j == COLS / 2) { // Free space in the center
                bingoCard[i][j] = 0;
            } else {
                int num = 0;
                do {
                    num = rand() % (COLS * ROWS) + 1;
                } while (numUsed[num - 1]);
                bingoCard[i][j] = num;
                numUsed[num - 1] = 1;
            }
        }
    }

    // Printing the Bingo Card
    printf("Your Bingo Card:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", bingoCard[i][j]);
        }
        printf("\n");
    }

    // Generating the Bingo Sequence
    for (int i = 0; i < BINGO_COUNT; i++) {
        numSequence[i] = rand() % ROWS; // Row number
        numSequence[i + BINGO_COUNT] = rand() % COLS; // Column number
    }

    // Game Loop
    printf("\nGame Starting...\n");
    int numCalled = 0;
    do {
        numCalled++;
        int num = 0;
        do {
            num = rand() % (COLS * ROWS) + 1;
        } while (numUsed[num - 1]);
        numUsed[num - 1] = 1;
        printf("Number Called: %d\n", num);

        // Check if the number is on the Bingo Card
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (bingoCard[i][j] == num) {
                    bingoCard[i][j] = 0; // Mark as used
                    printf("Number Found at Row: %d, Column: %d\n", i+1, j+1);

                    // Check if Bingo Sequence is completed
                    int seqFound = 1;
                    for (int k = 0; k < BINGO_COUNT; k++) {
                        if (bingoCard[numSequence[k]][numSequence[k+BINGO_COUNT]] != 0) {
                            seqFound = 0;
                            break;
                        }
                    }
                    if (seqFound) {
                        printf("Bingo!\n");
                        return 0;
                    }
                }
            }
        }
    } while (numCalled < ROWS * COLS);

    printf("Game Over - No Bingo Found\n");
    return 0;
}