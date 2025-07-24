//FormAI DATASET v1.0 Category: Encryption ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* key, char* message) {
    int len_key = strlen(key);
    int len_message = strlen(message);
    char* encrypted_message = malloc(sizeof(char) * (len_message + 1));

    for (int i = 0; i < len_message; i++) {
        int j = i % len_key;
        encrypted_message[i] = message[i] ^ key[j];
    }

    encrypted_message[len_message] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);

    free(encrypted_message);
}

void decrypt(char* key, char* message) {
    int len_key = strlen(key);
    int len_message = strlen(message);
    char* decrypted_message = malloc(sizeof(char) * (len_message + 1));

    for (int i = 0; i < len_message; i++) {
        int j = i % len_key;
        decrypted_message[i] = message[i] ^ key[j];
    }

    decrypted_message[len_message] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);

    free(decrypted_message);
}

int main() {
    char key[] = "my_secret_key";
    char message[] = "hello world";
    
    printf("Message: %s\n", message);
    encrypt(key, message);
    decrypt(key, "VÑoU\x81\x89Xªf] j\x7F5\x88zOPu");
    
    return 0;
}