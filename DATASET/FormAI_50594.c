//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to calculate modular exponentiation
long long int fast_modular_exponentiation(long long int base, long long int exponent, long long int modulus)
{
    long long int result = 1;

    // Loop until exponent becomes zero
    while(exponent > 0)
    {
        if(exponent % 2 == 1)
        {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }

    return result;
}

// Function to calculate greatest common divisor
long long int gcd(long long int a, long long int b)
{
    if(b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int main()
{
    srand(time(NULL)); // Seed for random number generator
    long long int p, q, n, phi, e, d, message, ciphertext, plaintext;

    // Step 1: Select two prime numbers
    p = 53; // Replace with function that finds a prime number
    q = 59; // Replace with function that finds a prime number

    // Step 2: Calculate n, the modulus
    n = p * q;

    // Step 3: Calculate phi(n), Euler's totient function
    phi = (p - 1) * (q - 1);

    // Step 4: Select an integer e, 1 < e < phi(n), such that gcd(e, phi(n)) = 1
    do
    {
        e = rand() % (phi - 2) + 2;
    } while(gcd(e, phi) != 1);

    // Step 5: Calculate d, the modular multiplicative inverse of e modulo phi(n)
    long long int k = 1;
    while((k * phi + 1) % e != 0)
    {
        k++;
    }
    d = (k * phi + 1) / e;

    // Step 6: Display public key (e, n)
    printf("\nPublic Key: (%lld, %lld)\n\n", e, n);

    // Step 7: Display private key (d, n)
    printf("Private Key: (%lld, %lld)\n\n", d, n);

    // Step 8: Enter the message
    printf("Enter the message to be encrypted: ");
    scanf("%lld", &message);

    // Step 9: Encrypt the message
    ciphertext = fast_modular_exponentiation(message, e, n);

    // Step 10: Display the ciphertext
    printf("\nCiphertext: %lld\n\n", ciphertext);

    // Step 11: Decrypt the message
    plaintext = fast_modular_exponentiation(ciphertext, d, n);

    // Step 12: Display the plaintext
    printf("Plaintext: %lld\n\n", plaintext);

    return 0;
}