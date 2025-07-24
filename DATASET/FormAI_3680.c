//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to calculate the modulus of two numbers
int modulus(int a, int b)
{
    int result = a % b;
    if(result < 0) result += b;
    return result;
}

// Function to calculate the greatest common divisor of two numbers using Euclid's algorithm
int gcd(int a, int b)
{
    int temp;
    while(b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to generate a random prime number
int generate_prime(int min, int max)
{
    int num = rand() % (max - min + 1) + min;
    while(1)
    {
        int i;
        for(i = 2; i <= sqrt(num); i++)
        {
            if(num % i == 0) break;
        }
        if(i > sqrt(num)) return num;
        num++;
    }
}

// Function to generate public and private keys
void generate_keys(int p, int q, int* n, int* e, int* d)
{
    *n = p * q;
    int phi = (p - 1) * (q - 1);
    *e = generate_prime(2, phi - 1);
    while(gcd(*e, phi) != 1)
    {
        *e = generate_prime(2, phi - 1);
    }
    int k = 1;
    while(1)
    {
        int temp = (k * phi + 1) / *e;
        if((k * phi + 1) % *e == 0 && gcd(temp, phi) == 1) break;
        k++;
    }
    *d = modulus((k * phi + 1) / *e, phi);
}

// Function to encrypt a message using public key
int encrypt(int message, int e, int n)
{
    return (int) pow(message, e) % n;
}

// Function to decrypt a message using private key
int decrypt(int message, int d, int n)
{
    return (int) pow(message, d) % n;
}

// Driver function
int main()
{
    srand(time(NULL));
    int p = generate_prime(100, 500); // Generate first prime number
    int q = generate_prime(500, 1000); // Generate second prime number
    int n, e, d;
    generate_keys(p, q, &n, &e, &d); // Generate public and private keys
    printf("p: %d, q: %d, n: %d, e: %d, d: %d\n", p, q, n, e, d);
    int message = 123456; // Message to be encrypted
    int encrypted_message = encrypt(message, e, n); // Encrypt the message
    printf("Encrypted message: %d\n", encrypted_message);
    int decrypted_message = decrypt(encrypted_message, d, n); // Decrypt the message
    printf("Decrypted message: %d\n", decrypted_message);
    return 0;
}