//FormAI DATASET v1.0 Category: Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1 and 100
int generateRandomNumber() {
    srand(time(0));
    int randomNumber = rand() % 100 + 1;
    return randomNumber;
}

int main() {
    int randomNumber = generateRandomNumber();
    int guessCount = 0;
    int guess;

    printf("Welcome to the Guessing Game!\n");
    printf("The computer has generated a random number between 1 and 100. Try to guess it in the fewest attempts possible.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        guessCount++;

        if (guess > randomNumber) {
            printf("Too high! Try again.\n");
        } else if (guess < randomNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", guessCount);
        }
    } while (guess != randomNumber);

    return 0;
}