//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

// function to calculate modulo
int calculate_modulo(int base, int exponent, int modulus) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

int main() {
    // p and q are two large prime numbers
    int p = 11;
    int q = 13;

    // calculate n and phi
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // choose an integer e such that 1 < e < phi and gcd(e, phi) = 1
    int e = 7;
    while (e < phi) {
        if (calculate_modulo(e, 1, phi) == 1) {
            break;
        }
        e++;
    }

    // calculate d such that d*e ≡ 1 (mod phi)
    int k = 2;
    int d = (1 + (k * phi)) / e;

    // public key is (n, e) and private key is (n, d)
    printf("Public Key (n, e) = (%d, %d)\n", n, e);
    printf("Private Key (n, d) = (%d, %d)\n", n, d);

    // message to be encrypted
    int message = 9;

    // encrypt the message using public key
    int encrypted_message = calculate_modulo(message, e, n);

    // decrypt the message using private key
    int decrypted_message = calculate_modulo(encrypted_message, d, n);

    printf("Message: %d\n", message);
    printf("Encrypted Message: %d\n", encrypted_message);
    printf("Decrypted Message: %d\n", decrypted_message);

    return 0;
}