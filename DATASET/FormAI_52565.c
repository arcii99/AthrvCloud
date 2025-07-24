//FormAI DATASET v1.0 Category: Educational ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 5

int main() {
    srand(time(NULL));
    int number = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    printf("Welcome to the Number Guessing Game!\n");
    printf("You have %d attempts to guess a number between 1 and 100.\n", MAX_ATTEMPTS);

    while(attempts < MAX_ATTEMPTS) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if(guess == number) {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts + 1);
            return 0;
        } else {
            printf("Incorrect. ");
            if(guess < number) {
                printf("The number is higher than %d.\n", guess);
            } else {
                printf("The number is lower than %d.\n", guess);
            }
        }

        attempts++;
    }

    printf("Sorry, you ran out of attempts. The number was %d.\n", number);
    return 0;
}