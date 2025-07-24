//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_RANGE 25
#define BINGO_GOAL 5

// Function to print the Bingo Card
void printCard(int card[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%2d ", card[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to generate a random number between 1 and MAX_RANGE
int generateRandomNumber(int max_range) {
    return (rand() % max_range) + 1;
}

// Function to check if the number is present in the Bingo Card
int isInCard(int card[ROWS][COLS], int num) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(card[i][j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to mark the number on the card
void markNumber(int card[ROWS][COLS], int num) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(card[i][j] == num) {
                card[i][j] = -1;
                break;
            }
        }
    }
}

// Function to check if any row contains BINGO_GOAL marked numbers
int checkRows(int card[ROWS][COLS]) {
    int count = 0;
    for(int i = 0; i < ROWS; i++) {
        count = 0;
        for(int j = 0; j < COLS; j++) {
            if(card[i][j] == -1) {
                count++;
            }
        }
        if(count == BINGO_GOAL) {
            return 1;
        }
    }
    return 0;
}

// Function to check if any column contains BINGO_GOAL marked numbers
int checkCols(int card[ROWS][COLS]) {
    int count = 0;
    for(int i = 0; i < COLS; i++) {
        count = 0;
        for(int j = 0; j < ROWS; j++) {
            if(card[j][i] == -1) {
                count++;
            }
        }
        if(count == BINGO_GOAL) {
            return 1;
        }
    }
    return 0;
}

// Function to check if any diagonal contains BINGO_GOAL marked numbers
int checkDiagonal(int card[ROWS][COLS]) {
    int count = 0;
    for(int i = 0; i < ROWS; i++) {
        if(card[i][i] == -1) {
            count++;
        }
    }
    if(count == BINGO_GOAL) {
        return 1;
    }
    count = 0;
    for(int i = 0; i < ROWS; i++) {
        if(card[i][ROWS-i-1] == -1) {
            count++;
        }
    }
    if(count == BINGO_GOAL) {
        return 1;
    }
    return 0;
}

int main() {
    int card[ROWS][COLS];
    int calledNumbers[MAX_RANGE];
    int randomNumber = 0;
    int numberCount = 0;
    int isBingo = 0;
    srand(time(0));
    
    // Initialize the Bingo Card
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            card[i][j] = (i*COLS + j) + 1;
        }
    }
    
    // Print the Bingo Card
    printf("Your Bingo Card:\n");
    printCard(card);
    
    // Generate and print the called numbers
    printf("The called numbers are:");
    while(!isBingo) {
        // Generate a random number that has not been called before
        do {
            randomNumber = generateRandomNumber(MAX_RANGE);    
        } while(isInCard(card, randomNumber) || isInCard(calledNumbers, randomNumber));
        
        // Add the number to the called numbers array and mark it on the Bingo Card
        calledNumbers[numberCount] = randomNumber;
        markNumber(card, randomNumber);
        numberCount++;
        
        // Print the called number
        printf(" %d", randomNumber);

        // Check if Bingo has been achieved
        if(checkRows(card) || checkCols(card) || checkDiagonal(card)) {
            isBingo = 1;
            printf("\n\nBingo!\n\n");
        }
    }
    
    return 0;
}