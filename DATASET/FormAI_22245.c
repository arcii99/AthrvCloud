//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

/* Function to randomly generate a number between 1 and 75 */
int generateNum() {
    return (rand() % 75) + 1;
}

/* Function to check if a number exists in the calling row */
int checkRow(int row[], int num) {
    for(int i = 0; i < COLS; i++) {
        if(row[i] == num) {
            row[i] = 0; // Mark the number as called by setting it to 0
            return 1;   // Number exists in row
        }
    }
    return 0;   // Number does not exist in row
}

/* Function to check if all elements of the calling row are 0 */
int checkWin(int row[]) {
    for(int i = 0; i < COLS; i++) {
        if(row[i] != 0) {
            return 0;   // row is incomplete
        }
    }
    return 1;   // row is complete
}

int main() {
    int randNum;
    int bingoCard[ROWS][COLS] = {    // Initializing the bingo card
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int calledNums[75] = {0};   // Initializing array to hold all called numbers
    int playerWins = 0; // Counter to keep track of number of rows completed by player
    srand(time(0)); // Seed for rand() function, based on current time
  
    printf("\n\nWelcome to Bingo Simulator!\n");

    // While loop to keep calling numbers until a player wins
    while(playerWins < ROWS) {
        randNum = generateNum();    // Generate a random number
        calledNums[randNum-1] = 1;  // Mark the number as called by setting the corresponding index to 1
        printf("\nNumber called: %d\n", randNum);
        
        // Check if the number exists in any row of the bingo card
        for(int i = 0; i < ROWS; i++) {
            if(checkRow(bingoCard[i], randNum)) {
                printf("Number exists in row %d!\n", i+1);
                if(checkWin(bingoCard[i])) {
                    printf("Row %d is complete!\n", i+1);
                    playerWins++;
                }
                break;  // Exit the loop once the number is found in a row
            }
        }
    }
    printf("\n\nBINGO! You won the game!\n");
    return 0;
}