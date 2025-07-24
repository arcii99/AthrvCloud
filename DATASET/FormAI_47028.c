//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Returns the greatest common divisor of two numbers
int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Returns the modular multiplicative inverse of two numbers
int mod_inverse(int a, int b) {
    int b0 = b, t, q;
    int x0 = 0, x1 = 1;
    if (b == 1) return 1;
    
    while (a > 1) {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    
    if (x1 < 0) x1 += b0;
    return x1;
}

// Generates a random prime number
int generate_prime(int lower, int upper) {
    int i, j, flag, num;
    srand(time(NULL));
    for (i = lower; i <= upper; i++) {
        flag = 1;
        for (j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            num = i;
        }
    }
    return num;
}

int main() {
    int p = generate_prime(100, 1000); // Generate a prime number p
    int q = generate_prime(1000, 10000); // Generate another prime number q
    int n = p * q; // Calculate n
    int phi = (p-1) * (q-1); // Calculate phi(n)
    
    int e = 2; // Starting value for e
    while (e < phi) {
        if (gcd(e, phi) == 1) break; // If e is coprime to phi(n), break out of the loop
        else e++;
    }
    
    int d = mod_inverse(e, phi); // Calculate the modular multiplicative inverse of e modulo phi(n)
    
    printf("p = %d\nq = %d\nn = %d\nphi(n) = %d\ne = %d\nd = %d\n", p, q, n, phi, e, d);
    
    int plaintext, ciphertext;
    printf("Enter plaintext: ");
    scanf("%d", &plaintext);
    
    ciphertext = (int)pow(plaintext, e) % n; // Encrypt the plaintext using the public key (e, n)
    printf("Ciphertext: %d\n", ciphertext);
    
    plaintext = (int)pow(ciphertext, d) % n; // Decrypt the ciphertext using the private key (d, n)
    printf("Plaintext: %d\n", plaintext);
    
    return 0;
}