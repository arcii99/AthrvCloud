//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: invasive
#include<stdio.h>
#include<math.h>

int main()
{
    int limit, i, j, isPrime;

    printf("Enter the limit: ");
    scanf("%d", &limit);

    printf("The prime numbers between 2 and %d are:\n", limit);

    for(i=2; i<=limit; i++)
    {
        isPrime = 1;
        
        for(j=2; j<=sqrt(i); j++)
        {
            if(i%j == 0)
            {
                isPrime = 0;
                break;
            }
        }
        
        if(isPrime == 1)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}