//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of rows and columns in the bingo card
#define ROWS 5
#define COLUMNS 5

// Function to generate random numbers
int generateRandomNumber(int upperLimit) {
    int randomNumber;
    randomNumber = rand() % upperLimit + 1;
    return randomNumber;
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    // Declare variables
    int bingoCard[ROWS][COLUMNS] = {0};
    int randomNumber;
    int calledNumbers[99] = {0};
    int calledNumbersCounter = 0;

    // Generate the bingo card
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            randomNumber = generateRandomNumber(99);
            bingoCard[i][j] = randomNumber;
        }
    }

    // Display the bingo card
    printf("Welcome to the Bingo Simulator!\n");
    printf("Here is your Bingo card:\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            printf("%d\t", bingoCard[i][j]);
        }
        printf("\n");
    }

    // Start calling numbers
    printf("\nLet's start calling numbers!\n");
    int gameOver = 0;
    do {
        randomNumber = generateRandomNumber(99);
        for(int i = 0; i < calledNumbersCounter; i++) {
            if(randomNumber == calledNumbers[i]) {
                randomNumber = -1; // Number has already been called
                break;
            }
        }
        if(randomNumber != -1) {
            calledNumbers[calledNumbersCounter] = randomNumber;
            calledNumbersCounter++;
            printf("Calling number %d!\n", randomNumber);
            // Check if number is on the card
            for(int i = 0; i < ROWS; i++) {
                for(int j = 0; j < COLUMNS; j++) {
                    if(bingoCard[i][j] == randomNumber) {
                        bingoCard[i][j] = 0; // Mark number as called on the card
                        printf("Number %d is on your card!\n", randomNumber);
                        // Check if there is a bingo
                        int bingo = 1;
                        // Check rows
                        for(int k = 0; k < ROWS; k++) {
                            int rowBingo = 1;
                            for(int l = 0; l < COLUMNS; l++) {
                                if(bingoCard[k][l] != 0) {
                                    rowBingo = 0;
                                    break;
                                }
                            }
                            if(rowBingo == 1) {
                                printf("Bingo! You got a row!\n");
                                gameOver = 1;
                                break;
                            }
                        }
                        if(gameOver == 1) {
                            break;
                        }
                        // Check columns
                        for(int k = 0; k < COLUMNS; k++) {
                            int columnBingo = 1;
                            for(int l = 0; l < ROWS; l++) {
                                if(bingoCard[l][k] != 0) {
                                    columnBingo = 0;
                                    break;
                                }
                            }
                            if(columnBingo == 1) {
                                printf("Bingo! You got a column!\n");
                                gameOver = 1;
                                break;
                            }
                        }
                        if(gameOver == 1) {
                            break;
                        }
                        // Check diagonals
                        if(bingoCard[0][0] == 0 && bingoCard[1][1] == 0 && bingoCard[2][2] == 0 && bingoCard[3][3] == 0 && bingoCard[4][4] == 0) {
                            printf("Bingo! You got a diagonal!\n");
                            gameOver = 1;
                            break;
                        }
                        if(bingoCard[0][4] == 0 && bingoCard[1][3] == 0 && bingoCard[2][2] == 0 && bingoCard[3][1] == 0 && bingoCard[4][0] == 0) {
                            printf("Bingo! You got a diagonal!\n");
                            gameOver = 1;
                            break;
                        }
                    }
                }
                if(gameOver == 1) {
                    break;
                }
            }
        }
    } while(gameOver == 0);

    // Display the final bingo card
    printf("\nHere is your final Bingo card:\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            printf("%d\t", bingoCard[i][j]);
        }
        printf("\n");
    }

    // End the program
    printf("\nThank you for playing the Bingo Simulator!\n");
    return 0;
}