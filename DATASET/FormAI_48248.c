//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <math.h>

// Function to generate a random prime number
uint64_t generate_prime()
{
    uint64_t num = (uint64_t) rand() % 100 + 100;
    int is_prime = 0;

    while (!is_prime)
    {
        is_prime = 1;
        for (uint64_t i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                is_prime = 0;
                break;
            }
        }
        if (!is_prime)
        {
            num++;
        }
    }

    return num;
}

// Function to calculate gcd of two numbers
uint64_t gcd(uint64_t a, uint64_t b)
{
    uint64_t temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the value of (a^x)%p in log(n) time
uint64_t power_modulo(uint64_t a, uint64_t x, uint64_t p)
{
    uint64_t res = 1;
    a = a % p;
    while (x > 0)
    {
        if (x & 1)
        {
            res = (res * a) % p;
        }
        x = x >> 1;
        a = (a * a) % p;
    }
    return res;
}

// Function to generate a public and private key pair
void generate_key_pair(uint64_t* public_key, uint64_t* private_key)
{
    // Generate two random prime numbers
    uint64_t p = generate_prime();
    uint64_t q = generate_prime();

    // Calculate n and phi(n)
    uint64_t n = p * q;
    uint64_t phi_n = (p - 1) * (q - 1);

    // Choose a random number e such that gcd(e, phi_n) = 1
    uint64_t e;
    do
    {
        e = rand() % phi_n + 1;
    } while (gcd(e, phi_n) != 1);

    // Calculate d such that d*e % phi_n = 1
    uint64_t d = 0;
    while (power_modulo(e, d, phi_n) != 1)
    {
        d++;
    }

    // Set the public and private keys
    *public_key = e;
    *private_key = d;
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Generate a public and private key pair
    uint64_t public_key, private_key;
    generate_key_pair(&public_key, &private_key);

    // Print the public and private keys
    printf("Public key: %lu\n", public_key);
    printf("Private key: %lu\n", private_key);

    return 0;
}