//FormAI DATASET v1.0 Category: Funny ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {

    int answer = 42; //The Ultimate Answer to the Ultimate Question of Life, the Universe, and Everything
    int guess;
    int tries = 0;

    printf("Welcome to the Ultimate Guessing Game!\n");
    printf("You have seven tries to guess the number.\n\n");

    while (tries < 7) {

        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess == answer) {
            printf("\nCongratulations, you got it right!\n");
            printf("It only took you %d tries.\n", tries);
            break;
        } else {
            printf("Sorry, that's not it.\n");
        }

        if (guess > answer) {
            printf("Your guess is too high.\n\n");
        } else if (guess < answer) {
            printf("Your guess is too low.\n\n");
        }

        if (tries == 7) {
            printf("Game over, better luck next time.\n");
        }

    }

    printf("\nThanks for playing the Ultimate Guessing Game!\n");

    return 0;
}