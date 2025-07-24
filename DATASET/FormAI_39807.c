//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: protected
#include <stdio.h>

// function to calculate gcd of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// function to calculate public key
int calculatePublicKey(int phi) {
    int publicKey = 2;
    while (publicKey < phi) {
        if (gcd(publicKey, phi) == 1) {
            return publicKey;
        }
        publicKey++;
    }
    return -1; // error
}

// function to encrypt message
int encrypt(int message, int publicKey, int n) {
    int encryptedMsg = 1;
    int i;
    for (i = 0; i < publicKey; i++) {
        encryptedMsg = (encryptedMsg * message) % n;
    }
    return encryptedMsg;
}

// function to decrypt message
int decrypt(int encryptedMsg, int privateKey, int n) {
    int decryptedMsg = 1;
    int i;
    for (i = 0; i < privateKey; i++) {
        decryptedMsg = (decryptedMsg * encryptedMsg) % n;
    }
    return decryptedMsg;
}

int main() {
    int p = 3; // prime number
    int q = 11; // another prime number
    int n = p * q; // calculate n
    int phi = (p - 1) * (q - 1); // calculate phi
    int publicKey = calculatePublicKey(phi); // calculate public key
    int privateKey = 0;
    int i;
    for (i = 2; i < phi; i++) {
        if ((publicKey * i) % phi == 1) {
            privateKey = i; // calculate private key
            break;
        }
    }
    int message = 7; // message to encrypt
    int encryptedMsg = encrypt(message, publicKey, n); // encrypt message
    int decryptedMsg = decrypt(encryptedMsg, privateKey, n); // decrypt message
    printf("Original Message: %d\n", message);
    printf("Encrypted Message: %d\n", encryptedMsg);
    printf("Decrypted Message: %d\n", decryptedMsg);
    return 0;
}