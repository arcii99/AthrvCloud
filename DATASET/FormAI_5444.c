//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define PRIME 19 // prime number used for the calculation of public and private keys
#define MAX_MSG_LEN 100 // maximum length of the input message

// function to calculate the exponentiation of a number
long long exp_mod(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp >> 1;
    }
    return res;
}

// function to calculate the greatest common divisor of two numbers
long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// function to calculate the private key based on the public key and prime number
long long calc_private_key(long long public_key, long long prime) {
    long long i;
    for (i = 1; i < prime; i++) {
        if (((public_key * i) % prime) == 1) {
            return i;
        }
    }
    return -1;
}

int main() {
    char input_msg[MAX_MSG_LEN]; // input message to be encrypted
    long long p, q, n, phi_n, e, d; // prime numbers and keys used for encryption and decryption
    int i;

    printf("Enter a message to be encrypted (max length %d): ", MAX_MSG_LEN);
    fgets(input_msg, MAX_MSG_LEN, stdin); // read input message from user
    printf("Original message: %s\n", input_msg);

    // Step 1: Choose two prime numbers
    printf("Step 1: Choosing two prime numbers...\n");
    p = 7;
    q = 11;
    printf("p = %lld, q = %lld\n", p, q);

    // Step 2: Calculate 'n' by multiplying the two prime numbers
    printf("Step 2: Calculating 'n' by multiplying p and q...\n");
    n = p * q;
    printf("n = %lld\n", n);

    // Step 3: Calculate 'phi_n' using (p-1)*(q-1)
    printf("Step 3: Calculating 'phi_n' using (p-1)*(q-1)...\n");
    phi_n = (p - 1) * (q - 1);
    printf("phi_n = %lld\n", phi_n);

    // Step 4: Choose 'e' such that 1 < e < phi_n and gcd(e, phi_n) = 1
    printf("Step 4: Choosing 'e' such that 1 < e < phi_n and gcd(e, phi_n) = 1...\n");
    for (i = 2; i < phi_n; i++) {
        if (gcd(i, phi_n) == 1) {
            e = i;
            break;
        }
    }
    printf("e = %lld\n", e);

    // Step 5: Calculate 'd' such that d*e = 1 mod phi_n
    printf("Step 5: Calculating 'd' such that d*e = 1 mod phi_n...\n");
    d = calc_private_key(e, phi_n);
    printf("d = %lld\n", d);

    // Step 6: Encrypt the input message using the public key (e, n)
    printf("Step 6: Encrypting the input message using the public key (e, n)...\n");
    printf("Encrypted message: ");
    for (i = 0; input_msg[i] != '\0'; i++) {
        printf("%lld ", exp_mod(input_msg[i], e, n));
    }
    printf("\n");

    // Step 7: Decrypt the encrypted message using the private key (d, n)
    printf("Step 7: Decrypting the encrypted message using the private key (d, n)...\n");
    printf("Decrypted message: ");
    for (i = 0; input_msg[i] != '\0'; i++) {
        printf("%c", (char)exp_mod(exp_mod(input_msg[i], e, n), d, n));
    }
    printf("\n");

    return 0;
}