//FormAI DATASET v1.0 Category: Random ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This is a program to generate a random sequence of number
 * Note: The algorithm will generate random numbers between 1 and 10
 * and will terminate when a 7 is generated.
 */

int main() {
    int num, i = 0;
    char another;

    srand(time(0)); /* Seed the random number generator */

    do {
        num = rand() % 10 + 1; /* Generate random number between 1 to 10 */
        printf("%d ", num); /* Print the generated number */

        /* Check if the generated number is 7 */
        if (num == 7) {
            printf("\n\nGeneration terminated as 7 was generated.\n");
            break; /* Exit the loop */
        }

        i++; /* Increment the counter */

        /* Ask the user if they want to generate another number */
        printf("\nDo you want to generate another number? (y/n): ");
        scanf("%s", &another);

        /* Check if the user wants to continue */
        if (another == 'n') {
            printf("\n\nGeneration terminated as requested by the user.\n");
            break; /* Exit the loop */
        }
    } while (1); /* Infinite loop until break statement reached */

    /* Print the total number of generated numbers */
    printf("\n\nTotal number of generated numbers: %d\n", i);

    return 0;
}