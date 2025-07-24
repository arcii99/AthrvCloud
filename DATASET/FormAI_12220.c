//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_PRIME 1000

int is_prime(int n);
int generate_prime(int max);
int gcd(int a, int b);
int generate_totient(int p, int q);
int generate_key(int totient);
int fast_pow(int base, int exponent, int mod);
int encrypt(int message, int e, int n);
int decrypt(int cipher, int d, int n);

int main()
{
    int p = generate_prime(MAX_PRIME);
    int q = generate_prime(MAX_PRIME);
    int n = p * q;
    int totient = generate_totient(p, q);
    int e = generate_key(totient);
    int d = generate_key(totient);

    printf("Encryption key (e, n): (%d, %d)\n", e, n);
    printf("Decryption key (d, n): (%d, %d)\n", d, n);

    srand(time(NULL));
    int message = rand() % n;

    printf("Original message: %d\n", message);

    int cipher = encrypt(message, e, n);

    printf("Cipher text: %d\n", cipher);

    int decrypted_message = decrypt(cipher, d, n);

    printf("Decrypted message: %d\n", decrypted_message);

    return 0;
}

int is_prime(int n)
{
    if (n <= 1)
        return 0;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int generate_prime(int max)
{
    int prime = rand() % max;

    while (!is_prime(prime))
    {
        prime = rand() % max;
    }

    return prime;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int generate_totient(int p, int q)
{
    return (p - 1) * (q - 1);
}

int generate_key(int totient)
{
    int key = rand() % totient;

    while (gcd(key, totient) != 1)
    {
        key = rand() % totient;
    }

    return key;
}

int fast_pow(int base, int exponent, int mod)
{
    int result = 1;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exponent = exponent / 2;
        base = (base * base) % mod;
    }

    return result;
}

int encrypt(int message, int e, int n)
{
    return fast_pow(message, e, n);
}

int decrypt(int cipher, int d, int n)
{
    return fast_pow(cipher, d, n);
}