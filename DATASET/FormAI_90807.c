//FormAI DATASET v1.0 Category: Math exercise ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize variables
    int answer = 0;
    int guess = -1;
    int attempts = 0;
    int lower_bound, upper_bound;

    // Prompt user for bounds
    printf("Enter the lower bound: ");
    scanf("%d", &lower_bound);

    printf("Enter the upper bound: ");
    scanf("%d", &upper_bound);

    // Generate random number within bounds
    srand(time(NULL));
    answer = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;

    // Game loop
    while(guess != answer)
    {
        // Prompt user for guess
        printf("Guess the number between %d and %d: ", lower_bound, upper_bound);
        scanf("%d", &guess);
        attempts++;

        // Check if guess is correct
        if(guess == answer)
        {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        }
        else if(guess < answer)
        {
            printf("Too low. Try again.\n");
        }
        else
        {
            printf("Too high. Try again.\n");
        }
    }

    return 0;
}