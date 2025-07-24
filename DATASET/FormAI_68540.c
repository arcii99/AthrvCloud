//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: grateful
#include <stdio.h>

int main()
{
    int n, i, j;
    printf("Enter the upper limit for the prime numbers: ");
    scanf("%d", &n);

    int primes[n+1];
    for(i=2; i<=n; i++)
    {
        primes[i] = 1;
    }

    for(i=2; i*i<=n; i++)
    {
        if(primes[i])
        {
            for(j=i*i; j<=n; j+=i)
            {
                primes[j] = 0;
            }
        }
    }

    printf("The prime numbers up to %d are:\n", n);
    for(i=2; i<=n; i++)
    {
        if(primes[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}