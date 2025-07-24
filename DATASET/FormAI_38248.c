//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the constants for the Bingo game
#define ROWS 5
#define COLS 5
#define BINGO 5

// Function to initialize the Bingo card with random values
void initializeCard(int card[ROWS][COLS])
{
    int i, j;
    srand(time(NULL));
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            card[i][j] = rand() % 15 + (j * 15) + 1;
        }
    }
    card[ROWS / 2][COLS / 2] = 0; // Mark the center as FREE
}

// Function to check whether a Bingo is achieved
int checkForBingo(int card[ROWS][COLS])
{
    int i, j, count;
    // Check for horizontal and vertical Bingos
    for(i = 0; i < ROWS; i++) {
        count = 0;
        for(j = 0; j < COLS; j++) {
            if(card[i][j] == 0) {
                count++;
            }
        }
        if(count == BINGO) {
            return 1;
        }
        count = 0;
        for(j = 0; j < COLS; j++) {
            if(card[j][i] == 0) {
                count++;
            }
        }
        if(count == BINGO) {
            return 1;
        }
    }
    // Check for diagonal and reverse diagonal Bingos
    count = 0;
    for(i = 0; i < ROWS; i++) {
        if(card[i][i] == 0) {
            count++;
        }
    }
    if(count == BINGO) {
        return 1;
    }
    count = 0;
    for(i = 0; i < ROWS; i++) {
        if(card[i][ROWS - i - 1] == 0) {
            count++;
        }
    }
    if(count == BINGO) {
        return 1;
    }
    return 0;
}

int main()
{
    int card[ROWS][COLS], i, j, num, bingo;
    // Initialize the Bingo card with random values
    initializeCard(card);
    // Print the card at the beginning of the game
    printf("BINGO CARD:\n");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%d\t", card[i][j]);
        }
        printf("\n");
    }
    // Start the game
    printf("\n\nLET'S PLAY BINGO!\n");
    do {
        // Generate a random number between 1 and 75
        num = rand() % 75 + 1;
        printf("\nCALLER: %d\n", num);
        // Mark the number on the card
        for(i = 0; i < ROWS; i++) {
            for(j = 0; j < COLS; j++) {
                if(card[i][j] == num) {
                    card[i][j] = 0;
                }
            }
        }
        // Check for Bingos
        bingo = checkForBingo(card);
        if(bingo) {
            printf("\nWE HAVE A BINGO!\n");
        } else {
            printf("\nKEEP PLAYING...\n");
        }
        // Print the updated card
        printf("BINGO CARD:\n");
        for(i = 0; i < ROWS; i++) {
            for(j = 0; j < COLS; j++) {
                printf("%d\t", card[i][j]);
            }
            printf("\n");
        }
    } while(!bingo);
    return 0;
}