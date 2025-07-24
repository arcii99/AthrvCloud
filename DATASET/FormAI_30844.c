//FormAI DATASET v1.0 Category: Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int guess;
    int num;
    int min = 1;
    int max = 100;
    int tries = 0;

    srand(time(0)); // Seed for random function
    num = min + (rand() % (max - min + 1)); // Generating a random number between 1 and 100

    printf("Welcome to the Number Guessing Game\n");

    do {
        printf("\nGuess a number between %d and %d: ", min, max);
        scanf("%d", &guess);
        tries++;

        if (guess < num) {
            printf("Too low! Try again.\n");
            min = guess; // Adjusting the minimum value of the range for the next guess
        } else if (guess > num) {
            printf("Too high! Try again.\n");
            max = guess; // Adjusting the maximum value of the range for the next guess
        } else {
            printf("Congratulations! You guessed the number %d in %d tries.\n", num, tries);
        }

    } while (guess != num);

    return 0;
}