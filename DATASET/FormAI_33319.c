//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define PRIME_LEN 64
#define MESSAGE_SIZE 200

typedef unsigned long long uint64_t;
typedef unsigned int uint32_t; 

uint64_t gcd(uint64_t a, uint64_t b)
{
    if(b == 0) 
        return a;
    return gcd(b, a % b); 
}

int is_prime(uint64_t n)
{
    uint64_t i;
    
    if(n < 2)
        return 0;
    
    for(i=2;i*i<=n;i++)
        if(n % i == 0)
            return 0;
    return 1;
}

uint64_t random_prime()
{
    uint64_t p;
    do
    {
        p = rand();
        p = (p << 32) | rand();
        p = (p & ~1) | 1; 
    }
    while(!is_prime(p)); 
    return p;
}

uint64_t mod_pow(uint64_t base, uint64_t exponent, uint64_t modulus)
{
    uint64_t result = 1;
    while(exponent > 0)
    {   
        if(exponent & 1)
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exponent >>= 1;
    }
    return result; 
}

int main()
{
    uint64_t p, q, n, phi, e, d, m, c;
    char message[MESSAGE_SIZE];
    printf("Enter message: ");
    fgets(message, MESSAGE_SIZE, stdin);
    printf("Message: %s\n", message);
    printf("Generating primes...\n");
    srand((unsigned int)time(NULL));
    p = random_prime();
    q = random_prime();
    printf("p = %lld, q = %lld\n", p, q);
    n = p*q;
    phi = (p - 1) * (q - 1);
    printf("n = %lld, phi = %lld\n", n, phi);
    do
        e = rand() % phi;
    while(gcd(e, phi) != 1); 
    printf("Public key: {%lld, %lld}\n", e, n);
    d = 1;
    while((d * e) % phi != 1) d++;
    printf("Private key: {%lld, %lld}\n", d, n);
    m = (uint64_t)message[0];
    printf("Message: %lld\n", m);
    c = mod_pow(m, e, n);
    printf("Encrypted message: %lld\n", c);
    m = mod_pow(c, d, n);
    printf("Decrypted message: %lld\n", m);
    printf("Decrypted message as text: %c\n", (char)m);
    return 0;
}