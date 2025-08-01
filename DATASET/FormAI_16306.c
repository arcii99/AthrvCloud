//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: innovative
#include <stdio.h>

int main()
{
    int n, i, j, flag;
    printf("Enter the number of prime numbers required: ");
    scanf("%d", &n);

    int primes[n], count = 0;

    for (i = 2; count < n; i++)
    {
        flag = 1;
        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            primes[count] = i;
            count++;
        }
    }

    printf("The first %d prime numbers are:\n", n);
    for (i = 0; i < n; i++)
        printf("%d ", primes[i]);
    
    return 0;
}