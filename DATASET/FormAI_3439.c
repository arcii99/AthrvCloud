//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between the given range
int generateRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main()
{
    srand(time(NULL)); // Set the seed value for random number generation

    int randomNumber = generateRandomNumber(1, 100); // Generate a random number between 1 to 100

    int guess, numberOfGuesses = 1; // Initialize the guess variable and set the initial guess count to 1

    printf("Guess a number between 1 to 100\n");

    do {
        scanf("%d", &guess); // Take the guess input from user

        if (guess < randomNumber) { // If the guess is smaller than the random number
            printf("Too low. Guess again.\n");
            numberOfGuesses++; // Increment the guess count
        }

        else if (guess > randomNumber) { // If the guess is greater than the random number
            printf("Too high. Guess again.\n");
            numberOfGuesses++; // Increment the guess count
        }

        else { // If the guess is equal to the random number
            printf("Congratulations! You guessed the number in %d attempts.\n", numberOfGuesses);
            break; // Exit the infinite loop
        }
    } while (1);

    return 0;
}