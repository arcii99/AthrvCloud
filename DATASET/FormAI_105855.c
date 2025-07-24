//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: recursive
#include <stdio.h>

int isPrime(int num, int divisor);

int main()
{
    int limit, i;
    
    printf("Enter a limit to generate prime numbers: ");
    scanf("%d", &limit);
    
    printf("Prime numbers within the range of 2 to %d are:\n", limit);
    for(i=2; i<=limit; i++)
    {
        if(isPrime(i, i/2)) // only check up to n/2 factors
            printf("%d\n", i);
    }
    
    return 0;
}

int isPrime(int num, int divisor)
{
    if(divisor == 1) // base case
        return 1; // prime
    else if(num % divisor == 0)
        return 0; // not prime
    else
        return isPrime(num, divisor-1); // recursive call with decremented divisor
}