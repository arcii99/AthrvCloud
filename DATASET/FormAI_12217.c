//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialization
    srand(time(NULL));
    int bingoCard[25] = {};
    int caller[75];
    int remainingNumbers[75];
    int counter = 0;
    int numCalled = 0;
    int gameEnd = 0;

    // Create the Bingo card
    printf("Your Bingo card:\n");
    for (int i = 0; i < 25; i++) {
        int num = (i == 12) ? 0 : (rand() % 75) + 1;
        if (num == 0)
            printf("   ");
        else
            printf("%2d ", num);
        bingoCard[i] = num;
    }
    printf("\n");

    // Create the caller array
    for (int i = 0; i < 75; i++) {
        caller[i] = i + 1;
    }

    // Main game loop
    while (!gameEnd) {
        int index = rand() % (75 - numCalled);
        int num = caller[index];
        caller[index] = caller[74 - numCalled];
        numCalled++;

        printf("Number called: %2d\n", num);

        // Mark number on the Bingo card
        for (int i = 0; i < 25; i++) {
            if (bingoCard[i] == num) {
                bingoCard[i] = 0;
                counter++;
                break;
            }
        }

        // Check for Bingo
        if (counter >= 5) {
            int rowCounter = 0;
            int colCounter = 0;
            int diagCounter1 = 0;
            int diagCounter2 = 0;
            for (int i = 0; i < 5; i++) {
                rowCounter = 0;
                colCounter = 0;
                for (int j = 0; j < 5; j++) {
                    rowCounter += bingoCard[i * 5 + j];
                    colCounter += bingoCard[j * 5 + i];
                    if (i == j)
                        diagCounter1 += bingoCard[i * 5 + j];
                    if (i == 4 - j)
                        diagCounter2 += bingoCard[i * 5 + j];
                }
                if (rowCounter == 0 || colCounter == 0)
                    gameEnd = 1;
            }
            if (diagCounter1 == 0 || diagCounter2 == 0)
                gameEnd = 1;

            if (gameEnd)
                printf("BINGO!\n");
        }
    }

    printf("Final Bingo card:\n");
    for (int i = 0; i < 25; i++) {
        if (bingoCard[i] == 0)
            printf("   ");
        else
            printf("%2d ", bingoCard[i]);
        if (i % 5 == 4)
            printf("\n");
    }

    return 0;
}