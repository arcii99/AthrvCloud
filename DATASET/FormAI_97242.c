//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PRIME_MIN 100
#define PRIME_MAX 1000
#define ASCII_CHAR_MIN 33
#define ASCII_CHAR_MAX 126

// Function to check if a given number is prime
int check_prime(int num) {
    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate a random prime number between PRIME_MIN and PRIME_MAX
int generate_prime() {
    int prime = 0;
    while (!prime) {
        prime = (rand() % (PRIME_MAX - PRIME_MIN + 1)) + PRIME_MIN;
        if (!check_prime(prime)) {
            prime = 0;
        }
    }
    return prime;
}

// Function to generate a random character between ASCII_CHAR_MIN and ASCII_CHAR_MAX
char generate_char() {
    return (char)((rand() % (ASCII_CHAR_MAX - ASCII_CHAR_MIN + 1)) + ASCII_CHAR_MIN);
}

// Function to generate a public key
void generate_key(int *n, int *e) {
    int p, q;
    // Generate two random prime numbers p and q
    p = generate_prime();
    q = generate_prime();
    // Calculate n and e
    *n = p * q;
    *e = ((p - 1) * (q - 1)) + 1;
}

// Function to encrypt a message using the public key
void encrypt(char *message, int len, int n, int e) {
    int i;
    printf("\nEncrypted Message: ");
    for (i = 0; i < len; i++) {
        printf("%c", (char)pow((int)message[i], e) % n);
    }
}

int main() {
    srand(time(NULL));
    char message[50];
    int n, e, len, i;
    // Generate a public key
    generate_key(&n, &e);
    printf("Public Key Generated: n=%d e=%d", n, e);
    // Get input message from user
    printf("\nEnter Message: ");
    fgets(message, 50, stdin);
    len = strlen(message);
    // Encrypt message using the public key
    encrypt(message, len, n, e);
    printf("\n");
    return 0;
}