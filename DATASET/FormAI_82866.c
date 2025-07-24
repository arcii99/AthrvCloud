//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Substitute with your own key
#define KEY "mysecretkey"

// Customized XOR function for encryption and decryption
void xor(char *data, size_t data_len, char *key, size_t key_len) {
    for (int i = 0; i < data_len; i++) {
        data[i] ^= key[i % key_len];
    }
}

int main() {
    char plaintext[1000] = "Hello World! This is a message to be encrypted.";
    char encrypted[1000];
    char decrypted[1000];
    size_t plaintext_len, key_len, encrypted_len, decrypted_len;

    plaintext_len = strlen(plaintext);
    key_len = strlen(KEY);
    encrypted_len = plaintext_len + 1;
    decrypted_len = encrypted_len;

    // Generate a random nonce for salting
    srand(time(NULL));
    unsigned int nonce = rand();

    // Append nonce to the beginning of plaintext
    char salted_plaintext[1000];
    snprintf(salted_plaintext, sizeof(salted_plaintext), "%u%s", nonce, plaintext);

    // Encrypt plaintext with key
    strcpy(encrypted, salted_plaintext);
    xor(encrypted, encrypted_len, KEY, key_len);

    // Decrypt encrypted data with key
    strcpy(decrypted, encrypted);
    xor(decrypted, decrypted_len, KEY, key_len);

    // Extract nonce and plaintext from decrypted data
    char *nonce_str, *decrypted_plaintext;
    nonce_str = strtok(decrypted, " ");
    decrypted_plaintext = strtok(NULL, "");

    // Check nonce match to prevent replay attacks
    if (atoi(nonce_str) != nonce) {
        printf("ERROR: Nonce does not match.\n");
        return -1;
    }

    // Print out results
    printf("Original Plaintext: %s\n", plaintext);
    printf("Encrypted Data: %s\n", encrypted);
    printf("Decrypted Plaintext: %s\n", decrypted_plaintext);

    return 0;
}