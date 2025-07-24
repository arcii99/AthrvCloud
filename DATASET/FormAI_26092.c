//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for prime number generation
#define MAX 1000
#define MIN 100
#define MAX_ATTEMPTS 10

// Function signatures
int generate_prime();
int gcd(int a, int b);
int mod_pow(int base, int exp, int mod);
int generate_key_pair(int *public_key, int *private_key, int p, int q);

int main()
{
    // Seed the random number generator with current time
    srand(time(NULL));
    
    // Generate two prime numbers for use in public-key encryption
    int p = generate_prime();
    int q = generate_prime();
    
    // Generate public and private keys
    int public_key, private_key;
    int success = generate_key_pair(&public_key, &private_key, p, q);
    if (!success) {
        printf("Error: Failed to generate key pair\n");
        return 1;
    }
    
    // Print out keys
    printf("Public key: %d\n", public_key);
    printf("Private key: %d\n", private_key);
    
    // Encrypt a message using public key
    int message = 1234;
    int encrypted_message = mod_pow(message, public_key, p * q);
    printf("Encrypted message: %d\n", encrypted_message);
    
    // Decrypt the message using private key
    int decrypted_message = mod_pow(encrypted_message, private_key, p * q);
    printf("Decrypted message: %d\n", decrypted_message);
    
    return 0;
}

// Generates a prime number between MIN and MAX
int generate_prime()
{
    int attempts = 0;
    
    while (attempts < MAX_ATTEMPTS) {
        int n = rand() % (MAX - MIN + 1) + MIN;
        int is_prime = 1;
        
        // Check if n is divisible by any number from 2 to n-1
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                is_prime = 0;
                break;
            }
        }
        
        // If n is prime, return it
        if (is_prime) {
            return n;
        }
        
        // Increment no of attempts
        attempts++;
    }
    
    // Failed to generate prime number after MAX_ATTEMPTS attempts
    printf("Error: Failed to generate prime number\n");
    exit(1);
}

// Calculates greatest common divisor of two numbers a and b
int gcd(int a, int b)
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}

// Calculates (base ^ exp) % mod efficiently using repeated squaring
int mod_pow(int base, int exp, int mod)
{
    int result = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    
    return result;
}

// Generates public and private key pairs using Euclid's Algorithm
int generate_key_pair(int *public_key, int *private_key, int p, int q)
{
    // Calculate modulus and totient
    int modulus = p * q;
    int totient = (p - 1) * (q - 1);

    // Choose a random integer e such that 1 < e < totient and gcd(e, totient) = 1
    int e;
    do {
        e = rand() % totient + 1;
    } while (gcd(e, totient) != 1);

    // Calculate d such that (d * e) % totient = 1
    int d;
    int k = 1;
    while (1) {
        int temp = (1 + k * totient) % e;
        if (temp == 0) {
            d = (1 + k * totient) / e;
            break;
        }
        k++;
    }
    
    // Set keys and return success
    *public_key = e;
    *private_key = d;
    return 1;
}