//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function Prototypes
int gcd(int a, int b);
int generate_prime(int min, int max);
int generate_coprime(int phi);
int mod_inv(int a, int m);
int mod_exp(int base, int exponent, int mod);

int main() 
{
    int p, q, n, phi, e, d;

    srand(time(0)); // Set random seed

    // Generate two random primes
    p = generate_prime(999, 9999); 
    q = generate_prime(999, 9999);
    n = p * q; // Calculate n
    phi = (p - 1) * (q - 1); // Calculate phi

    // Generate a random coprime to phi
    e = generate_coprime(phi);

    // Calculate the modular inverse of e mod phi
    d = mod_inv(e, phi);

    printf("Public key: {%d, %d}\n", e, n);
    printf("Private key: {%d, %d}\n", d, n);

    int plaintext, ciphertext, decrypted_text;

    printf("Enter plaintext: ");
    scanf("%d", &plaintext);

    // Encrypt plaintext using public key
    ciphertext = mod_exp(plaintext, e, n);
    printf("Ciphertext: %d\n", ciphertext);

    // Decrypt ciphertext using private key
    decrypted_text = mod_exp(ciphertext, d, n);
    printf("Decrypted text: %d\n", decrypted_text);

    return 0;
}

// Function to calculate GCD of two numbers
int gcd(int a, int b) 
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to generate a random prime number between min and max
int generate_prime(int min, int max) 
{
    int num = rand() % (max - min + 1) + min;
    int is_prime = 0;

    while (!is_prime) 
    {
        int i;
        is_prime = 1;

        for (i = 2; i <= sqrt(num); i++) 
        {
            if (num % i == 0) 
            {
                is_prime = 0;
                break;
            }
        }

        if (!is_prime) 
        {
            num = rand() % (max - min + 1) + min;
        }
    }

    return num;
}

// Function to generate a random integer coprime to parameter phi
int generate_coprime(int phi) 
{
    int num = rand() % phi + 1;

    while (gcd(num, phi) != 1) 
    {
        num = rand() % phi + 1;
    }

    return num;
}

// Function to calculate the modular inverse using Extended Euclidean Algorithm
int mod_inv(int a, int m) 
{
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1 && m > 0) 
    {
        int q = a / m;
        int t = m;

        m = a % m, a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

// Function to compute modular exponentiation
int mod_exp(int base, int exponent, int mod) 
{
    int result = 1;

    while (exponent > 0) 
    {
        if (exponent % 2 == 1) 
        {
            result = (result * base) % mod;
        }

        base = (base * base) % mod;
        exponent /= 2;
    }

    return result;
}