//FormAI DATASET v1.0 Category: Scientific ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void find_prime_factors(int n);

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    find_prime_factors(n);
    return 0;
}

void find_prime_factors(int n)
{
    int i, j, is_prime;

    printf("Prime factors of %d are: ",n);

    for(i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            is_prime = 1;
            for(j=2; j<=sqrt(i); j++)
            {
                if(i%j==0)
                {
                    is_prime = 0;
                    break;
                }
            }
            if(is_prime == 1)
                printf("%d ",i);
        }
    }
}