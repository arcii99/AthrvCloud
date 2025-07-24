//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: grateful
#include <stdio.h>

int main()
{
    int lower_limit, upper_limit, i, j, is_prime;

    printf("Thank you for using this Prime Number Generator program!\n");
    printf("Please enter the lower limit of the range: ");
    scanf("%d", &lower_limit);
    printf("Please enter the upper limit of the range: ");
    scanf("%d", &upper_limit);

    printf("\nThe prime numbers between %d and %d are: \n", lower_limit, upper_limit);

    // The outer loop iterates over all numbers within the range
    for (i = lower_limit; i <= upper_limit; i++)
    {
        // Assume each number is prime until proven otherwise
        is_prime = 1;

        // The inner loop iterates over all possible factors of the current number
        for (j = 2; j < i; j++)
        {
            if (i % j == 0) // If i is divisible by j, it is not a prime
            {
                is_prime = 0; // Set is_prime to 0 to indicate that it is not prime
                break;
            }
        }

        if (is_prime == 1) // If is_prime is still equal to 1, i is a prime number
        {
            printf("%d\n", i); // Print the prime number
        }
    }

    printf("\nThank you for using this Prime Number Generator program! We hope you found it helpful.\n");
    return 0;
}