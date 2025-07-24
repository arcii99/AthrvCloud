//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int bingoCard[5][5]; // The 5x5 bingo card
    int bingoCalls[75];  // Array to store the 75 possible bingo calls
    
    // Initialize all the elements of the bingoCard to 0
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            bingoCard[i][j] = 0;
        }
    }
    
    // Fill the array of bingo calls with the numbers 1-75
    for(int i = 0; i < 75; i++) {
        bingoCalls[i] = i + 1;
    }
    
    // Shuffle the array of bingo calls using the Fisher-Yates shuffle algorithm
    for(int i = 74; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = bingoCalls[i];
        bingoCalls[i] = bingoCalls[j];
        bingoCalls[j] = temp;
    }
    
    // Print out the shuffled bingo call numbers
    printf("Bingo Calls:\n");
    for(int i = 0; i < 75; i++) {
        printf("%d ", bingoCalls[i]);
        if((i+1) % 15 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    
    // Randomly choose which column gets which range of numbers
    int columnRanges[5][2];
    for(int i = 0; i < 5; i++) {
        if(i == 2) {
            columnRanges[i][0] = 41;
            columnRanges[i][1] = 50;
        } else {
            columnRanges[i][0] = i*15 + 1;
            columnRanges[i][1] = (i+1)*15;
        }
    }
    
    // Fill out the bingo card with random numbers from their assigned ranges
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(i == 2 && j == 2) {
                continue; // Middle spot is free space
            }
            int rangeMin = columnRanges[j][0];
            int rangeMax = columnRanges[j][1];
            int num = (rand() % (rangeMax-rangeMin+1)) + rangeMin;
            bingoCard[i][j] = num;
        }
    }
    
    // Print out the empty bingo card
    printf("Bingo Card:\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%3d ", bingoCard[i][j]);
        }
        printf("\n");
    }
    
    // Start the game
    printf("Let's play bingo!\n");
    int calledNumbers[75];  // Array to store the numbers that have been called
    int numCalled = 0;      // Counter for the number of times a number has been called
    
    // Keep calling numbers until someone gets bingo
    while(1) {
        // Get the next number to call from the shuffled array of bingo calls
        int numToCall = bingoCalls[numCalled];
        
        // Check if the number has already been called
        int alreadyCalled = 0;
        for(int i = 0; i < numCalled; i++) {
            if(calledNumbers[i] == numToCall) {
                alreadyCalled = 1;
                break;
            }
        }
        if(alreadyCalled) {
            continue;
        }
        
        // Print out the number that was called
        printf("Calling number %d!\n", numToCall);
        
        // Mark the number on every bingo card if it exists
        int numMarked = 0;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(bingoCard[i][j] == numToCall) {
                    bingoCard[i][j] = -1; // Mark the number as called
                    numMarked++;
                }
            }
        }
        
        // Check if any of the players have bingo
        int bingo = 0;
        for(int i = 0; i < 5; i++) {
            // Check rows
            if(bingoCard[i][0] == -1 && bingoCard[i][1] == -1 && bingoCard[i][2] == -1 && bingoCard[i][3] == -1 && bingoCard[i][4] == -1) {
                bingo = 1;
                break;
            }
            // Check columns
            if(bingoCard[0][i] == -1 && bingoCard[1][i] == -1 && bingoCard[2][i] == -1 && bingoCard[3][i] == -1 && bingoCard[4][i] == -1) {
                bingo = 1;
                break;
            }
        }
        // Check diagonals
        if(bingoCard[0][0] == -1 && bingoCard[1][1] == -1 && bingoCard[2][2] == -1 && bingoCard[3][3] == -1 && bingoCard[4][4] == -1) {
            bingo = 1;
        }
        if(bingoCard[0][4] == -1 && bingoCard[1][3] == -1 && bingoCard[2][2] == -1 && bingoCard[3][1] == -1 && bingoCard[4][0] == -1) {
            bingo = 1;
        }
        
        // If someone got bingo, end the game and declare the winner
        if(bingo) {
            printf("BINGO! We have a winner!\n");
            printf("Congratulations on winning the game!\n");
            break;
        }
        
        // If all numbers have been called and nobody got bingo, end the game and declare a tie
        numCalled++;
        if(numCalled == 75) {
            printf("It's a tie! Nobody got bingo!\n");
            break;
        }
    }
    
    return 0;
}