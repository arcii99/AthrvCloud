//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: portable
#include <stdio.h>

int is_prime(int n)
{
    int i;
    if (n <= 1)
    {
        return 0;
    }
    else
    {
        for (i = 2; i <= n - 1; i++)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}

void generate_prime(int n)
{
    int i, count = 0;
    printf("First %d prime numbers are: \n", n);
    for (i = 2; count < n; i++)
    {
        if (is_prime(i))
        {
            printf("%d ", i);
            count++;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);
    generate_prime(n);
    return 0;
}