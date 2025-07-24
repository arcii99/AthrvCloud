//FormAI DATASET v1.0 Category: Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize variables
    int guess, num, tries = 0;
    srand(time(0));
    num = rand() % 100 + 1;

    // greet user and get their first guess
    printf("Welcome to the Guessing Game!\n");
    printf("I have a number between 1 and 100, can you guess what it is?\n");
    printf("Please enter your guess: ");
    scanf("%d", &guess);
    tries++;

    // loop to keep asking user for input until they guess correctly
    while(guess != num) {
        if(guess > num) {
            printf("Too high...try again!\n");
        } else {
            printf("Too low...try again!\n");
        }
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;
    }

    // user guessed the correct number, congratulate them and print statistics
    printf("\nCongratulations, you guessed the number %d!\n", num);
    printf("It took you %d tries to guess the correct number.\n", tries);

    return 0;
}