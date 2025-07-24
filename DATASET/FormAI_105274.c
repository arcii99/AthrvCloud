//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

/* Takes in a bingo card and prints it out */
void printCard(int card[ROWS][COLS]) {
    printf("B\tI\tN\tG\tO\n");
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (card[row][col] != -1) {
                printf("%d\t", card[row][col]);
            } else {
                printf("X\t");
            }
        }
        printf("\n");
    }
}

/* Initializes the bingo card with random numbers */
void initializeCard(int card[ROWS][COLS]) {
    srand(time(NULL));
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            card[row][col] = -1;
        }
    }
    for (int col = 0; col < COLS; col++) {
        int nums[15];
        for (int i = 0; i < 15; i++) {
            nums[i] = (col * 15) + i + 1;
        }
        for (int row = 0; row < ROWS; row++) {
            int index = rand() % (15 - row);
            card[row][col] = nums[index];
            nums[index] = nums[14 - row];
        }
    }
}

/* Checks if a player has bingo */
int hasBingo(int card[ROWS][COLS]) {
    int rowBingo = 0;
    int colBingo = 0;
    int diagBingo = 0;

    // Check for row bingo
    for (int row = 0; row < ROWS; row++) {
        int count = 0;
        for (int col = 0; col < COLS; col++) {
            if (card[row][col] == -1) {
                count++;
            }
        }
        if (count == COLS) {
            rowBingo = 1;
            break;
        }
    }

    // Check for column bingo
    for (int col = 0; col < COLS; col++) {
        int count = 0;
        for (int row = 0; row < ROWS; row++) {
            if (card[row][col] == -1) {
                count++;
            }
        }
        if (count == ROWS) {
            colBingo = 1;
            break;
        }
    }

    // Check for diagonal bingo
    if (card[0][0] == -1 && card[1][1] == -1 && card[2][2] == -1 && card[3][3] == -1 && card[4][4] == -1) {
        diagBingo = 1;
    }
    if (card[0][4] == -1 && card[1][3] == -1 && card[2][2] == -1 && card[3][1] == -1 && card[4][0] == -1) {
        diagBingo = 1;
    }

    return rowBingo || colBingo || diagBingo;
}

/* Main function */
int main() {
    // Initialize player and computer cards
    int playerCard[ROWS][COLS];
    int computerCard[ROWS][COLS];
    initializeCard(playerCard);
    initializeCard(computerCard);

    // Print out the player card
    printf("Here is your bingo card:\n");
    printCard(playerCard);

    // Keep track of which numbers have been called
    int numbersCalled[75];
    for (int i = 0; i < 75; i++) {
        numbersCalled[i] = 0;
    }

    // Play the game
    int turn = 0;
    while (1) {
        // Player's turn
        if (turn % 2 == 0) {
            // Get input from the player
            int input;
            printf("Enter a number between 1 and 75: ");
            scanf("%d", &input);
            if (input < 1 || input > 75) {
                printf("Invalid input, please enter a number between 1 and 75.\n");
                continue;
            }
            if (numbersCalled[input-1]) {
                printf("That number has already been called, please enter a different number.\n");
                continue;
            }

            // Check if the player has that number on their card
            int found = 0;
            for (int row = 0; row < ROWS; row++) {
                for (int col = 0; col < COLS; col++) {
                    if (playerCard[row][col] == input) {
                        playerCard[row][col] = -1;
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }

            if (!found) {
                printf("That number is not on your card.\n");
                continue;
            }

            numbersCalled[input-1] = 1;
            printf("You called %d.\n", input);
            printCard(playerCard);

            if (hasBingo(playerCard)) {
                printf("Congratulations, you win!\n");
                break;
            }
        }

        // Computer's turn
        else {
            // Pick a random number between 1 and 75
            int input;
            do {
                input = rand() % 75 + 1;
            } while (numbersCalled[input-1]);

            // Check if the computer has that number on their card
            int found = 0;
            for (int row = 0; row < ROWS; row++) {
                for (int col = 0; col < COLS; col++) {
                    if (computerCard[row][col] == input) {
                        computerCard[row][col] = -1;
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }

            numbersCalled[input-1] = 1;
            printf("The computer called %d.\n", input);
            printCard(playerCard);

            if (hasBingo(computerCard)) {
                printf("Oh no, the computer won!\n");
                break;
            }
        }

        turn++;
    }

    return 0;
}