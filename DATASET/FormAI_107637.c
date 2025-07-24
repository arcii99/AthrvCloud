//FormAI DATASET v1.0 Category: Table Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int table[5][5] = {0}; // initialize a 5x5 table with all zeroes
    srand(time(NULL)); // seed the random number generator with the current time
    
    // randomly select coordinates for the target square
    int targetRow = rand() % 5;
    int targetCol = rand() % 5;
    table[targetRow][targetCol] = 1; // set the target square to 1
    
    printf("Welcome to the Table Game!\n");
    printf("Try to find the target square with as few guesses as possible.\n");
    printf("The table looks like this:\n");
    
    // print the table
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            printf("%d ", table[row][col]);
        }
        printf("\n");
    }
    
    int numGuesses = 0; // keep track of the number of guesses
    int guessRow, guessCol;
    do {
        numGuesses++;
        printf("Enter your guess for the row and column (separated by a space): ");
        scanf("%d %d", &guessRow, &guessCol);
        
        // check if the guess is valid
        if (guessRow < 0 || guessRow >= 5 || guessCol < 0 || guessCol >= 5) {
            printf("Invalid guess. Please enter a row and column between 0 and 4.\n");
        } else if (table[guessRow][guessCol] == 1) {
            printf("Congratulations, you found the target square in %d guesses!\n", numGuesses);
        } else {
            printf("Not quite, try again.\n");
        }
    } while (table[guessRow][guessCol] != 1); // continue guessing until the target is found
    
    return 0;
}