//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: safe
#include<stdio.h>

//function to check if a number is prime
int isPrime(int n)
{
    if(n<=1)
        return 0;
    for(int i=2; i<=n/2; i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

//function to generate prime numbers
int primeGenerator(int n)
{
    int num = 2, count = 0;
    printf("The first %d prime numbers are: \n", n);
    while(count<n)
    {
        if(isPrime(num))
        {
            printf("%d ", num);
            count++;
        }
        num++;
    }
}

//main function
int main()
{
    int n;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);
    primeGenerator(n);
    return 0;
}