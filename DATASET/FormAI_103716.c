//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for the Bingo game
#define ROWS 5
#define COLS 5
#define MIN_NUM 1
#define MAX_NUM 75

// Define function prototypes
void generateCard(int card[ROWS][COLS]);
int callNumber(int calledNums[MAX_NUM], int numCalled);
int checkCard(int card[ROWS][COLS], int calledNum);

// Main function
int main() {
    // Initialize variables
    int card[ROWS][COLS] = {0};
    int calledNums[MAX_NUM] = {0};
    int numCalled = 0;
    int numHits = 0;

    // Welcome message for the game
    printf("Welcome to the Ken Thompson Bingo Simulator!\n\n");

    // Generate card and display it to the user
    generateCard(card);
    printf("Here is your Bingo card:\n\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == 0) {
                printf("     ");
            } else {
                printf("%-4d ", card[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");

    // Begin calling numbers and checking the card
    srand(time(0)); // Seed random number generator with current time
    while (numHits < ROWS) {
        int calledNum = callNumber(calledNums, numCalled);
        numCalled++;
        printf("The called number is: %d\n", calledNum);
        if (checkCard(card, calledNum)) {
            numHits++;
            printf("You have %d hit%s so far!\n", numHits, numHits == 1 ? "" : "s");
        }
    }

    // Display congratulations message when all rows are hit
    printf("\nCongratulations! You have hit all rows of the Bingo card!\n");

    return 0;
}

// Function to generate a random Bingo card
void generateCard(int card[ROWS][COLS]) {
    // Loop through each column and assign random numbers
    for (int i = 0; i < COLS; i++) {
        // Loop until all five rows in the column have unique random numbers
        int numAssigned = 0;
        while (numAssigned < ROWS) {
            int num = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
            int duplicate = 0;
            // Loop through the rows in the column to check for duplicates
            for (int j = 0; j < numAssigned; j++) {
                if (card[j][i] == num) {
                    duplicate = 1;
                    break;
                }
            }
            // Assign the number to the next available row in the column if it is unique
            if (!duplicate) {
                card[numAssigned][i] = num;
                numAssigned++;
            }
        }
    }
}

// Function to call a random number that has not been called before
int callNumber(int calledNums[MAX_NUM], int numCalled) {
    int num;
    // Loop until a unique, uncalled number is generated
    do {
        num = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
    } while (calledNums[num-1] == 1);
    calledNums[num-1] = 1;
    return num;
}

// Function to check if a called number appears in the card and mark it
int checkCard(int card[ROWS][COLS], int calledNum) {
    // Loop through each cell in the card
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // If the number is found, mark it as hit and return true
            if (card[i][j] == calledNum) {
                card[i][j] = 0;
                return 1;
            }
        }
    }
    return 0;
}