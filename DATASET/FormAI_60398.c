//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: energetic
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define ROWS 5 
#define COLS 5 
#define FREE 0 
#define OCCUPIED 1 

int main(void) { 
    // Seed RNG with current time
    srand(time(NULL)); 

    // Initialize bingo card
    int card[ROWS][COLS] = {0}; 

    // Initialize the horizontal and vertical lines
    int hlines[ROWS] = {FREE}; 
    int vlines[COLS] = {FREE}; 

    // Generate random numbers for the card
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int num = (j * 15) + rand() % 15 + 1; 

            // Check if number is already on the card
            int repeat = 0; 
            for(int k = 0; k < i; k++) {
                for(int l = 0; l < j; l++) {
                    if(card[k][l] == num) {
                        repeat = 1; 
                        break; 
                    }
                }
            }

            // If number is unique, add it to the card
            if(!repeat) card[i][j] = num; 
            else j--; 
        }
        printf("\n"); 
    }

    // Display the bingo card
    printf("Bingo Card:\n"); 
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(!card[i][j]) printf("[   ]"); 
            else printf("[%2d]", card[i][j]); 
        }
        printf("\n"); 
    }

    // Begin the game
    printf("\nWelcome to C Bingo! The game has started.\n"); 

    // Keep track of how many numbers have been called
    int count = 0; 

    while(1) {
        // Generate a random number
        int num = rand() % 75 + 1; 
        printf("\nThe number called is: %d\n", num); 

        // Mark the number on the card
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(card[i][j] == num) {
                    card[i][j] = OCCUPIED; 
                    count++; 
                    hlines[i]++; 
                    vlines[j]++; 
                }
            }
        }

        // Check for a winner
        for(int i = 0; i < ROWS; i++) {
            if(hlines[i] == COLS) {
                printf("\nBINGO! A horizontal line has been completed.\n");
                exit(0); 
            }
        }

        for(int i = 0; i < COLS; i++) {
            if(vlines[i] == ROWS) {
                printf("\nBINGO! A vertical line has been completed.\n"); 
                exit(0); 
            }
        }

        if(count == ROWS * COLS) {
            printf("\nBINGO! The entire card has been completed.\n"); 
            exit(0); 
        }
    }

    return 0; 
}