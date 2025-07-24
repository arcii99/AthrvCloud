//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: beginner-friendly
#include <stdio.h>

int main()
{
    int num, i, j, isPrime;

    printf("Enter the maximum number to generate prime numbers: ");
    scanf("%d", &num);

    printf("Prime numbers between 1 and %d are: \n", num);

    // loop through all numbers from 2 to num
    for (i = 2; i <= num; i++)
    {
        isPrime = 1; // assume all numbers are prime

        // check if i is prime
        for (j = 2; j <= i/2; j++)
        {
            if (i % j == 0)
            {
                isPrime = 0; // i is not prime
                break;
            }
        }

        // if i is prime, print it
        if (isPrime == 1)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}