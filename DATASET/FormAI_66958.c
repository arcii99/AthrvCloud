//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PRIME 1000 // maximum prime number
#define PUBLIC_EXPONENT 65537 // public exponent
#define BUFFER_SIZE 128 // buffer size for file I/O

/* Function prototypes */
int is_prime(int n);
int gcd(int a, int b);
int modexp(int base, int exponent, int mod);
int generate_public_key(int p, int q, int* n, int* e);
void generate_private_key(int p, int q, int e, int* d);
void encrypt(FILE* in, FILE* out, int n, int e);
void decrypt(FILE* in, FILE* out, int d, int n);

/* Generate a prime number */
int generate_prime() {
    int prime;
    do {
        prime = rand() % MAX_PRIME + 2;
    } while (!is_prime(prime));
    return prime;
}

/* Check if a number is prime */
int is_prime(int n) {
    int i;
    if (n < 2) {
        return 0;
    }
    for (i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

/* Find greatest common divisor */
int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/* Modular exponentiation */
int modexp(int base, int exponent, int mod) {
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

/* Generate public key */
int generate_public_key(int p, int q, int* n, int* e) {
    int phi_n = (p - 1) * (q - 1);
    *n = p * q;
    *e = PUBLIC_EXPONENT;
    while (gcd(phi_n, *e) > 1) {
        (*e)++;
    }
    return phi_n;
}

/* Generate private key */
void generate_private_key(int p, int q, int e, int* d) {
    int phi_n = (p - 1) * (q - 1);
    int k = 1;
    while ((1 + k * phi_n) % e != 0) {
        k++;
    }
    *d = (1 + k * phi_n) / e;
}

/* Encrypt file */
void encrypt(FILE* in, FILE* out, int n, int e) {
    char buffer[BUFFER_SIZE];
    int i, m, c;
    while ((m = fread(buffer, sizeof(char), BUFFER_SIZE, in)) > 0) {
        for (i = 0; i < m; i++) {
            c = modexp((int) buffer[i], e, n);
            fprintf(out, "%d ", c);
        }
    }
}

/* Decrypt file */
void decrypt(FILE* in, FILE* out, int d, int n) {
    char buffer[BUFFER_SIZE];
    int i, c, m;
    while (fscanf(in, "%d", &c) != EOF) {
        m = modexp(c, d, n);
        buffer[i++] = (char) m;
        if (i == BUFFER_SIZE) {
            fwrite(buffer, sizeof(char), i, out);
            i = 0;
        }
    }
    if (i > 0) {
        fwrite(buffer, sizeof(char), i, out);
    }
}

/* Main function */
int main() {
    srand(time(NULL));
    int p = generate_prime();
    int q = generate_prime();
    int n, e, d, phi_n;
    phi_n = generate_public_key(p, q, &n, &e);
    generate_private_key(p, q, e, &d);
    FILE* in = fopen("input.txt", "r");
    FILE* out = fopen("output.txt", "w");
    encrypt(in, out, n, e);
    fclose(in);
    fclose(out);
    in = fopen("output.txt", "r");
    out = fopen("decrypted.txt", "w");
    decrypt(in, out, d, n);
    fclose(in);
    fclose(out);
    return 0;
}