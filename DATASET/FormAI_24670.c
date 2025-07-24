//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: mathematical
#include<stdio.h>

int is_prime(int n); // function to check if a number is prime
void generate_primes(int n); // function to generate prime numbers

int main()
{
    int n;

    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);

    generate_primes(n); // generating prime numbers
    return 0;
}

int is_prime(int n)
{
    int i;

    if(n <= 1) // 1 is not prime
        return 0;

    for(i=2; i*i<=n; i++)
    {
        if(n%i == 0) // if n is divisible by i, it's not prime
            return 0;
    }

    return 1; // else it's prime
}

void generate_primes(int n)
{
    int i, j=0;

    printf("First %d prime numbers:\n", n);

    for(i=2; j<n; i++)
    {
        if(is_prime(i)) // checking if i is prime
        {
            printf("%d ", i);
            j++; // incrementing the count of prime numbers generated
        }
    }
}