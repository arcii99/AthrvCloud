//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Linus Torvalds
#include <stdio.h>

int is_prime(int n)
{
    int i;

    if (n < 2)
        return 0;

    for (i = 2; i < n; ++i)
        if (n % i == 0)
            return 0;

    return 1;
}

int main()
{
    int n, i;

    printf("Enter the number of prime numbers: ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("Invalid input!\n");
        return 1;
    }

    printf("The first %d prime numbers are: ", n);

    for (i = 2; n > 0; ++i)
        if (is_prime(i))
        {
            printf("%d ", i);
            --n;
        }

    return 0;
}