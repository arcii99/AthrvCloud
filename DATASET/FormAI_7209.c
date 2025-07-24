//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to find greatest common divisor
int gcd(int m, int n)
{
    int r;

    while (n > 0)
    {
        r = m % n;
        m = n;
        n = r;
    }

    return m;
}

// Function to check if number is prime
int isPrime(int num)
{
    if (num <= 1)
    {
        return 0;
    }

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

// Function to generate random prime number
int generatePrime(int lower, int upper)
{
    int num = rand() % (upper - lower + 1) + lower;

    while (!isPrime(num))
    {
        num = rand() % (upper - lower + 1) + lower;
    }

    return num;
}

// Function to find modular multiplicative inverse
int modInverse(int a, int m)
{
    int m0 = m;
    int t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
    {
        return 0;
    }

    while (a > 1)
    {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
    {
        x1 = x1 + m0;
    }

    return x1;
}

// Function to encrypt the message
int encrypt(int message, int e, int n)
{
    return ((int)pow(message, e) % n);
}

// Function to decrypt the message
int decrypt(int encoded_message, int d, int n)
{
    return ((int)pow(encoded_message, d) % n);
}

int main()
{
    int p, q;               // prime numbers
    int n, phi, e, d;       // encryption variables
    int message, encoded_message, decrypted_message;
    srand(time(NULL));      // seed for random number generator

    // Generate the prime numbers p and q
    p = generatePrime(100, 500);
    q = generatePrime(100, 500);

    // Calculate n and phi(n)
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Find e such that gcd(e, phi(n)) = 1
    for (e = 2; e < phi; e++)
    {
        if (gcd(e, phi) == 1)
        {
            break;
        }
    }

    // Find d such that ed ≡ 1 (mod phi(n))
    d = modInverse(e, phi);

    printf("Public key: (e = %d, n = %d)\n", e, n);
    printf("Private key: (d = %d, n = %d)\n", d, n);

    // Get message from user
    printf("Enter a number to encrypt: ");
    scanf("%d", &message);

    // Encrypt the message
    encoded_message = encrypt(message, e, n);
    printf("Encrypted message: %d\n", encoded_message);

    // Decrypt the message
    decrypted_message = decrypt(encoded_message, d, n);
    printf("Decrypted message: %d\n", decrypted_message);

    return 0;
}