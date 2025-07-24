//FormAI DATASET v1.0 Category: Modern Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* msg, int key) {
    int len = strlen(msg);
    char* encrypted_msg = malloc(sizeof(char) * len);

    for (int i = 0; i < len; i++) {
        encrypted_msg[i] = msg[i] + key; // add key to each character
    }

    encrypted_msg[len] = '\0'; // add null character at the end

    return encrypted_msg;
}

char* decrypt(char* encrypted_msg, int key) {
    int len = strlen(encrypted_msg);
    char* msg = malloc(sizeof(char) * len);

    for (int i = 0; i < len; i++) {
        msg[i] = encrypted_msg[i] - key; // subtract key from each character
    }

    msg[len] = '\0'; // add null character at the end

    return msg;
}

int main() {
    char* msg = "Hello, world!";
    int key = 3;

    printf("Original message: %s\n", msg);

    char* encrypted_msg = encrypt(msg, key);
    printf("Encrypted message: %s\n", encrypted_msg);

    char* decrypted_msg = decrypt(encrypted_msg, key);
    printf("Decrypted message: %s\n", decrypted_msg);

    free(encrypted_msg);
    free(decrypted_msg);

    return 0;
}