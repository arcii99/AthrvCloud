//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: multivariable
#include<stdio.h>
#include<math.h>

int isPrime(int n);

int main()
{
    int n, i, j, count = 1;
    printf("Enter the number of prime numbers to be generated: ");
    scanf("%d", &n);

    printf("The first %d prime numbers are:\n", n);
    printf("%-10d ", 2); // Printing the first prime number i.e 2, Adjusting the spaces between the numbers

    for(i = 3; count < n; i += 2)  // Starting from 3, since 2 has already been printed, increments are in steps of 2 since every next number is odd
    {
        if(isPrime(i))  // Checking if the number is prime or not
        {
            printf("%-10d ", i); // If prime, printing the number, adjusting the spaces between the numbers
            count++;    // Incrementing the counter of generated primes
        }
    }
    return 0;
}

int isPrime(int n)
{
    int i;
    if(n == 2)  // 2 is the smallest prime number, hence a special case
        return 1;
    if(n % 2 == 0)  // If the number is even, it is not prime
        return 0;
    for(i = 3; i <= sqrt(n); i += 2)    // Checking for prime numbers from 3 to sqrt(n) in steps of 2
    {
        if(n % i == 0)  // If divisible, the number is not prime
            return 0;
    }
    return 1;   // If the number passes all the above checks, it is prime
}