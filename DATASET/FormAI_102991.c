//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Linus Torvalds
/* The following program is an implementation of the RSA public-key
 * encryption algorithm. It generates a public and a private key pair, and
 * uses them to encrypt and decrypt messages. 
 *
 * Implemented by [Enter your name] in a Linus Torvalds style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

// Function to check if a number is prime.
bool is_prime(long int num)
{
    if (num <= 1)
        return false;
    for (long int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

// Function to calculate the greatest common divisor of two numbers.
long int gcd(long int a, long int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

// Function to generate a random prime number.
long int generate_prime()
{
    long int num;
    do {
        num = rand() % 1000 + 1000; // Generate a number between 1000 and 2000.
    } while (!is_prime(num));
    return num;
}

// Function to generate the public and private keys.
void generate_key_pair(long int *pub_key, long int *pri_key, long int p, long int q)
{
    long int n = p * q;
    long int t = (p - 1) * (q - 1);
    long int e, d;

    // Generate public key.
    do {
        e = rand() % t + 1;
    } while (gcd(e, t) != 1);
    *pub_key = e;

    // Generate private key.
    long int k = 1;
    do {
        k += t;
        d = (1 + k * t) / e;
    } while (d * e % t != 1);
    *pri_key = d;
}

// Function to encrypt a message using the public key.
long int encrypt(long int msg, long int pub_key, long int n)
{
    long int c = 1;
    for (int i = 0; i < pub_key; i++) {
        c = (c * msg) % n;
    }
    return c;
}

// Function to decrypt a message using the private key.
long int decrypt(long int c, long int pri_key, long int n)
{
    long int m = 1;
    for (int i = 0; i < pri_key; i++) {
        m = (m * c) % n;
    }
    return m;
}

int main()
{
    srand(time(NULL)); // Initialize random seed.

    // Generate two prime numbers and calculate their product.
    long int p = generate_prime();
    long int q = generate_prime();
    long int n = p * q;

    // Generate public and private keys.
    long int pub_key, pri_key;
    generate_key_pair(&pub_key, &pri_key, p, q);

    // Print key pair.
    printf("Public key: %ld\n", pub_key);
    printf("Private key: %ld\n", pri_key);

    // Encrypt and decrypt a message.
    long int msg = 123456789;
    long int c = encrypt(msg, pub_key, n);
    long int m = decrypt(c, pri_key, n);
    printf("Original message: %ld\n", msg);
    printf("Encrypted message: %ld\n", c);
    printf("Decrypted message: %ld\n", m);

    return 0;
}