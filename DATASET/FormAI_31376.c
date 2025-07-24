//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: paranoid
#include <stdio.h>
#include <stdbool.h>

/* Function to check if a number is prime */
bool is_prime(int num) 
{
    if (num <= 1)
        return false;
    for (int i = 2; i < num; i++)
        if (num % i == 0)
            return false;
    return true;
}

/* Function to generate prime numbers */
void generate_primes(int n)
{
    int primes_found = 0; // How many primes have we found so far?
    int current_number = 2; // Start searching for primes at 2

    while (primes_found < n) {
        if (is_prime(current_number)) {
            printf("%d ", current_number);
            primes_found++;
        }
        current_number++;
    }
    
    printf("\nTotal of %d prime numbers found\n", primes_found);
}

/* Main function */
int main(void)
{
    int n;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input, please enter a positive integer!\n");
        return 1; // Signal error
    }
    
    generate_primes(n);
    
    return 0; // Success
}