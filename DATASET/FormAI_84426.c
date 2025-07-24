//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: thoughtful
#include <stdio.h>

unsigned char S[256]; // S-box
unsigned char K[256]; // Key
unsigned char plaintext[] = "Sample plaintext for demonstration"; // Plaintext to encrypt
unsigned char ciphertext[sizeof(plaintext)]; // Encrypted ciphertext
int i, j;

void KSA(unsigned char *key, int keylen) {
    int i, j = 0;
    unsigned char temp;

    for (i = 0; i < 256; i++)
        S[i] = i;

    for (i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % keylen]) % 256;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }
}

void PRGA(unsigned char *plaintext, unsigned char *ciphertext, int len) {
    int i = 0, j = 0, k, t;
    unsigned char temp;

    for (t = 0; t < len; t++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
        k = S[(S[i] + S[j]) % 256];
        ciphertext[t] = plaintext[t] ^ k;
    }
}

int main() {
    // Set the key
    for (i = 0; i < 256; i++) {
        K[i] = (unsigned char) i;
    }
    KSA(K, sizeof(K)/sizeof(K[0]));
    PRGA(plaintext, ciphertext, sizeof(plaintext)/sizeof(plaintext[0]));

    // Print the encrypted text
    printf("Plaintext: ");
    for (i = 0; i < sizeof(plaintext)/sizeof(plaintext[0]); i++) {
        printf("%c", plaintext[i]);
    }
    printf("\nCiphertext: ");
    for (i = 0; i < sizeof(ciphertext)/sizeof(ciphertext[0]); i++) {
        printf("%02X ", ciphertext[i]);
    }
    printf("\n");

    return 0;
}