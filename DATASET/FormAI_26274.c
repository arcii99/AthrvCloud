//FormAI DATASET v1.0 Category: Random ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Welcome to the magical world of randomness! */

int main()
{
    int i, num, min, max;

    /* Output a welcome message */
    printf("Welcome to the magical world of randomness!\n");

    /* Get user input for the minimum and maximum values */
    printf("Please enter the minimum value for the random numbers: ");
    scanf("%d", &min);
    printf("Thank you. Now, please enter the maximum value: ");
    scanf("%d", &max);

    /* Generate a random number between the specified minimum and maximum values */
    srand(time(0)); // Seed the random number generator
    num = (rand() % (max - min + 1)) + min;

    /* Output the random number */
    printf("Your random number is: %d\n", num);

    /* Let's generate a few more random numbers, just for fun */
    printf("Here are ten more randomly generated numbers between %d and %d:\n", min, max);
    for (i = 0; i < 10; i++) {
        num = (rand() % (max - min + 1)) + min;
        printf("%d\n", num);
    }

    /* Say goodbye and exit gracefully */
    printf("Thank you for visiting the magical world of randomness. Goodbye!\n");
    return 0;

} /* End of main() */