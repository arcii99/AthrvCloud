//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to clear the terminal
void clear() {
    system("clear || cls");
}

int main() {
    int num, guess, tries = 0;
    
    // Generate Random Number
    srand(time(0));
    num = rand() % 100 + 1;
    
    // Print Instructions
    printf("\nWelcome to the Number Guessing Game!\n");
    printf("\nI am thinking of a number between 1 and 100\n");
    printf("\nYou have to guess that number within 5 tries\n");
    
    // Game Loop
    while(tries < 5) {
        printf("\nGuess %d: ", tries+1);
        scanf("%d", &guess);
        
        if(guess == num) {
            printf("\nCongratulations! You have guessed the correct number in %d tries\n", tries+1);
            printf("\nThe number was %d\n", num);
            return 0;
        } else if(guess < num) {
            printf("\nYour guess is lower than the number\n");
        } else {
            printf("\nYour guess is higher than the number\n");
        }
        
        tries++;
    }
    
    // Game Over
    printf("\nSorry! You have used all 5 tries.\n");
    printf("\nThe number I was thinking of was %d\n", num);
    
    return 0;
}