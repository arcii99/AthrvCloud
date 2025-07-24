//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: rigorous
#include <stdio.h>

int is_prime(int num) // function to check if a number is prime
{
    int i;
    if(num < 2)
        return 0;
    for(i = 2; i*i <= num; i++)
        if(num%i == 0)
            return 0;
    return 1;
}

int main()
{
    int n, count = 0; // variables to store user input and count of prime numbers found
    printf("Enter the range of prime numbers to generate: ");
    scanf("%d", &n);
    printf("The prime numbers between 1 and %d are: \n", n);

    for(int i = 2; i <= n; i++) // loop through all numbers from 2 to n
    {
        if(is_prime(i)) // check if current number is prime
        {
            printf("%d ", i); // print the prime number
            count++; // increment count of prime numbers found
        }
    }
    printf("\nTotal number of prime numbers between 1 and %d is: %d\n", n, count); // print total count of prime numbers found
    return 0;
}