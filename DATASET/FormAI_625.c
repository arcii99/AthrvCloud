//FormAI DATASET v1.0 Category: Random ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess, tries = 0;
    srand(time(NULL)); /* seed the random number generator */
    num = rand() % 100 + 1; /* generate a random number between 1 and 100 */

    printf("Welcome to the Random Number Guessing Game!\n");
    printf("I have selected a random number between 1 and 100.\n");
    printf("Can you guess what it is in 10 tries or less?\n\n");

    do {
        printf("Enter your guess (between 1 and 100): ");
        scanf("%d", &guess);
        tries++;

        if (guess > num) {
            printf("Sorry, that's too high. Try again.\n\n");
        } else if (guess < num) {
            printf("Sorry, that's too low. Try again.\n\n");
        }
    } while (guess != num && tries < 10);

    if (guess == num) {
        printf("\nCongratulations! You guessed the number in %d tries!\n", tries);
    } else {
        printf("\nSorry, you ran out of tries. The number was %d.\n", num);
    }

    return 0;
}