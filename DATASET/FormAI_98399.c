//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: beginner-friendly
#include <stdio.h>

int main()
{
    int n, i, isPrime;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("The prime numbers from 1 to %d are:\n", n);

    for (i = 2; i <= n; i++)
    {
        isPrime = 1;

        for (int j = 2; j <= i/2; j++)
        {
            if (i % j == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if (isPrime == 1)
        {
            printf("%d ", i);
        }
    }
    return 0;
}