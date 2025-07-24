//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: recursive
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n, int i)
{
    if(i == 1)
        return true;

    if(n % i == 0)
        return false;

    return is_prime(n, i-1);
}

void print_primes(int n)
{
    if(n <= 1)
        return;
    
    print_primes(n-1);
    
    if(is_prime(n, n-1))
        printf("%d ", n);
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Prime numbers: ");
    print_primes(num);

    return 0;
}