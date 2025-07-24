//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Function to find greatest common divisor */
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

/* Function to generate random prime number */
int generatePrime(int min, int max) {
    int i, j, isPrime;
    for (i = min; i <= max; i++) {
        isPrime = 1;
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime == 1)
            return i;
    }
    return -1;
}

/* Function to generate public and private keys */
void generateKeys(int prime1, int prime2, int *public_key, int *private_key) {
    int n = prime1 * prime2; // Calculate n
    int phi = (prime1 - 1) * (prime2 - 1); // Calculate Euler's totient function phi(n)

    int e = 2;
    while (e < phi) {
        if (gcd(e, phi) == 1) // Finding e, a co-prime of phi(n)
            break;
        else
            e++;
    }
    *public_key = e;

    int k = 0;
    int d = (1 + k * phi) / e; // Finding d, the modular multiplicative inverse of e mod phi(n)
    while (d < n) {
        if ((d * e) % phi == 1) // Checking if d is the modular multiplicative inverse of e mod phi(n)
            break;
        else {
            k++;
            d = (1 + k * phi) / e;
        }
    }
    *private_key = d;
}

/* Function to encrypt plaintext using public key */
int *encrypt(int *plaintext, int plaintext_size, int public_key, int n) {
    int *ciphertext = (int*)malloc(plaintext_size * sizeof(int));
    for (int i = 0; i < plaintext_size; i++) {
        int p = plaintext[i];
        int c = fmod(pow(p, public_key), n); // Calculate ciphertext
        ciphertext[i] = c;
    }
    return ciphertext;
}

/* Function to decrypt ciphertext using private key */
int *decrypt(int *ciphertext, int ciphertext_size, int private_key, int n) {
    int *plaintext = (int*)malloc(ciphertext_size * sizeof(int));
    for (int i = 0; i < ciphertext_size; i++) {
        int c = ciphertext[i];
        int p = fmod(pow(c, private_key), n); // Calculate plaintext
        plaintext[i] = p;
    }
    return plaintext;
}

int main() {
    int min = 2, max = 20;
    int prime1 = generatePrime(min, max); // Generate first prime number
    int prime2 = generatePrime(min, max); // Generate second prime number
    while (prime2 == prime1)
        prime2 = generatePrime(min, max); // Make sure second prime number is not equal to first

    int public_key, private_key;
    generateKeys(prime1, prime2, &public_key, &private_key); // Generate public and private keys
    printf("Public Key (e,n): (%d,%d)\n", public_key, prime1 * prime2);
    printf("Private Key (d,n): (%d,%d)\n", private_key, prime1 * prime2);

    int plaintext[] = {12, 4, 7, 2, 8}; // Plaintext to be encrypted
    int plaintext_size = sizeof(plaintext) / sizeof(plaintext[0]);

    int *ciphertext = encrypt(plaintext, plaintext_size, public_key, prime1 * prime2); // Encrypt plaintext
    printf("Ciphertext: ");
    for (int i = 0; i < plaintext_size; i++)
        printf("%d ", ciphertext[i]);

    int *decrypted_plaintext = decrypt(ciphertext, plaintext_size, private_key, prime1 * prime2); // Decrypt ciphertext
    printf("\nDecrypted Plaintext: ");
    for (int i = 0; i < plaintext_size; i++)
        printf("%d ", decrypted_plaintext[i]);

    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}