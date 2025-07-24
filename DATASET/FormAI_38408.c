//FormAI DATASET v1.0 Category: Benchmarking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    printf("\n\n\nWelcome to the Great C Benchmarking Show!\n\n");

    printf("Today we're going to test your luck in a game called \"Guess the Number\"!\n");
    printf("I bet you didn't see that coming, huh?\n");

    printf("\nHere are the rules:\n");
    printf("The computer will pick a random number between 0 and 100.\n");
    printf("Your job is to guess the number the computer picked.\n");
    printf("Easy, right?\n");

    srand(time(NULL));
    int number = rand() % 101;
    int guess = -1;
    int counter = 0;

    printf("\n\n\nAlright, let's start!\n");

    while (guess != number) {
        printf("\n\n\nWhat's your guess?\n");
        scanf("%d", &guess);

        if (guess < number) {
            printf("\nToo low! Try again.\n");
            counter++;
        }
        else if (guess > number) {
            printf("\nToo high! Try again.\n");
            counter++;
        }
        else {
            counter++;
            printf("\nCongratulations! You guessed it in %d tries!\n", counter);
        }
    }

    printf("\n\n\nThank you for playing the Great C Benchmarking Show!\n");
    printf("We hope you enjoyed this game as much as we enjoyed writing it!\n");

    return 0;
}