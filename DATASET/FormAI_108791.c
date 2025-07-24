//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int num, i, j;
    bool is_prime;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("All Prime numbers between 1 and %d are:\n", num);

    /* loop through all numbers between 2 and num */
    for (i = 2; i <= num; i++)
    {
        is_prime = true;

        /* check if the number is divisible by any number between 2 and i/2 */
        for (j = 2; j <= i/2; j++)
        {
            if (i % j == 0)
            {
                is_prime = false;
                break;
            }
        }

        /* if the number is prime, print it */
        if (is_prime)
        {
            printf("%d ", i);
        }
    }

    printf("\nPress any key to continue...");
    getchar();
    return 0;
}