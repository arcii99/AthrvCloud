//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRIME_NUM 3 // number of prime numbers used
#define PRIME_ARR {2, 3, 5} // array of prime numbers used
#define MAX_INPUT 1024 // maximum input buffer size

// Function to calculate greatest common divisor of two numbers
int gcd(int a, int b)
{
    int temp;
    while (b > 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate multiplicative inverse of a number using extended euclidean algorithm
int multiplicative_inverse(int a, int b)
{
    int b0 = b, t, q;
    int x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1)
    {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
}

// Function to generate public and private keys
void generate_keys(int *p, int *q, int *e, int *d, int *n)
{
    int i, j, phi_n, totient_n;
    int prime_arr[PRIME_NUM] = PRIME_ARR; // get prime array

    // Get two random prime numbers
    *p = prime_arr[rand() % PRIME_NUM];
    *q = prime_arr[rand() % PRIME_NUM];

    // Calculate n and totient(n) values
    *n = *p * *q;
    totient_n = (*p - 1) * (*q - 1);

    // Get random public key value that is coprime to totient(n)
    do
    {
        *e = rand() % totient_n;
    } while (gcd(*e, totient_n) != 1);

    // Calculate corresponding private key value
    *d = multiplicative_inverse(*e, totient_n);
}

// Function to encrypt a message using public key
void encrypt(char *plaintext, char *ciphertext, int e, int n)
{
    int i = 0, len = strlen(plaintext);
    for (i = 0; i < len; i++)
    {
        ciphertext[i] = (char) ((long long) plaintext[i] * e % n); // Use public key to encrypt message
    }
    ciphertext[i] = '\0';
}

// Function to decrypt a message using private key
void decrypt(char *ciphertext, char *decryptedtext, int d, int n)
{
    int i = 0, len = strlen(ciphertext);
    for (i = 0; i < len; i++)
    {
        decryptedtext[i] = (char) ((long long) ciphertext[i] * d % n); // Use private key to decrypt ciphertext
    }
    decryptedtext[i] = '\0';
}

int main()
{
    int p, q, e, d, n;
    char plaintext[MAX_INPUT], ciphertext[MAX_INPUT], decryptedtext[MAX_INPUT];

    // Get user input for plaintext
    printf("Enter plaintext: ");
    fgets(plaintext, MAX_INPUT, stdin);

    generate_keys(&p, &q, &e, &d, &n); // Generate keys
    encrypt(plaintext, ciphertext, e, n); // Encrypt plaintext
    decrypt(ciphertext, decryptedtext, d, n); // Decrypt ciphertext

    // Print results
    printf("Public Key (e,n): (%d,%d)\n", e, n);
    printf("Private Key (d,n): (%d,%d)\n", d, n);
    printf("Plaintext: %s", plaintext);
    printf("Ciphertext: %s", ciphertext);
    printf("Decryptedtext: %s", decryptedtext);

    return 0;
}