//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: optimized
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void generate_primes(int limit)
{
    for (int i = 2; i <= limit; i++)
    {
        if (is_prime(i))
            printf("%d ", i);
    }
}

int main()
{
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    generate_primes(limit);
    return 0;
}