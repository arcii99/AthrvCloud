//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// function to compute gcd of two integers
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// function to compute modular multiplicative inverse of a mod m using extended euclidean algorithm
int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

// function to generate random prime number between low and high
int gen_prime(int low, int high) {
    int i, j, isprime;
    int num;
    srand(time(NULL));
    do {
        num = rand() % (high - low + 1) + low;
        isprime = 1;
        for (i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                isprime = 0;
                break;
            }
        }
    } while (isprime == 0);
    return num;
}

int main() {
    int p, q, n, phi, e, d, plaintext, ciphertext;
    char ch;
    // generate two random prime numbers
    p = gen_prime(100, 200);
    q = gen_prime(200, 300);
    // compute n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);
    // choose a random e that is coprime to phi
    do {
        e = gen_prime(2, phi - 1);
    } while (gcd(e, phi) != 1);
    // compute the modular multiplicative inverse of e mod phi
    d = mod_inverse(e, phi);
    printf("Public key: {e = %d, n = %d}\n", e, n);
    printf("Private key: {d = %d, n = %d}\n", d, n);
    // ask user for plaintext
    printf("Enter plaintext: ");
    scanf("%c", &ch);
    plaintext = ch;
    // encrypt the plaintext using public key
    ciphertext = fmod(pow(plaintext, e), n);
    printf("Ciphertext: %d\n", ciphertext);
    // decrypt the ciphertext using private key
    plaintext = fmod(pow(ciphertext, d), n);
    printf("Decrypted plaintext: %c\n", plaintext);
    return 0;
}