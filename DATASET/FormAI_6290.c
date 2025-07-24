//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Structure to store the public key
struct PublicKey {
    int n;
    int e;
};

// Structure to store the private key
struct PrivateKey {
    int n;
    int d;
};

// function to generate a random prime number between 1 and 1000
int getPrime() {
    int num, i;
    srand(time(0)); // set the seed for random number generation
    do {
        num = rand() % MAX_SIZE + 1; // generate a random number between 1 and 100
        // check if the number is prime
        for (i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                break;
            }
        }
    } while (i <= num / 2); // repeat the loop until a prime number is generated
    return num;
}

// function to calculate the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// function to generate public and private keys
void generateKeys(struct PublicKey *pubKey, struct PrivateKey *privKey) {
    int p, q, n, phi, e, d;

    // generate two prime numbers
    p = getPrime();
    q = getPrime();

    // calculate n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);

    // choose e such that 1 < e < phi and gcd(e, phi) = 1
    srand(time(0)); // set the seed for random number generation
    do {
        e = rand() % phi + 1;
    } while (gcd(e, phi) != 1);

    // calculate d such that d is the multiplicative inverse of e modulo phi
    int k = 1;
    while (1) {
        k += phi;
        if (k % e == 0) {
            d = k / e;
            break;
        }
    }

    // store the values in the public and private key structures
    pubKey->n = n;
    pubKey->e = e;
    privKey->n = n;
    privKey->d = d;
}

// function to encrypt a message using the public key
void encrypt(struct PublicKey pubKey, char *message, int *encrypted) {
    int i, len = strlen(message);
    for (i = 0; i < len; i++) {
        encrypted[i] = (int) message[i];
        encrypted[i] = (int) pow(encrypted[i], pubKey.e) % pubKey.n; // encrypt using public key
    }
}

// function to decrypt a message using the private key
void decrypt(struct PrivateKey privKey, int *encrypted, char *decrypted) {
    int i, len = strlen(encrypted);
    for (i = 0; i < len; i++) {
        decrypted[i] = (char) pow(encrypted[i], privKey.d) % privKey.n; // decrypt using private key
    }
    decrypted[i] = '\0'; // add null terminator at the end
}

int main() {
    struct PublicKey pubKey;
    struct PrivateKey privKey;
    char message[MAX_SIZE];
    int i, len, encrypted[MAX_SIZE];
    char decrypted[MAX_SIZE];

    // generate public and private keys
    generateKeys(&pubKey, &privKey);

    // get the message from the user
    printf("Enter a message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);
    len = strlen(message);
    if (message[len - 1] == '\n') {
        message[len - 1] = '\0'; // remove the newline character
    }

    // encrypt the message using the public key
    encrypt(pubKey, message, encrypted);

    // decrypt the message using the private key
    decrypt(privKey, encrypted, decrypted);

    // print the original message, encrypted message, and decrypted message
    printf("Original message: %s\n", message);
    printf("Encrypted message: ");
    for (i = 0; i < len; i++) {
        printf("%d ", encrypted[i]);
    }
    printf("\nDecrypted message: %s\n", decrypted);

    return 0;
}