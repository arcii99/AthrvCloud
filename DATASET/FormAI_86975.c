//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: authentic
#include <stdio.h>

int main()
{
    int num, prime, i, flag;

    printf("Enter the limit: ");
    scanf("%d", &num);

    // For every number in the range, check if it is prime or not
    for(prime=2; prime<=num; prime++)
    {
        flag = 0; // Reset the flag for every iteration

        // Check if the number is prime or not
        for(i=2; i<=prime/2; i++)
        {
            if(prime%i == 0)
            {
                flag = 1; // Set flag if number is not prime
                break;
            }
        }

        // If the number is prime, print it
        if(flag == 0 && prime != 1)
        {
            printf("%d ", prime);
        }
    }

    return 0;
}