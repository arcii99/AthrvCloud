//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Define the maximum primality test iterations
#define MAX_PRIMALITY_TEST_ITERATIONS 1000

// Define the maximum Euclid's algorithm iterations
#define MAX_EUCLID_ALGORITHM_ITERATIONS 1000

// Define the maximum modulo inverse iterations
#define MAX_MODULO_INVERSE_ITERATIONS 1000

// Define the maximum plaintext message length
#define MAX_PLAINTEXT_LENGTH 100

// Function to check if a number is prime
int is_prime(int num) {
    if(num < 2) {
        return 0; // not prime
    }
    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) {
            return 0; // not prime
        }
    }
    return 1; // prime
}

// Function to compute the greatest common divisor of two numbers
int gcd(int a, int b) {
    int temp;
    int iteration = 0;
    while(b != 0 && iteration < MAX_EUCLID_ALGORITHM_ITERATIONS) {
        temp = b;
        b = a % b;
        a = temp;
        iteration++;
    }
    if(iteration == MAX_EUCLID_ALGORITHM_ITERATIONS) {
        printf("Error: Maximum Euclid's algorithm iterations reached.\n");
        exit(1);
    }
    return a;
}

// Function to compute a modulo b for positive integers a and b
int modulo(int a, int b) {
    int result = a % b;
    if(result < 0) {
        result += b;
    }
    return result;
}

// Function to compute the modulo inverse of a number a mod m
int modulo_inverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;
    int iteration = 0;
    if (m == 1) {
        return 0;
    }
    while (a > 1 && iteration < MAX_MODULO_INVERSE_ITERATIONS) {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
        iteration++;
    }
    if(iteration == MAX_MODULO_INVERSE_ITERATIONS) {
        printf("Error: Maximum modulo inverse iterations reached.\n");
        exit(1);
    }
    if (x < 0) {
        x += m0;
    }
    return x;
}

// Function to generate a random prime number in the range [start, end]
int generate_random_prime(int start, int end) {
    int num;
    int iteration = 0;
    while(iteration < MAX_PRIMALITY_TEST_ITERATIONS) {
        num = rand() % (end - start + 1) + start;
        if(is_prime(num)) {
            return num;
        }
        iteration++;
    }
    printf("Error: Maximum primality test iterations reached.\n");
    exit(1);
}

// Function to generate the public and private keys
void generate_keys(int *p, int *q, int *n, int *e, int *d) {
    // Generate two random prime numbers
    *p = generate_random_prime(100, 1000);
    *q = generate_random_prime(100, 1000);
    // Compute n and phi(n)
    *n = (*p) * (*q);
    int phi_n = (*p - 1) * (*q - 1);
    // Choose e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1
    *e = 2; // start with 2 as the initial value of e
    while(gcd(*e, phi_n) != 1) {
        *e += 1;
    }
    // Compute d such that d is the modular inverse of e mod phi(n)
    *d = modulo_inverse(*e, phi_n);
}

// Function to encrypt a message using the RSA public key algorithm
void encrypt_message(int *message, int length, int n, int e, int *encrypted_message) {
    for(int i = 0; i < length; i++) {
        encrypted_message[i] = modulo((int)pow(message[i], e), n);
    }
}

// Function to decrypt a message using the RSA private key algorithm
void decrypt_message(int *encrypted_message, int length, int n, int d, int *decrypted_message) {
    for(int i = 0; i < length; i++) {
        decrypted_message[i] = modulo((int)pow(encrypted_message[i], d), n);
    }
}

int main() {
    srand(time(NULL));
    int p, q, n, e, d;
    generate_keys(&p, &q, &n, &e, &d);
    printf("Public Key (n, e): (%d, %d)\n", n, e);
    printf("Private Key (n, d): (%d, %d)\n", n, d);
    // take plaintext message as input from user
    char plaintext[MAX_PLAINTEXT_LENGTH];
    printf("Enter plaintext message: ");
    fgets(plaintext, MAX_PLAINTEXT_LENGTH, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // remove newline character
    // convert plaintext message to integer array
    int plaintext_len = strlen(plaintext);
    int plaintext_int[plaintext_len];
    for(int i = 0; i < plaintext_len; i++) {
        plaintext_int[i] = (int)plaintext[i];
    }
    // encrypt the message using the public key
    int encrypted_message[plaintext_len];
    encrypt_message(plaintext_int, plaintext_len, n, e, encrypted_message);
    printf("Encrypted message: ");
    for(int i = 0; i < plaintext_len; i++) {
        printf("%d ", encrypted_message[i]);
    }
    printf("\n");
    // decrypt the message using the private key
    int decrypted_message[plaintext_len];
    decrypt_message(encrypted_message, plaintext_len, n, d, decrypted_message);
    printf("Decrypted message: ");
    for(int i = 0; i < plaintext_len; i++) {
        printf("%c", (char)decrypted_message[i]);
    }
    printf("\n");
    return 0;
}