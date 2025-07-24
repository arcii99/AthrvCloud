//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int n)
{
    if(n == 2 || n == 3)
    {
        return 1;
    }
    if(n % 2 == 0 || n == 1)
    {
        return 0;
    }
    for(int i = 3; i <= sqrt(n); i = i + 2)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

// Function to compute the greatest common divisor
int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

// Function to compute modular exponentiation
long long int mod_exp(long long int base, long long int exponent, long long int mod)
{
    long long int result = 1;
    base = base % mod;

    while(exponent > 0)
    {
        if(exponent % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exponent = exponent / 2;
        base = (base * base) % mod;  
    }
    return result;
}

int main()
{
    // Generate two random prime numbers
    int p, q;
    srand(time(0));
    do
    {
        p = rand() % 1000 + 1000;
    }while(!isPrime(p));
    do
    {
        q = rand() % 1000 + 1000;
    }while(!isPrime(q));

    // Calculate n and phi(n)
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Generate a random number e that is coprime with phi(n)
    int e;
    do
    {
        e = rand() % phi;
    }while(gcd(e, phi) != 1);

    // Calculate d, the modular multiplicative inverse of e
    int d = 1;
    while((d * e) % phi != 1)
    {
        d++;
    }

    // Print the public and private keys
    printf("Public key: (%d, %d)\n", n, e);
    printf("Private key: (%d, %d)\n", n, d);

    // Encrypt a message using the public key
    char message[100];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    char encrypted_message[100];
    for(int i = 0; message[i] != '\0'; i++)
    {
        long long int c = mod_exp(message[i], e, n);
        encrypted_message[i] = (char)c;
    }
    encrypted_message[strlen(message)] = '\0';

    // Decrypt the message using the private key
    char decrypted_message[100];
    for(int i = 0; encrypted_message[i] != '\0'; i++)
    {
        long long int m = mod_exp(encrypted_message[i], d, n);
        decrypted_message[i] = (char)m;
    }
    decrypted_message[strlen(encrypted_message)] = '\0';

    // Print the encrypted and decrypted messages
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}