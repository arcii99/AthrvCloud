//FormAI DATASET v1.0 Category: Math exercise ; Style: relaxed
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, guess;
    int num_attempts = 0;
    int max_attempts = 5;
    char play_again;

    srand(time(0));  // Seed random number generator

    do {
        num1 = rand() % 10 + 1;  // Generate a random number between 1 & 10
        num2 = rand() % 10 + 1;  // Generate another random number between 1 & 10

        printf("What is the result of %d x %d? ", num1, num2);

        while (num_attempts < max_attempts) {
            scanf("%d", &guess);

            if (guess == (num1 * num2)) {
                printf("You are correct!\n");
                break;
            }

            num_attempts++;
            printf("Sorry, that's not the right answer. You have %d attempts left.\n", max_attempts - num_attempts);
        }

        if (num_attempts == max_attempts) {
            printf("You have no more attempts left. The answer was %d.\n", num1 * num2);
        }

        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &play_again);
        num_attempts = 0;  // Reset num_attempts for next round

    } while (play_again == 'y' || play_again == 'Y');

    printf("Thanks for playing!\n");

    return 0;
}