//FormAI DATASET v1.0 Category: Math exercise ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand(time(NULL));      // seed random number generator
    int x = rand() % 100;    // choose random number between 0 and 99
    int y = rand() % 100;    // choose another random number between 0 and 99
    int guess;               // initialize variable for guessed number
    int attempts = 0;        // initialize variable for number of attempts
    
    printf("Welcome to the Guessing Game!\n");
    printf("I have chosen two numbers between 0 and 99.\n");
    printf("Can you guess what they are?\n");
    
    while (guess != x && guess != y) {   // loop until correct guess made
        printf("Enter your guess: ");
        scanf("%d", &guess);            // get user input
        
        if (!(guess >= 0 && guess <= 99)) {   // check if guess is within range
            printf("Invalid input. Please enter a number between 0 and 99.\n");
            continue;                       // jump back to beginning of loop
        }
        
        attempts++;     // increment number of attempts
        
        if (guess == x) {
            printf("Congratulations, you guessed number %d in %d attempts!\n", x, attempts);
        } else if (guess == y) {
            printf("Congratulations, you guessed number %d in %d attempts!\n", y, attempts);
        } else {
            printf("Sorry, your guess is incorrect. Try again.\n");
        }
    }
    
    return 0;
}