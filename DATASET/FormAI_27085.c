//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CRYPTO_BUFFER_SIZE 1024

void encrypt(char* key, char* message, char* encrypted_message) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int key_index = 0;
    for (int i = 0; i < message_length; i++) {
        int encrypted_char = message[i] ^ key[key_index];
        encrypted_message[i] = (char)encrypted_char;
        key_index = (key_index + 1) % key_length;
    }
    encrypted_message[message_length] = '\0';
}

void decrypt(char* key, char* encrypted_message, char* decrypted_message) {
    int message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    int key_index = 0;
    for (int i = 0; i < message_length; i++) {
        int decrypted_char = encrypted_message[i] ^ key[key_index];
        decrypted_message[i] = (char)decrypted_char;
        key_index = (key_index + 1) % key_length;
    }
    decrypted_message[message_length] = '\0';
}

int main() {
    char* key = "mysecretkey";
    char* message = "Hello World! This is a secret message.";
    char* encrypted_message = malloc(CRYPTO_BUFFER_SIZE);
    encrypt(key, message, encrypted_message);
    printf("Encrypted Message: %s\n", encrypted_message);

    char* decrypted_message = malloc(CRYPTO_BUFFER_SIZE);
    decrypt(key, encrypted_message, decrypted_message);
    printf("Decrypted Message: %s\n", decrypted_message);

    free(encrypted_message);
    free(decrypted_message);
    return 0;
}