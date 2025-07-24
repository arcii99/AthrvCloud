//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: puzzling
#include <stdio.h>

int is_prime(int); // Function to check if a number is prime
int main()
{
    int n, i, flag = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n == 1) // 1 is not a prime number
    {
        printf("1 is not a prime number.\n");
        return 0;
    }

    printf("The prime numbers between 1 and %d are:\n", n);

    // Check for prime numbers and print them
    for(i=2; i<=n; i++)
    {
        flag = is_prime(i);
        if(flag == 1) 
            printf("%d\n", i);
    }

    return 0;
}

int is_prime(int num)
{
    int i;
    for(i=2; i<=num/2; i++)
    {
        if(num % i == 0) // If number is not prime
        {
            return 0; // Return false
        }
    }
    return 1; // Return true
}