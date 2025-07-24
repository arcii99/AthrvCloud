//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define MIN 1

/**
 * A cheerful implementation of Public-Key Algorithm using prime numbers.
 * 
 * This program generates two distinct prime numbers and calculates the 
 * public and private keys using those prime numbers.
 * 
 * When the user enters a message, the message is encrypted using the 
 * public key and decrypted using the private key.
 */

int gcd(int a, int b);
int choose_e(int phi_n);
int choose_d(int e, int phi_n);
int power(int x, unsigned int y, int p);
int is_prime(int n);
int generate_prime_number(int min, int max);

int main()
{
    // Seed the random number generator
    srand(time(NULL));
    
    int p, q, n, phi_n, e, d, message;
    
    // Generate two distinct prime numbers
    do {
        p = generate_prime_number(MIN, MAX);
        q = generate_prime_number(MIN, MAX);
    } while (p == q);
    
    // Calculate n and phi(n)
    n = p * q;
    phi_n = (p - 1) * (q - 1);
    
    // Choose e
    e = choose_e(phi_n);
    
    // Choose d
    d = choose_d(e, phi_n);
    
    // Display public and private keys to user
    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n\n", d, n);
    
    // Ask user for a message to encrypt
    printf("Enter a message to encrypt: ");
    scanf("%d", &message);
    
    // Encrypt the message using public key
    printf("Encrypting message...\n");
    int encrypted_message = power(message, e, n);
    printf("Encrypted message: %d\n", encrypted_message);
    
    // Decrypt the message using private key
    printf("Decrypting message...\n");
    int decrypted_message = power(encrypted_message, d, n);
    printf("Decrypted message: %d\n", decrypted_message);
    
    return 0;
}

/**
 * Calculate the greatest common divisor of two numbers.
 * 
 * @param a The first number
 * @param b The second number
 * @return The greatest common divisor of a and b
 */
int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

/**
 * Choose a value for e
 * 
 * @param phi_n The value of phi(n)
 * @return The value of e
 */
int choose_e(int phi_n) {
    int e;
    
    do {
        e = generate_prime_number(MIN, phi_n);
    } while (gcd(e, phi_n) != 1);
    
    return e;
}

/**
 * Choose a value for d
 * 
 * @param e The value of e
 * @param phi_n The value of phi(n)
 * @return The value of d
 */
int choose_d(int e, int phi_n) {
    int d = 0;
    int k = 1;
    
    while (d == 0) {
        if ((k * phi_n + 1) % e == 0) {
            d = (k * phi_n + 1) / e;
        }
        k++;
    }
    
    return d;
}

/**
 * Calculate base^exponent % modulus
 * 
 * @param x The base
 * @param y The exponent
 * @param p The modulus
 * @return x^y % p
 */
int power(int x, unsigned int y, int p) {
    int res = 1;     // Initialize result
    
    x = x % p; // Update x if it is more than or equal to p
    
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    
    return res;
}

/**
 * Check if a number is prime
 * 
 * @param n The number to check
 * @return 1 if n is prime, 0 otherwise
 */
int is_prime(int n) {
    if (n <= 1) 
        return 0; 
    
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    
    return 1;
}

/**
 * Generate a random prime number between min and max (inclusive)
 * 
 * @param min The minimum value for the prime number
 * @param max The maximum value for the prime number
 * @return A prime number between min and max (inclusive)
 */
int generate_prime_number(int min, int max) {
    int n, flag;
    
    do {
        flag = 0;
        n = rand() % (max - min + 1) + min;
        
        if (!is_prime(n)) {
            flag = 1;
        }
    } while (flag);
    
    return n;
}