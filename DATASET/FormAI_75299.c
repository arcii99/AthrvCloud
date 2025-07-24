//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: shocked
#include <stdio.h>

int check_prime(int n);

int main()
{
    int n, i, prime_flag;
    printf("Enter the number of primes you want to generate: ");
    scanf("%d", &n);
    printf("\n--- Generating %d prime numbers ---\n", n);
    if (n >= 1)
        printf("2 ");
    for (i = 3; i <= n; i += 2)
    {
        prime_flag = check_prime(i);
        if (prime_flag == 1)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}

int check_prime(int n)
{
    int j, flag = 1;
    for (j = 2; j <= n / 2; ++j)
    {
        if (n % j == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}