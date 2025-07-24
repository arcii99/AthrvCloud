//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void generateCard(int card[ROWS][COLS]) {
    int num;

    // First column numbers (1-15)
    for (int i = 0; i < ROWS; i++) {
        num = (rand() % 15) + 1;
        card[i][0] = num;
    }

    // Second column numbers (16-30)
    for (int i = 0; i < ROWS; i++) {
        num = (rand() % 15) + 16;
        card[i][1] = num;
    }

    // Third column numbers (31-45)
    for (int i = 0; i < ROWS; i++) {
        num = (rand() % 15) + 31;
        card[i][2] = num;
    }

    // Fourth column numbers (46-60)
    for (int i = 0; i < ROWS; i++) {
        num = (rand() % 15) + 46;
        card[i][3] = num;
    }

    // Fifth column numbers (61-75)
    for (int i = 0; i < ROWS; i++) {
        num = (rand() % 15) + 61;
        card[i][4] = num;
    }

}

void printCard(int card[ROWS][COLS]) {
    printf(" B  I  N  G  O\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] < 10) {
                printf(" %d ", card[i][j]);
            }
            else {
                printf("%d ", card[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int card[ROWS][COLS];
    int callNums[75] = { 0 }; // Array to keep track of called numbers
    int num, numCalls = 0;
    char choice;

    srand(time(NULL)); // Seed for random number generator

    generateCard(card); // Generate Bingo card
    printCard(card); // Print Bingo card

    // Keep looping until Bingo is called or user chooses to quit
    do {
        printf("Press enter to call next number\n");
        getchar(); // Wait for user to press enter
        system("clear"); // Clear screen

        // Generate random number between 1-75 and check if already called
        do {
            num = (rand() % 75) + 1;
        } while (callNums[num - 1] != 0);

        callNums[num - 1] = 1; // Mark as called
        numCalls++; // Increment number of calls

        // Print called number
        printf("The number is: %d\n\n", num);

        // Loop through card to check for called number
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (card[i][j] == num) {
                    card[i][j] = 0; // Mark as found on card
                }
            }
        }

        // Print updated Bingo card
        printCard(card);

        // Check if Bingo has been called
        if (numCalls >= 5) {
            // Check rows
            for (int i = 0; i < ROWS; i++) {
                if (card[i][0] == 0 && card[i][1] == 0 && card[i][2] == 0 && card[i][3] == 0 && card[i][4] == 0) {
                    printf("BINGO! You got a row!\n");
                    printf("Press y to play again or any other key to quit.\n");
                    scanf(" %c", &choice);
                    if (choice == 'y') {
                        generateCard(card);
                        printCard(card);
                        numCalls = 0;
                        for (int i = 0; i < 75; i++) {
                            callNums[i] = 0;
                        }
                        break;
                    }
                    else {
                        printf("Thanks for playing!\n");
                        exit(0);
                    }
                }
            }

            // Check columns
            for (int i = 0; i < COLS; i++) {
                if (card[0][i] == 0 && card[1][i] == 0 && card[2][i] == 0 && card[3][i] == 0 && card[4][i] == 0) {
                    printf("BINGO! You got a column!\n");
                    printf("Press y to play again or any other key to quit.\n");
                    scanf(" %c", &choice);
                    if (choice == 'y') {
                        generateCard(card);
                        printCard(card);
                        numCalls = 0;
                        for (int i = 0; i < 75; i++) {
                            callNums[i] = 0;
                        }
                        break;
                    }
                    else {
                        printf("Thanks for playing!\n");
                        exit(0);
                    }
                }
            }

            // Check diagonals
            if (card[0][0] == 0 && card[1][1] == 0 && card[2][2] == 0 && card[3][3] == 0 && card[4][4] == 0) {
                printf("BINGO! You got a diagonal!\n");
                printf("Press y to play again or any other key to quit.\n");
                scanf(" %c", &choice);
                if (choice == 'y') {
                    generateCard(card);
                    printCard(card);
                    numCalls = 0;
                    for (int i = 0; i < 75; i++) {
                        callNums[i] = 0;
                    }
                    break;
                }
                else {
                    printf("Thanks for playing!\n");
                    exit(0);
                }
            }

            if (card[0][4] == 0 && card[1][3] == 0 && card[2][2] == 0 && card[3][1] == 0 && card[4][0] == 0) {
                printf("BINGO! You got a diagonal!\n");
                printf("Press y to play again or any other key to quit.\n");
                scanf(" %c", &choice);
                if (choice == 'y') {
                    generateCard(card);
                    printCard(card);
                    numCalls = 0;
                    for (int i = 0; i < 75; i++) {
                        callNums[i] = 0;
                    }
                    break;
                }
                else {
                    printf("Thanks for playing!\n");
                    exit(0);
                }
            }
        }

    } while (numCalls < 75);

    printf("It's a tie! No one won.\n");

    return 0;
}