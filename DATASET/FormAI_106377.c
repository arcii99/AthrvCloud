//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5       // Number of rows in the Bingo card
#define COLS 5       // Number of columns in the Bingo card

// Function to generate a random number
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to create the initial Bingo card
void createBingoCard(int card[ROWS][COLS]) {
    int i, j;
    
    // Fill the card with zeros
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            card[i][j] = 0;
        }
    }
    
    // Generate the values for B column (1-15)
    for(i = 0; i < ROWS; i++) {
        card[i][0] = generateRandomNumber((i * 15) + 1, (i + 1) * 15);
    }
    
    // Generate the values for I column (16-30)
    for(i = 0; i < ROWS; i++) {
        card[i][1] = generateRandomNumber(16 + (i * 15), 30 + i * 15);
    }
    
    // Generate the values for N column (31-45)
    for(i = 0; i < ROWS; i++) {
        if(i == ROWS / 2) {
            card[i][2] = 0;     // Free space
        } else {
            card[i][2] = generateRandomNumber(31 + (i * 15), 45 + i * 15);
        }
    }
    
    // Generate the values for G column (46-60)
    for(i = 0; i < ROWS; i++) {
        card[i][3] = generateRandomNumber(46 + (i * 15), 60 + i * 15);
    }
    
    // Generate the values for O column (61-75)
    for(i = 0; i < ROWS; i++) {
        card[i][4] = generateRandomNumber(61 + (i * 15), 75 + i * 15);
    }
}

// Function to print the Bingo card
void printBingoCard(int card[ROWS][COLS]) {
    int i, j;
    printf("B   I   N   G   O\n");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(card[i][j] == 0) {
                printf("X   ");        // Free space
            } else {
                printf("%-3d ", card[i][j]);
            }
        }
        printf("\n");
    }
}

// Recursive function to check if the Bingo card has a win
int checkWin(int card[ROWS][COLS], int row, int col) {
    int i;
    int win = 1;
    
    // Check the row
    for(i = 0; i < COLS; i++) {
        if(card[row][i] != 0) {
            win = 0;
            break;
        }
    }
    if(win) return 1;
    
    // Check the column
    win = 1;
    for(i = 0; i < ROWS; i++) {
        if(card[i][col] != 0) {
            win = 0;
            break;
        }
    }
    if(win) return 1;
    
    // Check diagonal 1
    if(row == col) {
        win = 1;
        for(i = 0; i < ROWS; i++) {
            if(card[i][i] != 0) {
                win = 0;
                break;
            }
        }
        if(win) return 1;
    }
    
    // Check diagonal 2
    if(row + col == ROWS - 1) {
        win = 1;
        for(i = 0; i < ROWS; i++) {
            if(card[i][ROWS - 1 - i] != 0) {
                win = 0;
                break;
            }
        }
        if(win) return 1;
    }
    
    return 0;
}

int main() {
    int bingoCard[ROWS][COLS];
    int numCalled;
    int row, col;
    
    // Initialize the random number generator with the current time
    srand(time(NULL));
    
    // Create the Bingo card
    createBingoCard(bingoCard);
    
    // Print the Bingo card
    printBingoCard(bingoCard);
    
    // Start calling numbers
    while(1) {
        // Generate a random number
        numCalled = generateRandomNumber(1, 75);
        
        // Search the card for the called number
        for(row = 0; row < ROWS; row++) {
            for(col = 0; col < COLS; col++) {
                if(bingoCard[row][col] == numCalled) {
                    bingoCard[row][col] = 0;    // Mark the number as called
                    printf("Number %d called!\n", numCalled);
                    
                    // Check if there is a win
                    if(checkWin(bingoCard, row, col)) {
                        printf("BINGO!!!\n");
                        exit(0);
                    }
                    break;      // Number found, exit the inner loop
                }
            }
        }
    }
    
    return 0;
}