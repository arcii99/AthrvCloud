//FormAI DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between lower and upper bounds
int randomNumber(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main()
{
    srand(time(0)); // Seed for random number generation

    int num, guess, attempts = 0;
    int lower = 1, upper = 100; // Lower and Upper bounds for random number

    num = randomNumber(lower, upper); // Generate random number

    printf("I am thinking of a number between %d and %d\n", lower, upper);

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess > num) {
            printf("Too high! Try again.\n");
        } else if (guess < num) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts\n", attempts);
        }
        
        attempts++;
    } while (guess != num);

    return 0;
}