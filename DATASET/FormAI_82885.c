//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char secret_message[] = "the quick brown fox jumps over the lazy dog";
    int secret_key = 42;
    int key_length = sizeof(secret_key);

    // Cryptic algorithm
    for (int i = 0; i < strlen(secret_message); i++) {
        secret_message[i] = secret_message[i] ^ secret_key;
    }

    printf("Secret Message: %s\n", secret_message);

    // Decrypting the secret message
    for (int i = 0; i < strlen(secret_message); i++) {
        secret_message[i] = secret_message[i] ^ secret_key;
    }

    printf("Decrypted message: %s\n", secret_message);

    return 0;
}