//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: secure
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n);

int main()
{
    int limit, i;
    printf("Enter the limit to generate prime numbers: ");
    scanf("%d", &limit);

    printf("Prime numbers between 2 and %d are: \n", limit);

    // loop through each number from 2 to the limit
    for (i = 2; i <= limit; i++)
    {
        if (isPrime(i))
        {
            printf("%d\n", i);
        }
    }

    return 0;
}

// function to check if a number is prime or not
bool isPrime(int n)
{
    int i;
    // loop through all numbers from 2 to n-1
    for (i = 2; i < n; i++)
    {
        // if n is divisible by i, it is not prime
        if (n % i == 0)
        {
            return false;
        }
    }
    // if n is not divisible by any i, it is prime
    return true;
}