//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int count = 1, n = 3, i, isPrime;
    printf("The prime numbers from 2 to 100 are: \n");
    printf("2\n"); //2 is the only even prime number so we print it directly
    while(count <= 24) //We want to print the next 24 prime numbers
    {
        isPrime = 1; //Assuming n is a prime number
        for(i = 2; i <= sqrt(n); ++i) //Checking if n is divisible by any number between 2 and its square root
        {
            if(n % i == 0) //If n is divisible by i, it's not a prime number
            {
                isPrime = 0;
                break;
            }
        }

        if(isPrime) //If n is a prime number, print it
        {
            printf("%d\n", n);
            ++count;
        }
        ++n;
    }

    return 0;
}