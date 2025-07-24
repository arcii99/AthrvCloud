//FormAI DATASET v1.0 Category: Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));  // Seed the random number generator with time
    int guess, num, tries = 0;
    num = rand() % 10001;  // Generate a random number between 0 and 10000

    printf("\nI'm thinking of a number between 0 and 10000. Can you guess what it is?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess < num) {
            printf("Too low! Try again.\n");
        } else if (guess > num) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries!\n", tries);
        }
    } while (guess != num);

    return 0;
}