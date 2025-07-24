//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: funny
#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime or not
bool isPrime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i <= num/2; i++)
        if (num % i == 0)
            return false;
    return true;
}

// Function to generate prime numbers
void generatePrimeNumbers(int max)
{
    printf("Generating prime numbers...\n");
    for (int i = 2; i <= max; i++)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    printf("Done!");
}

int main()
{
    int max;
    printf("Welcome to the Prime Number Generator Program!\n");
    printf("Enter the maximum number up to which you want to generate prime numbers: ");
    scanf("%d", &max);
    printf("Hold tight! The program is working its magic...\n");
    generatePrimeNumbers(max);
    return 0;
}