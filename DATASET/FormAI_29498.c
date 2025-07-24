//FormAI DATASET v1.0 Category: Funny ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int guess, number, attempts = 0;

    srand(time(NULL));
    number = rand() % 100 + 1;
    
    printf("============================= \n");
    printf("| Welcome to Guess the Number | \n");
    printf("============================= \n\n");
    printf("I am thinking of a number between 1 and 100. Can you guess what it is?\n\n");

    do {
        attempts++;
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess > number) {
            printf("Too high!\n");
        } else if (guess < number) {
            printf("Too low!\n");
        } else {
            printf("\nCongratulations! You guessed the number in %d attempts!", attempts);
        }

    } while (guess != number);

    return 0;
}