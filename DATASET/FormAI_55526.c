//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: introspective
#include<stdio.h>

/* This is a program to generate prime numbers within a given limit */ 

int main()
{
    int i, j, n, flag;
    printf("Enter the value of n:");
    scanf("%d", &n);
    printf("Prime numbers between 1 and %d are:\n", n);

    /* Loop through each number from 2 to n and check if it's prime */
    for(i=2; i<=n; i++)
    {
        flag = 0; //set flag to 0 initially
        for(j=2; j<=i/2; j++)
        {
            if(i%j==0)
            {
                flag = 1; //if i is not prime, set flag to 1
                break;
            }
        }
        if(flag==0) //if flag is still 0, i is prime
            printf("%d\n", i);
    }
    return 0;
}