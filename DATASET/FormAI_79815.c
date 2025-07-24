//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i, j, flag;
    printf("Enter the number of prime numbers to be generated: ");
    scanf("%d", &n);
    int primes[n];
    primes[0] = 2;
    int count = 1;
    i = 3;

    while(count < n)
    {
        flag = 0;

        for(j = 2; j < i; j++)
        {
            if(i % j == 0)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            primes[count] = i;
            count++;
        }

        i++;
    }

    printf("Prime numbers generated are: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", primes[i]);
    }

    return 0;
}