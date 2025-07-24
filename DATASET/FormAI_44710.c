//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: multiplayer
#include <stdio.h>

// Check if a given number is prime or not
int isPrime(int num)
{
    if (num <= 1)
    {
        return 0;
    }

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int startNum, endNum, primeCount = 0;

    printf("Enter the starting number: ");
    scanf("%d", &startNum);

    printf("Enter the ending number: ");
    scanf("%d", &endNum);

    printf("\nPRIME NUMBERS:\n");

    // Loop through the range of numbers specified
    for (int i = startNum; i <= endNum; i++)
    {
        // Check if the current number is prime
        if (isPrime(i))
        {
            printf("%d ", i);
            primeCount++;
        }
    }

    // Calculate the number of prime numbers found
    printf("\n\nTotal prime numbers found: %d\n", primeCount);

    return 0;
}