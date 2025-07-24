//FormAI DATASET v1.0 Category: Modern Encryption ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void encrypt(char message[], char key[]) {
    // Generate random permutation of alphabet
    char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
    srand(time(0));
    for (int i = 0; i < 26; i++) {
        int j = rand() % 26;
        char temp = alphabet[i];
        alphabet[i] = alphabet[j];
        alphabet[j] = temp;
    }

    printf("Permutation of alphabet: %s\n", alphabet);

    // Encrypt message using key and permutation
    int msg_len = strlen(message);
    int key_len = strlen(key);
    char encrypted[msg_len];

    for (int i = 0; i < msg_len; i++) {
        char c = message[i];
        int idx = strchr(alphabet, c) - alphabet;
        char encrypted_char;

        if (i < key_len) {
            char key_char = key[i];
            int key_idx = strchr(alphabet, key_char) - alphabet;
            encrypted_char = alphabet[(idx + key_idx) % 26];
        } else {
            encrypted_char = alphabet[idx];
        }

        encrypted[i] = encrypted_char;
    }

    printf("Encrypted message: %s\n", encrypted);
}

int main() {
    char message[] = "hello world";
    char key[] = "secret";

    encrypt(message, key);

    return 0;
}