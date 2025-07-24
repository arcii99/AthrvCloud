//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* Function to check if a given number is prime number or not */
bool isPrime(int num)
{
    int i;
    if(num==1)
        return false; // 1 is not a prime number
    for(i=2;i<=num/2;i++)
    {
        if(num%i==0)
            return false; // Non-prime number
    }
    return true; // Prime number
}

/* Function to generate and print prime numbers */
void generatePrimes(int start, int end)
{
    int i;
    printf("\nPrime numbers between %d and %d are: ", start, end);
    for(i=start;i<=end;i++)
    {
        if(isPrime(i))
            printf("%d ",i);
    }
}

int main()
{
    int start, end;
    printf("Enter starting and ending numbers: ");
    scanf("%d %d", &start, &end);
    generatePrimes(start, end);
    printf("\n");
    return 0;
}