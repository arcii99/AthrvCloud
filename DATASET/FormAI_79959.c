//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between low and high (inclusive)
int getRandomNumber(int low, int high)
{
    srand(time(NULL));     // seed the random number generator with the current time
    return (rand() % (high - low + 1)) + low;
}

int main()
{
    int guess, randomNumber, numAttempts = 0, maxAttempts = 10;

    // randomly generate a number between 1 and 100
    randomNumber = getRandomNumber(1, 100);

    printf("Welcome to the Guessing Game!\n");

    // loop until the user runs out of guesses or correctly guesses the number
    while (numAttempts < maxAttempts)
    {
        printf("Guess the number between 1 and 100. You have %d attempts left: ", maxAttempts - numAttempts);
        scanf("%d", &guess);

        // Increment the numAttempts count.
        numAttempts++;

        if (guess == randomNumber)   // If user guessed the number, break out of the loop.
        {
            printf("Congratulations! You have correctly guessed the number %d in %d attempts.\n", randomNumber, numAttempts);
            break;
        }
        else if (guess < randomNumber)
        {
            printf("Your guess is too low. ");
        }
        else
        {
            printf("Your guess is too high. ");
        }
        if (numAttempts == maxAttempts) // if the user ran out of attempts, print the correct number.
        {
            printf("You have run out of attempts. The correct number was %d.\n", randomNumber);
        }
    }
    return 0;
}