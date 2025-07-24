//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Generate a random prime number within a given range
int randomPrime(int min, int max) {
    int num = 0;
    int isPrime = 0;
    
    while (!isPrime) {
        num = rand() % (max - min + 1) + min;
        isPrime = 1;
        
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }
    
    return num;
}

// Calculate gcd using Euclid's algorithm
int gcd(int a, int b) {
    int temp;
    
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    
    return a;
}

// Generate a random number coprime to a given number
int randomCoprime(int num) {
    int coprime = rand() % num + 1;
    
    while (gcd(num, coprime) != 1) {
        coprime = rand() % num + 1;
    }
    
    return coprime;
}

// Calculate modular exponentiation using square and multiply algorithm
int modularExponentiation(int base, int exponent, int mod) {
    int result = 1;
    
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        
        base = (base * base) % mod;
        exponent /= 2;
    }
    
    return result;
}

// Calculate the private key using Extended Euclid's algorithm
int calculatePrivateKey(int e, int phi) {
    int d = 0;
    int x1 = 0, x2 = 1, y1 = 1, y2 = 0;
    int q, r, temp;
    
    while (phi != 0) {
        q = e / phi;
        r = e % phi;
        
        e = phi;
        phi = r;
        
        temp = x2;
        x2 = x1 - q * x2;
        x1 = temp;
        
        temp = y2;
        y2 = y1 - q * y2;
        y1 = temp;
    }
    
    if (x1 < 0) {
        d = x1 + y1*abs(x1+phi)/abs(y1);
    } else {
        d = x1;
    }
    
    return d;
}

int main() {
    int p, q, n, phi, e, d, message, encrypted, decrypted;
    
    srand(time(NULL));
    
    // Generate p and q, two random prime numbers
    p = randomPrime(10, 100);
    q = randomPrime(10, 100);
    
    // Calculate n as the product of p and q
    n = p * q;
    
    // Calculate phi as the Euler totient function of n
    phi = (p - 1) * (q - 1);
    
    // Generate e, a random number coprime to phi
    e = randomCoprime(phi);
    
    // Calculate d, the modular multiplicative inverse of e modulo phi
    d = calculatePrivateKey(e, phi);
    
    printf("Public key: (%d, %d)\n", n, e);
    printf("Private key: (%d, %d)\n", n, d);
    
    // Encrypt and decrypt a message using the public and private keys
    message = 42;
    encrypted = modularExponentiation(message, e, n);
    decrypted = modularExponentiation(encrypted, d, n);
    
    printf("Original message: %d\n", message);
    printf("Encrypted message: %d\n", encrypted);
    printf("Decrypted message: %d\n", decrypted);
    
    return 0;
}