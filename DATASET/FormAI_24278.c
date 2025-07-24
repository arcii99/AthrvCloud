//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: surprised
#include <stdio.h>

int main() 
{
    int num, i, isPrime;
    printf("Welcome to the Prime Number Generator!\n");
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("The prime numbers between 1 and %d are: \n", num);
    for(i=2; i<=num; i++) 
    {
        isPrime=1;
        for(int j=2; j<=i/2; j++)
        {
            if (i % j==0)
            {
                isPrime = 0;
                break;
            }
        }
        if(isPrime==1)
        {
            printf("%d ",i);
        }
    }
    printf("\nWow! You have generated Prime numbers upto %d\n", num);  
    return 0;
}