//FormAI DATASET v1.0 Category: Dice Roller ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Definition of the main function */
int main()
{
    int number, sides, rolls, i, j;
    int total = 0;
    char answer;
    srand(time(0)); /* Seed the random number generator with the current time */

    do {
        /* Prompt the user for input */
        printf("Enter the number of dice, number of sides, and number of rolls: ");
        scanf("%d %d %d", &number, &sides, &rolls);

        if (number <= 0 || sides <= 0 || rolls <= 0) {
            /* Error message: input cannot be negative or zero*/
            printf("Error: Input values must be positive and non-zero\n");
        }
        else {
            /* Roll the dice and display the results */
            printf("Rolling %d %d-sided dice %d times...\n", number, sides, rolls);
            for (i = 0; i < rolls; i++) {
                int sum = 0;
                printf("Roll %d: ", i + 1);
                for (j = 0; j < number; j++) {
                    int roll = rand() % sides + 1;
                    printf("%d ", roll);
                    sum += roll;
                }
                total += sum;
                printf("(Total: %d)\n", sum);
            }

            /* Display the overall total and option to roll again*/
            printf("Overall total: %d\n", total);
            printf("Roll again? (y/n): ");
            scanf(" %c", &answer);

            /* Reset the total*/
            total = 0;
        }

    } while (answer == 'y' || answer == 'Y'); /* Keep looping until the user enters 'n' or 'N' */

    return 0; /* End of the program */
}