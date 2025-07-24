//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the prime number size
#define PRIME_SIZE 11

// Define the maximum message size
#define MAX_MSG_SIZE 100

// Define the public key structure
typedef struct {
    int n; // Public modulus
    int e; // Public exponent
} PublicKey;

// Define the private key structure
typedef struct {
    int d; // Private exponent
} PrivateKey;

// Define the prime number array
const int primes[PRIME_SIZE] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

// Function to test if a number is prime
bool isPrime(int n) {
    int i;
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate a random prime number
int generateRandomPrime() {
    int index = rand() % PRIME_SIZE;
    int prime = primes[index];
    while (!isPrime(prime)) {
        index = rand() % PRIME_SIZE;
        prime = primes[index];
    }
    return prime;
}

// Function to calculate the greatest common divisor of two numbers
int gcd(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

// Function to calculate the modular exponentiation of a number
int modExp(int base, int exponent, int modulus) {
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

// Function to generate public and private keys
void generateKeys(PublicKey *publicKey, PrivateKey *privateKey) {
    int p, q, n, phi, e, d;
    p = generateRandomPrime();
    q = generateRandomPrime();
    n = p * q;
    phi = (p - 1) * (q - 1);
    e = 2;
    while (gcd(e, phi) != 1) {
        e++;
    }
    d = 1;
    while ((d * e) % phi != 1) {
        d++;
    }
    publicKey->n = n;
    publicKey->e = e;
    privateKey->d = d;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate the keys
    PublicKey publicKey;
    PrivateKey privateKey;
    generateKeys(&publicKey, &privateKey);
    
    // Get the message from the user
    char message[MAX_MSG_SIZE];
    printf("Enter message to encrypt: ");
    fgets(message, MAX_MSG_SIZE, stdin);

    // Encrypt the message
    int i;
    int encryptedMessage[MAX_MSG_SIZE];
    for (i = 0; message[i] != '\0'; i++) {
        encryptedMessage[i] = modExp(message[i], publicKey.e, publicKey.n);
    }
    encryptedMessage[i] = '\0';
    
    // Decrypt the message
    char decryptedMessage[MAX_MSG_SIZE];
    for (i = 0; encryptedMessage[i] != '\0'; i++) {
        decryptedMessage[i] = modExp(encryptedMessage[i], privateKey.d, publicKey.n);
    }
    decryptedMessage[i] = '\0';
    
    // Print the original message, encrypted message, and decrypted message
    printf("Original Message: %s\n", message);
    printf("Encrypted Message: ");
    for (i = 0; encryptedMessage[i] != '\0'; i++) {
        printf("%d ", encryptedMessage[i]);
    }
    printf("\nDecrypted Message: %s\n", decryptedMessage);
    
    // Exit the program
    return 0;
}