//FormAI DATASET v1.0 Category: Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    printf("Welcome to the Guessing Game !\n\n");

    srand(time(0));
    int number = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    do {
        printf("Enter your guess (between 1 and 100): ");
        scanf("%d", &guess);
        attempts++;

        if (guess > number) {
            printf("Your guess is too high !\n");
        }
        else if (guess < number) {
            printf("Your guess is too low !\n");
        }
        else {
            printf("\nCongratulations ! You guessed it in %d attempts.\n", attempts);
        }
    } while (guess != number);

    return 0;
}