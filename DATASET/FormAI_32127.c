//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

#define PRIME_1 65537
#define PRIME_2 16777259

uint32_t gcd(uint32_t a, uint32_t b)
{
    while(b!=0)
    {
        uint32_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

uint32_t extended_gcd(uint32_t a, uint32_t b, uint32_t *x, uint32_t *y)
{
    if(a % b == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    uint32_t x1, y1;
    uint32_t d = extended_gcd(b, a % b, &x1, &y1);
    *x = y1 - (a / b) * x1;
    *y = x1;
    return d;
}

uint32_t modular_inverse(uint32_t a, uint32_t m)
{
    uint32_t x, y;
    extended_gcd(a, m, &x, &y);
    if(x < 0)
        x += m;
    return x;
}

uint32_t generate_prime()
{
    static uint32_t primes[] = {3, 7, 13, 31, 61, 127, 251, 509, 1021, 2039, 4093, 8191, 16381, 32749, 65521, PRIME_1, PRIME_2};
    return primes[rand() % 16];
}

uint32_t power_modulo(uint32_t base, uint32_t exponent, uint32_t modulo)
{
    uint32_t result = 1;
    while(exponent > 0)
    {
        if(exponent % 2 == 1)
            result = (result * base) % modulo;
        base = (base * base) % modulo;
        exponent = exponent / 2;
    }
    return result;
}

void generate_keys(uint32_t *public_key, uint32_t *private_key)
{
    uint32_t p, q, n, phi, e, d;
    p = generate_prime();
    q = generate_prime();
    n = p * q;
    phi = (p - 1) * (q - 1);
    e = generate_prime();
    while(gcd(phi, e) != 1)
        e = generate_prime();
    d = modular_inverse(e, phi);
    *public_key = ((uint64_t)e << 32) | n;
    *private_key = ((uint64_t)d << 32) | n;
}

void encrypt_message(uint32_t *encrypted, uint32_t message, uint32_t public_key)
{
    uint32_t e = public_key >> 32;
    uint32_t n = public_key & 0x00000000FFFFFFFF;
    *encrypted = power_modulo(message, e, n);
}

void decrypt_message(uint32_t *decrypted, uint32_t encrypted, uint32_t private_key)
{
    uint32_t d = private_key >> 32;
    uint32_t n = private_key & 0x00000000FFFFFFFF;
    *decrypted = power_modulo(encrypted, d, n);
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    uint32_t public_key, private_key;
    generate_keys(&public_key, &private_key);
    printf("Public key: %u\n", public_key);
    printf("Private key: %u\n", private_key);
    uint32_t message = 12345;
    uint32_t encrypted;
    uint32_t decrypted;
    encrypt_message(&encrypted, message, public_key);
    printf("Encrypted message: %u\n", encrypted);
    decrypt_message(&decrypted, encrypted, private_key);
    printf("Decrypted message: %u\n", decrypted);
    return 0;
}