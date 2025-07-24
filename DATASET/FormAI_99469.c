//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a 16-bit integer type for our algorithm
typedef unsigned short int uint16;

/* Define structure for our public and private keys */
typedef struct {
    uint16 key;
    uint16 n;
} pk_t;

typedef struct {
    uint16 p;
    uint16 q;
    uint16 d;
} sk_t;

/* Define a helper function for getting the greatest common divisor of two numbers */
uint16 gcd(uint16 a, uint16 b) {
    uint16 temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/* Define a helper function for generating a random prime number */
uint16 generate_prime() {
    uint16 n, i, j;
    int is_prime;
    do {
        n = rand() % 65535 + 1; // Generate a random number
        is_prime = 1;
        for (i = 2; i <= n/2; i++) { // Check if it is prime
            if (n % i == 0) {
                is_prime = 0;
                break;
            }
        }
    } while (!is_prime);
    return n;
}

/* Define function for generating a public and private key pair */
void generate_keys(pk_t *pk, sk_t *sk) {
    uint16 p, q, n, phi_n, e, d;
    p = generate_prime(); // Generate first prime number
    q = generate_prime(); // Generate second prime number
    while (p == q) { // If the prime numbers are the same, generate a new one for q
        q = generate_prime();
    }
    n = p * q;
    phi_n = (p - 1) * (q - 1);
    e = 65537; // Commonly used value for e
    while (gcd(e, phi_n) != 1) { // Generate a new value for e if it is not relatively prime with phi_n
        e++;
    }
    d = 0;
    for (uint16 i = 1; i < phi_n; i++) { // Calculate the multiplicative inverse of e modulo phi_n for d
        if ((i * e) % phi_n == 1) {
            d = i;
            break;
        }
    }
    pk->key = e;
    pk->n = n;
    sk->p = p;
    sk->q = q;
    sk->d = d;
}

/* Define function for encrypting a message */
void encrypt(char *message, pk_t pk, char *cipher) {
    uint16 m, c, i;
    for (i = 0; i < strlen(message); i++) {
        m = (uint16) message[i];
        c = 1;
        for (uint16 j = 0; j < pk.key; j++) {
            c = (c * m) % pk.n;
        }
        cipher[i] = (char) c;
    }
    cipher[i] = '\0';
}

/* Define function for decrypting a message */
void decrypt(char *cipher, sk_t sk, char *message) {
    uint16 c, m, i;
    for (i = 0; i < strlen(cipher); i++) {
        c = (uint16) cipher[i];
        m = 1;
        for (uint16 j = 0; j < sk.d; j++) {
            m = (m * c) % (sk.p * sk.q);
        }
        message[i] = (char) m;
    }
    message[i] = '\0';
}

int main() {
    srand(time(NULL)); // Initialize random number generator
    pk_t pk;
    sk_t sk;
    char message[100];
    char cipher[100];
    char decrypted_message[100];
    printf("Please enter a message to encrypt: ");
    scanf("%[^\n]%*c", message); // Read in user input until newline character is encountered
    generate_keys(&pk, &sk); // Generate key pair
    encrypt(message, pk, cipher); // Encrypt message with public key
    decrypt(cipher, sk, decrypted_message); // Decrypt message with private key
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", cipher);
    printf("Decrypted message: %s\n", decrypted_message);
    return 0;
}