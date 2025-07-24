//FormAI DATASET v1.0 Category: Scientific ; Style: sophisticated
//Example program to implement the Sieve of Eratosthenes algorithm in C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//Function to print the prime numbers within a range
void printPrimeNumbers(int n)
{
    //Declaring an array to hold the value of prime numbers within a given range
    bool primeNumbers[n+1];
    //Initializing all the values within the array to true
    for(int i=0;i<=n;i++)
    {
        primeNumbers[i]=true;
    }

    //Iterating through all the values to find and mark all non-prime numbers
    for(int i=2;i<=sqrt(n);i++)
    {
        if(primeNumbers[i]==true)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                primeNumbers[j]=false;
            }
        }
    }

    //Printing all prime numbers within the given range
    printf("The prime numbers within the range 1 to %d are:\n",n);
    for(int i=2;i<=n;i++)
    {
        if(primeNumbers[i]==true)
        {
            printf("%d ",i);
        }
    }
}

int main()
{
    int range;
    printf("Enter the upper limit for finding prime numbers: ");
    scanf("%d",&range);
    printPrimeNumbers(range);
    return 0;
}