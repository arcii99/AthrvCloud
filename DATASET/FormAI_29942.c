//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: future-proof
#include<stdio.h>

//Function to check if a number is prime or not
int isPrime(int num)
{
    for(int i=2; i<=num/2; i++)
    {
        if(num%i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n, i, j;
    printf("Enter the number of prime numbers you want: ");
    scanf("%d", &n);
    
    //Declaring the array to store the prime numbers
    int primes[n];
    
    for(i=2, j=0; j<n; i++)
    {
        //Checking if the number is prime
        if(isPrime(i))
        {
            primes[j] = i;
            j++;
        }
    }
    
    //Printing the prime numbers stored in the array
    printf("The first %d prime numbers are: ", n);
    for(i=0; i<n; i++)
    {
        printf("%d ", primes[i]);
    }
    
    return 0;
}