//FormAI DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>

/* Function to check if a given integer is prime or not */
int isPrime(int num)
{
    int i;
    if(num < 2) 
    {
        return 0;
    }
    for(i = 2; i <= num/2; i++)
    {
        if(num%i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int i, n, count = 0;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Prime numbers between 1 and %d are:\n", n);
    for (i = 2; i <= n; i++)
    {
        if(isPrime(i))
        {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTotal number of prime numbers between 1 and %d is %d\n", n, count);
    return 0;
}