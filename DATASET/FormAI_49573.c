//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Function to calculate a^b % c
int power(int a, int b, int c) {
    int res = 1;
    a = a % c;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % c;

        b = b >> 1;
        a = (a * a) % c;
    }
    return res;
}

// Function to generate a random prime number between 2^16 and 2^32
int random_prime(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    while (1) {
        int i;
        for (i = 2; i <= sqrt(num); i++) {
            if (num % i == 0)
                break;
        }
        if (i > sqrt(num))
            return num;
        else {
            num = (rand() % (upper - lower + 1)) + lower;
            continue;
        }
    }
}

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1)
        return 0;
    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

// Function to find gcd of two numbers
int gcd(int num1, int num2) {
    if (num1 == 0)
        return num2;
    return gcd(num2 % num1, num1);
}

// Function to calculate public key
void calc_public_key(int p, int q, int *n_ptr, int *e_ptr) {
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e;
    for (e = phi / 2; e < phi; e++) {
        if (gcd(e, phi) == 1)
            break;
    }
    *n_ptr = n;
    *e_ptr = e;
}

// Function to calculate inverse of a number
int inv(int num, int mod) {
    int m0 = mod, y = 0, x = 1;
    if (mod == 1)
        return 0;
    while (num > 1) {
        int q = num / mod;
        int t = mod;
        mod = num % mod, num = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

// Function to calculate private key
void calc_private_key(int p, int q, int *n_ptr, int *d_ptr) {
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 0;
    int d = inv(e, phi);
    *n_ptr = n;
    *d_ptr = d;
}

// Function to encrypt a message
void encrypt(int *msg, int len, int n, int e, int *cipher) {
    int i;
    for (i = 0; i < len; i++)
        cipher[i] = power(msg[i], e, n);
}

// Function to decrypt a message
void decrypt(int *cipher, int len, int n, int d, int *msg) {
    int i;
    for (i = 0; i < len; i++)
        msg[i] = power(cipher[i], d, n);
}

int main() {
    srand(time(NULL));

    // Generate two random prime numbers
    int p = random_prime((int)pow(2, 16), (int)pow(2, 32));
    int q = random_prime((int)pow(2, 16), (int)pow(2, 32));

    // Calculate public key
    int n, e;
    calc_public_key(p, q, &n, &e);

    // Calculate private key
    int d;
    calc_private_key(p, q, &n, &d);

    // Print public and private keys
    printf("Public Key: (%d, %d)\n", n, e);
    printf("Private Key: (%d, %d)\n", n, d);

    // Encrypt and decrypt a test message
    int msg[] = {72, 69, 76, 76, 79};
    int len = sizeof(msg) / sizeof(int);
    int cipher[len];
    encrypt(msg, len, n, e, cipher);
    int decrypted_msg[len];
    decrypt(cipher, len, n, d, decrypted_msg);

    // Print original message and decrypted message
    printf("Original Message: ");
    int i;
    for (i = 0; i < len; i++)
        printf("%c", msg[i]);
    printf("\nDecrypted Message: ");
    for (i = 0; i < len; i++)
        printf("%c", decrypted_msg[i]);
    printf("\n");

    return 0;
}