//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: complete
#include <stdio.h>

int isPrime(int n) // function to check if a number is prime or not
{
    if(n < 2) // 0 and 1 are not prime numbers
        return 0;

    for(int i=2; i<=n/2; i++)
    {
        if(n%i==0)
            return 0;
    }

    return 1;
}

int main()
{
    int n; // to get user input
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Prime numbers between 1 and %d are: ", n);

    for(int i=2; i<=n; i++)
    {
        if(isPrime(i))
            printf("%d ", i);
    }

    return 0;
}