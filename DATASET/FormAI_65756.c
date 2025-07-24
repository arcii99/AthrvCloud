//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: energetic
#include <stdio.h>

// Function to check if a number is prime
int isPrime(int n)
{
    if (n <= 1)
        return 0;

    // Check for factors up to n/2
    for (int i = 2; i <= n/2; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

// Implement the C Prime Number Generator
int main()
{
    int num, i = 2;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &num);

    printf("Generating prime numbers...\n");

    // Loop until num prime numbers are found
    while (num > 0)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
            num--;
        }
        i++;
    }

    printf("\n");
    return 0;
}