//FormAI DATASET v1.0 Category: Table Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 100
int generateRandomNumber() {
    srand(time(0)); // Initialize random number generator
    return (rand() % 100) + 1; // Return a random number between 1 and 100
}

int main() {
    int randomNumber = generateRandomNumber(); // Generate a random number
    
    printf("Welcome to Guess the Number!\n");
    printf("I am thinking of a number between 1 and 100.\n");
    printf("You have 10 attempts to guess the number.\n");

    int guess;
    int attempts = 0;

    // Game loop
    while (attempts < 10) {
        printf("Guess #%d: ", attempts + 1);
        scanf("%d", &guess);

        if (guess < 1 || guess > 100) {
            printf("Invalid guess. Please enter a number between 1 and 100.\n");
        } else if (guess < randomNumber) {
            printf("Your guess is too low. Try again.\n");
            attempts++;
        } else if (guess > randomNumber) {
            printf("Your guess is too high. Try again.\n");
            attempts++;
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts + 1);
            break; // Exit the game loop
        }
    }

    // If the user is unable to guess the number in 10 attempts
    if (attempts == 10) {
        printf("Sorry, you were unable to guess the number. The number was %d.\n", randomNumber);
    }

    return 0;
}