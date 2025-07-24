//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between min and max
int getRandomNumber(int min, int max)
{
    srand(time(NULL));  // Seed random number generator
    return (rand() % (max - min + 1)) + min;
}

int main()
{
    int guess, numAttempts = 0, randomNumber = getRandomNumber(1, 20);

    printf("Guess the number between 1 and 20.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess < 1 || guess > 20) {
            printf("Invalid guess. Please enter a number between 1 and 20.\n");
        } else if (guess < randomNumber) {
            printf("Your guess is too low. Try again.\n");
            numAttempts++;
        } else if (guess > randomNumber) {
            printf("Your guess is too high. Try again.\n");
            numAttempts++;
        } else {
            numAttempts++;
            printf("Congratulations! You won in %d attempts.\n", numAttempts);
        }
    } while (guess != randomNumber);

    return 0;
}