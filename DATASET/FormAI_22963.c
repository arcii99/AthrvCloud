//FormAI DATASET v1.0 Category: Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printIntro() {
    printf("Welcome to the guessing game!\n");
    printf("Try to guess the secret number between 1 and 100.\n");
    printf("You have a maximum of 10 tries.\n");
}

int generateNumber() {
    srand(time(NULL)); // Seed the random number generator with current time
    int secretNumber = rand() % 100 + 1;
    return secretNumber;
}

void runGame(int secretNumber) {
    int guess, numTries = 0;
    while (numTries < 10) {
        printf("Enter your guess (between 1 and 100): ");
        scanf("%d", &guess);

        if (guess == secretNumber) {
            printf("Congratulations! You guessed the secret number in %d tries.\n", numTries + 1);
            return;
        } else if (guess < secretNumber) {
            printf("Your guess is too low. ");
        } else if (guess > secretNumber) {
            printf("Your guess is too high. ");
        }

        printf("You have %d tries left.\n", 9 - numTries);
        numTries++;
    }

    printf("Sorry, you ran out of tries. The secret number was %d.\n", secretNumber);
}

int main() {
    printIntro();
    int secretNumber = generateNumber();
    runGame(secretNumber);

    return 0;
}