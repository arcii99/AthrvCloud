//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: energetic
#include <stdio.h>

int main()
{
    int num, i, prime;

    printf("Enter a number to generate prime numbers: ");
    scanf("%d", &num);

    printf("\nThe prime numbers generated are: ");
    
    for(i=2; i<=num; i++)
    {
        prime = 1;

        for(int j=2; j<=i/2; j++)
        {
            if(i%j==0)
            {
                prime = 0;
                break;
            }
        }

        if(prime==1)
        {
            printf("%d ", i);
        }
    }

    return 0;
}