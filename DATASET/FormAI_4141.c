//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: automated
#include <stdio.h>
#include <stdlib.h>

void find_prime_numbers(int n)
{
    int is_prime = 1;   //boolean variable indicating if number is prime or not

    for(int i = 2; i <= n; i++)
    {
        is_prime = 1;   // assuming it's prime initially

        for(int j = 2; j <= i/2; j++)
        {
            if(i%j == 0)    // if number is not prime
            {
                is_prime = 0;   // set flag to false
                break;
            }
        }

        if(is_prime == 1)   // if number is prime
        {
            printf("%d, ", i);  // print it
        }
    }
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Prime numbers less than or equal to %d:\n", n);
    find_prime_numbers(n);

    return 0;
}