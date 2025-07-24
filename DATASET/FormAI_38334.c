//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int n);
void generate_primes(int n);

int main()
{
    int num;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &num);
    generate_primes(num);
    return 0;
}

bool is_prime(int n)
{
    if(n <= 1)
        return false;
    for(int i=2; i<=n/2; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

void generate_primes(int n)
{
    int count = 0;
    int num = 2;
    while(count < n)
    {
        if(is_prime(num))
        {
            printf("%d ", num);
            count++;
        }
        num++;
    }
}