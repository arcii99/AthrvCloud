//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: random
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n)
{
    if (n < 2) return false; // 1 is not prime
    
    // check divisibility by numbers up to the square root of n
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;

    return true;
}

void print_primes(int n)
{
    printf("The first %d prime numbers are:", n);
    int count = 0, i = 2;
    while (count < n) {
        if (is_prime(i)) {
            printf(" %d", i);
            count += 1;
        }
        i++;
    }
}

int main()
{
    printf("Welcome to the Prime Number Generator!\n");
    printf("How many prime numbers do you want to generate? ");
    int n;
    scanf("%d", &n);
    print_primes(n);
    printf("\nThank you for using the Prime Number Generator!");
    return 0;
}