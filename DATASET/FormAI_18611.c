//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: brave
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i*i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}

int main()
{
    int limit;

    printf("Enter the limit: ");
    scanf("%d", &limit);

    printf("The prime numbers between 1 and %d are:\n", limit);
    
    for (int i = 2; i <= limit; i++)
        if (isPrime(i))
            printf("%d ", i);
            
    return 0;
}