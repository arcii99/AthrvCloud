//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This is a simple C Terminal Based Game where the user has to guess a randomly generated number between 1 and 100. 
The user has a limited number of tries, and each time they guess, they will receive a hint to help them get closer to the answer.*/

int main() {
    int correct_number, guessed_number, remaining_guesses = 10, counter = 1;
    srand(time(0)); // Initializes the random number generator

    correct_number = (rand() % 100) + 1; // Generates a random number between 1 and 100

    printf("\nWELCOME TO THE GUESSING GAME!\n\n");

    while (remaining_guesses != 0) {
        printf("Guess a number between 1 and 100 (you have %d guesses left): ", remaining_guesses);
        scanf("%d", &guessed_number);

        if (guessed_number < 1 || guessed_number > 100) { // Checking if the input is valid
            printf("Invalid input! Please enter a number between 1 and 100. \n");
            continue; // Restart the loop
        }
        else if (guessed_number == correct_number) {
            printf("Congratulations! You guessed the correct number in %d try/tries.\n", counter);
            break; // Exit the loop
        }
        else if (guessed_number > correct_number) {
            printf("Your guess is too high! Try again.\n");
            remaining_guesses--;
            counter++;
        } 
        else {
            printf("Your guess is too low! Try again.\n");
            remaining_guesses--;
            counter++;
        }
    }

    if (remaining_guesses == 0) {
        printf("Sorry, you have used all your %d guesses. The correct number was %d!\n", 10, correct_number);
    }

    printf("\nThank you for playing! Please come again.\n\n");
    return 0;
}