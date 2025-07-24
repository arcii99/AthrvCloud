//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number within a given range
int generateRandomNumber(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main() {
    // Initialize Bingo board and arrays to keep track of previously called numbers
    int bingoBoard[5][5] = {0};
    int calledNumbers[75] = {0};
    int currentNumberIndex = 0;

    // Initialize variables for user input and winning conditions
    int userRow, userCol, numBingos = 0;
    char playAgain;

    // Seed the random number generator
    srand(time(NULL));

    // Generate numbers until there are no more positions left on the bingo board
    while (currentNumberIndex < 25) {
        int currentNumber;

        // Generate a new random number and check if it has already been called
        do {
            currentNumber = generateRandomNumber(1, 75);
        } while (calledNumbers[currentNumber - 1] != 0);

        calledNumbers[currentNumber - 1] = 1;

        // Print the current number and pause for dramatic effect
        printf("Number called: %d\n", currentNumber);
        printf("Press ENTER to continue...");
        while (getchar() != '\n');
        system("clear");

        // Loop through the bingo board and mark any cells containing the current number
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (bingoBoard[i][j] == currentNumber) {
                    bingoBoard[i][j] = -1;
                }
            }
        }

        // Print the updated bingo board
        printf("BINGO BOARD\n");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (bingoBoard[i][j] == -1) {
                    printf("X  ");
                } else {
                    printf("%d  ", bingoBoard[i][j]);
                }
            }
            printf("\n");
        }

        // Check for winning conditions
        numBingos = 0;

        // Check for horizontal bingos
        for (int i = 0; i < 5; i++) {
            int sum = 0;
            for (int j = 0; j < 5; j++) {
                sum += (bingoBoard[i][j] == -1 ? 1 : 0);
            }
            if (sum == 5) {
                numBingos++;
            }
        }

        // Check for vertical bingos
        for (int i = 0; i < 5; i++) {
            int sum = 0;
            for (int j = 0; j < 5; j++) {
                sum += (bingoBoard[j][i] == -1 ? 1 : 0);
            }
            if (sum == 5) {
                numBingos++;
            }
        }

        // Check for diagonal bingos
        if ((bingoBoard[0][0] == -1 && bingoBoard[1][1] == -1 && bingoBoard[2][2] == -1 && bingoBoard[3][3] == -1 && bingoBoard[4][4] == -1) || 
            (bingoBoard[4][0] == -1 && bingoBoard[3][1] == -1 && bingoBoard[2][2] == -1 && bingoBoard[1][3] == -1 && bingoBoard[0][4] == -1)) {
                numBingos++;
            }

        // Print number of bingos
        printf("\n\nNumber of bingos: %d\n\n", numBingos);

        // If there are no more positions left on the bingo board, ask user if they want to play again
        if (currentNumberIndex == 24) {
            printf("No more spaces left on the bingo board. Do you want to play again? (y/n)\n");
            scanf(" %c", &playAgain);
            if (playAgain == 'y') {
                // Reset game variables
                currentNumberIndex = 0;
                numBingos = 0;
                for (int i = 0; i < 75; i++) {
                    calledNumbers[i] = 0;
                }
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        bingoBoard[i][j] = 0;
                    }
                }
            } else {
                break;
            }
        } else {
            // Otherwise, ask user to mark a cell on the board
            printf("Enter the row (1-5) and column (1-5) of the cell you want to mark: ");
            scanf("%d %d", &userRow, &userCol);
            while (bingoBoard[userRow - 1][userCol - 1] == -1) {
                printf("\nThat cell has already been marked. Please select another cell: ");
                scanf("%d %d", &userRow, &userCol);
            }
            bingoBoard[userRow - 1][userCol - 1] = currentNumber;
            currentNumberIndex++;
        }

        // Clear input buffer
        while (getchar() != '\n');
    }

    return 0;
}