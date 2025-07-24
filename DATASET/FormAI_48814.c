//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: high level of detail
#include <stdio.h>

// Generate public and private key pair
void generate_key_pair(int p, int q, int *public_key, int *private_key, int *n) {
    *n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 2;
    while (e < phi) {
        if (phi % e == 0) {
            e++;
            continue;
        }
        int flag = 1;
        for (int i = 2; i < e; i++) {
            if (e % i == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            break;
        }
        e++;
    }
    *public_key = e;
    int k = 0;
    while (((k * phi) + 1) % e != 0) {
        k++;
    }
    *private_key = ((k * phi) + 1) / e;
}

// Encrypt plaintext message using public key
int encrypt(int message, int public_key, int n) {
    int ciphertext = 1;
    for (int i = 0; i < public_key; i++) {
        ciphertext = (ciphertext * message) % n;
    }
    return ciphertext;
}

// Decrypt ciphertext message using private key
int decrypt(int ciphertext, int private_key, int n) {
    int message = 1;
    for (int i = 0; i < private_key; i++) {
        message = (message * ciphertext) % n;
    }
    return message;
}

int main() {
    int p = 11;
    int q = 13;
    int public_key, private_key, n;
    generate_key_pair(p, q, &public_key, &private_key, &n);
    printf("Public key: %d\nPrivate key: %d\nN: %d\n", public_key, private_key, n);
    int message = 7;
    int ciphertext = encrypt(message, public_key, n);
    int decrypted_message = decrypt(ciphertext, private_key, n);
    printf("Plaintext message: %d\nEncrypted message: %d\nDecrypted message: %d\n", message, ciphertext, decrypted_message);
    return 0;
}