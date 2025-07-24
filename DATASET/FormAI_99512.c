//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: energetic
#include <stdio.h>

int main()
{
    int n, i, flag;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n == 1)
    {
        printf("1 is neither prime nor composite.\n");
        return 0;
    }

    printf("Prime numbers between 1 and %d are: ", n);

    // loop through all the numbers up to n
    for (i = 2; i <= n; i++)
    {
        // assume that the number is prime
        flag = 1;

        // check if i is divisible by any number up to i/2
        for (int j = 2; j <= i/2; j++)
        {
            if (i % j == 0)
            {
                // i is not a prime number
                flag = 0;
                break;
            }
        }

        // if i is a prime number, print it
        if (flag == 1)
        {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}