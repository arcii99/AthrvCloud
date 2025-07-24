//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: scientific
/* 
   * C Public-Key Algorithm Implementation
   * 
   * This program implements a public key algorithm in C. 
   * The algorithm generates a public and private key pair, then encrypts and decrypts messages using those keys.
   * It is based on the RSA cryptosystem. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_DIGITS 1000 // Maximum number of digits for our big numbers

// Helper function to compute the greatest common divisor of two numbers
int gcd(int a, int b) {
    while (a != 0) {
        int temp = a;
        a = b % a;
        b = temp;
    }
    return b;
}

// Helper function to compute the power of a number (mod n)
int mod_pow(int base, int exponent, int n) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % n;
        }
        base = (base * base) % n;
        exponent = exponent / 2;
    }
    return result;
}

// Helper function to randomly initialize an array with digits between 0 and 9
void random_initialize(int *a, int size) {
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 10;
    }
}

// Helper function to print a big number to the console
void print_number(int *a, int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", a[i]);
    }
}

// Helper function to calculate the size of a big number
int size_of_number(int *a, int size) {
    int i;
    for (i = size - 1; i >= 0; i--) {
        if (a[i] != 0) {
            break;
        }
    }
    return i + 1;
}

// Helper function to add two big numbers together
void add(int *a, int *b, int size, int *c) {
    int carry = 0;
    for (int i = 0; i < size; i++) {
        int sum = a[i] + b[i] + carry;
        c[i] = sum % 10;
        carry = sum / 10;
    }
}

// Helper function to multiply two big numbers together
void multiply(int *a, int *b, int size_a, int size_b, int *c) {
    for (int i = 0; i < size_a; i++) {
        int carry = 0;
        for (int j = 0; j < size_b; j++) {
            int product = a[i] * b[j] + carry + c[i + j];
            c[i + j] = product % 10;
            carry = product / 10;
        }
        c[i + size_b] += carry;
    }
}

// Helper function to calculate the private key using the Extended Euclidean Algorithm
int extended_euclidean(int e, int phi_n) {
    int old_r = phi_n, r = e;
    int old_s = 1, s = 0;
    while (r != 0) {
        int quotient = old_r / r;
        int temp = r;
        r = old_r - quotient * r;
        old_r = temp;
        temp = s;
        s = old_s - quotient * s;
        old_s = temp;
    }
    if (old_s < 0) {
        old_s += phi_n;
    }
    return old_s;
}

// Main function to generate a public and private key pair and test the algorithm
int main() {
    // First we generate two large prime numbers p and q
    srand(time(NULL));
    int p[MAX_DIGITS] = {0}, q[MAX_DIGITS] = {0};
    int p_size = 50, q_size = 50;
    random_initialize(p, p_size);
    random_initialize(q, q_size);
    int n[MAX_DIGITS] = {0};
    multiply(p, q, p_size, q_size, n);
    int phi_n[MAX_DIGITS] = {0};
    int p_minus_one[MAX_DIGITS] = {0}, q_minus_one[MAX_DIGITS] = {0};
    p_minus_one[0] = 1;
    q_minus_one[0] = 1;
    int p_minus_one_size = 1, q_minus_one_size = 1;
    for (int i = 0; i < p_size; i++) {
        if (p[i] != 0) {
            p[i] -= 1;
            break;
        }
        p[i] = 9;
    }
    for (int i = 0; i < q_size; i++) {
        if (q[i] != 0) {
            q[i] -= 1;
            break;
        }
        q[i] = 9;
    }
    multiply(p, q, p_size, q_size, phi_n);

    // Find e such that gcd(e, phi_n) = 1
    int e = 2;
    while (gcd(e, phi_n[0]) != 1) {
        e++;
    }
    int public_key[MAX_DIGITS] = {e};
    int private_key[MAX_DIGITS] = {extended_euclidean(e, phi_n[0])};

    // Encrypt and decrypt a message using the keys
    char message[] = "Hello, World!";
    int message_ascii[MAX_DIGITS] = {0};
    int encrypted_message[MAX_DIGITS] = {0}, decrypted_message[MAX_DIGITS] = {0};
    for (int i = 0; i < strlen(message); i++) {
        message_ascii[i] = message[i];
    }
    int encrypted_message_size = 0, decrypted_message_size = 0;
    for (int i = 0; i < strlen(message); i++) {
        // Encrypt using public key
        int x = mod_pow(message_ascii[i], e, n[0]);
        encrypted_message[i] = x;
        if (x != 0) {
            encrypted_message_size = i + 1;
        }

        // Decrypt using private key
        x = mod_pow(encrypted_message[i], private_key[0], n[0]);
        decrypted_message[i] = x;
        if (x != 0) {
            decrypted_message_size = i + 1;
        }
    }

    // Print out the results
    printf("p = ");
    print_number(p, p_size);
    printf("\nq = ");
    print_number(q, q_size);
    printf("\nn = ");
    print_number(n, size_of_number(n, MAX_DIGITS));
    printf("\nphi_n = ");
    print_number(phi_n, size_of_number(phi_n, MAX_DIGITS));
    printf("\nPublic key: (%d, %d)\n", e, n[0]);
    printf("Private key: (%d, %d)\n", private_key[0], n[0]);
    printf("Original message: %s\n", message);
    printf("Encrypted message: ");
    for (int i = encrypted_message_size - 1; i >= 0; i--) {
        printf("%d ", encrypted_message[i]);
    }
    printf("\nDecrypted message: ");
    for (int i = decrypted_message_size - 1; i >= 0; i--) {
        printf("%c", decrypted_message[i]);
    }
    printf("\n");

    return 0;
}