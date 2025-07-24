//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: creative
#include <stdio.h>

int main()
{
    int n, i, flag;

    // Ask user for input
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("Prime numbers between 1 and %d are: ", n);

    // All prime numbers less than n
    for (i = 2; i <= n; ++i)
    {
        flag = 0;

        // check if number is prime
        for (int j = 2; j <= i / 2; ++j)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            printf("%d ", i);
    }

    return 0;
}