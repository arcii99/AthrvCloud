//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: beginner-friendly
#include <stdio.h>

int main()
{
    int num;
    int i,j;
    int isPrime;

    //Take input from user
    printf("Enter the maximum number till which you want to generate prime numbers: ");
    scanf("%d",&num);

    //Checking for prime numbers
    for(i=2;i<=num;i++)
    {
        isPrime=1;    //Assuming it is a prime number

        for(j=2;j<=i/2;j++)
        {
            if(i%j==0)
            {
                isPrime=0;   //If number is divisible by any other number, it is not a prime
                break;
            }
        }

        if(isPrime==1)
        {
            printf("%d ",i);   //Printing prime numbers
        }

    }

    return 0;
}