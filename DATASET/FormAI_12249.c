//FormAI DATASET v1.0 Category: Educational ; Style: authentic
#include<stdio.h>

/* A program to find the prime numbers within a given range */

int main()
{
    int start, end, i, j, flag;
    printf("Enter the starting range: ");
    scanf("%d", &start);
    printf("Enter the ending range: ");
    scanf("%d", &end);
    printf("The prime numbers within the given range are: \n");
    
    // Loop to iterate through all the numbers within the given range
    for(i=start; i<=end; i++)
    {
        flag = 0; // To check if the number is prime or not
        // Loop to check if the number is divisible by any of the preceding numbers
        
        for(j=2; j<=i/2; j++)
        {
            if(i%j==0)
            {
                flag = 1;
                break;
            }
        }
        // If the number is not divisible by any number, then it is prime
        
        if(flag==0 && i>1)
        {
            printf("%d ", i);
        }
    }
    return 0;
}