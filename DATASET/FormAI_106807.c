//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to compute the greatest common divisor of two integers
int gcd(int a, int b) {
    if (b > a) {
        int temp = a;
        a = b;
        b = temp;
    }
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to generate a random prime number between the given bounds
int generate_prime(int lower_bound, int upper_bound) {
    srand(time(NULL));
    int prime;
    do {
        prime = rand() % (upper_bound - lower_bound + 1) + lower_bound;
    } while (prime % 2 == 0 || prime % 3 == 0 || prime % 5 == 0);
    int i;
    for (i = 7; i <= sqrt(prime); i += 2) {
        if (prime % i == 0) {
            break;
        }
    }
    if (i <= sqrt(prime)) {
        return generate_prime(lower_bound, upper_bound);
    } else {
        return prime;
    }
}

// Function to calculate the modular inverse of a number
int modular_inverse(int a, int b) {
    int b0 = b, t, q;
    int x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1 && b != 0) {
        q = a / b;
        t = b;
        b = a % b;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
}

// Function to encrypt a message using the RSA algorithm
int* rsa_encrypt(int message, int e, int n) {
    int* ciphertext = malloc(2 * sizeof(int));
    ciphertext[0] = (int)(pow(message, e)) % n;
    ciphertext[1] = n;
    return ciphertext;
}

// Function to decrypt a ciphertext using the RSA algorithm
int rsa_decrypt(int* ciphertext, int d) {
    int message = (int)(pow(ciphertext[0], d)) % ciphertext[1];
    return message;
}

int main() {
    int p = generate_prime(100, 1000);
    int q = p;
    while (q == p) {
        q = generate_prime(100, 1000);
    }
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 2;
    while (gcd(phi, e) != 1) {
        e++;
    }
    int d = modular_inverse(e, phi);
    printf("Public key (e, n): (%d, %d)\n", e, n);
    printf("Private key (d): %d\n", d);
    int message;
    printf("Enter a message to encrypt: ");
    scanf("%d", &message);
    int* ciphertext = rsa_encrypt(message, e, n);
    printf("Ciphertext is: {%d, %d}\n", ciphertext[0], ciphertext[1]);
    int decrypted_message = rsa_decrypt(ciphertext, d);
    printf("Decrypted message is: %d\n", decrypted_message);
    return 0;
}