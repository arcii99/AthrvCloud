//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Function to calculate the Greatest Common Divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

// Function to generate prime numbers
int generate_prime_number(int n) {
    int i, j, flag, count = 0;
    srand(time(NULL)); // Seed random number generator
    
    for (i = n; i < n+10000; i++) { // Generate 10,000 prime numbers starting from n
        flag = 1;
        for (j = 2; j <= sqrt(i); j++) { // Check if i is a prime number
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            count++;
            if (count == 10000) { // Return the 10,000th prime number
                return i;
            }
        }
    }
}

// Function to get the multiplicative inverse of a number using Extended Euclidean Algorithm
int get_multiplicative_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1) {
        return 0;
    }
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) {
        x1 += m0;
    }
    return x1;
}

int main() {
    int p, q, n, phi, e, d, msg, enc_msg, dec_msg;
    printf("----Public-Key Algorithm Implementation----\n\n");
    printf("Generating two prime numbers...Please wait.\n");
    // Generate two random prime numbers
    p = generate_prime_number(1000000);
    q = generate_prime_number(p);
    printf("Generated prime numbers are p = %d and q = %d\n", p, q);
    // Calculate n and phi(n)
    n = p * q;
    phi = (p-1) * (q-1);
    // Choose a random integer e such that 1 < e < phi(n) and gcd(e,phi(n)) = 1
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1) {
            break;
        }
    }
    // Calculate d, the multiplicative inverse of e (mod phi(n))
    d = get_multiplicative_inverse(e, phi);
    printf("Public Key: {e = %d, n = %d}\n", e, n);
    printf("Private Key: {d = %d, n = %d}\n\n", d, n);
    printf("Enter the message you want to encrypt: ");
    scanf("%d", &msg);
    // Encryption
    enc_msg = (int) pow(msg, e) % n;
    printf("Encrypted Message is: %d\n", enc_msg);
    // Decryption
    dec_msg = (int) pow(enc_msg, d) % n;
    printf("Decrypted Message is: %d\n\n", dec_msg);
    printf("----End of Program----\n");
    return 0;
}