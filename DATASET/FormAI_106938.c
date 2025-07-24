//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to display the instructions
void displayInstructions() {
    printf("\nWelcome to the Guessing Game!\n");
    printf("Your task is to guess a number between 1 and 100.\n");
    printf("You will be given 7 attempts to guess the correct number.\n");
    printf("After each guess, you will be told if your guess is too high or too low.\n");
}

// function to generate the random number
int generateRandomNumber() {
    srand(time(NULL)); // use current time as seed
    return rand() % 100 + 1; // generate random number between 1 and 100
}

int main() {
    int randomNumber = generateRandomNumber();
    int guess, attempts = 0;

    // display instructions
    displayInstructions();

    // loop through the game until the user has used all attempts or guessed the correct number
    while (attempts < 7) {
        printf("\nGuess a number between 1 and 100: ");
        scanf("%d", &guess);
        attempts++;

        if (guess == randomNumber) {
            printf("\nCongratulations! You guessed the correct number in %d attempts.\n\n", attempts);
            return 0;
        } else if (guess < randomNumber) {
            printf("\nOops! Your guess is too low.\n");
        } else {
            printf("\nOh no! Your guess is too high.\n");
        }
    }

    printf("\nSorry, you have used all your attempts. The correct number was %d.\n\n", randomNumber);

    return 0;
}