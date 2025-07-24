//FormAI DATASET v1.0 Category: Encryption ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 32
#define MAX_BUFFER_SIZE 1024

void generate_key(char* key) {
    int i;
    for(i = 0; i < KEY_SIZE - 1; i++)
        key[i] = rand() % 256;
    key[i] = '\0';
}

void encrypt(char* key, char* message, char* encrypted_message) {
    int i, j;
    for(i = 0; i < strlen(message); i++) {
        j = i % KEY_SIZE;
        encrypted_message[i] = message[i] ^ key[j];
    }
    encrypted_message[i] = '\0';
}

void decrypt(char* key, char* encrypted_message, char* decrypted_message) {
    int i, j;
    for(i = 0; i < strlen(encrypted_message); i++) {
        j = i % KEY_SIZE;
        decrypted_message[i] = encrypted_message[i] ^ key[j];
    }
    decrypted_message[i] = '\0';
}

int main() {
    char key[KEY_SIZE];
    char message[MAX_BUFFER_SIZE];
    char encrypted_message[MAX_BUFFER_SIZE];
    char decrypted_message[MAX_BUFFER_SIZE];

    srand(time(NULL));

    // Get input message from user
    printf("Enter your message: ");
    fgets(message, MAX_BUFFER_SIZE, stdin);

    // Generate encryption key
    generate_key(key);
    printf("Your encryption key is: %s\n", key);

    // Encrypt message and print
    encrypt(key, message, encrypted_message);
    printf("Your encrypted message is: %s\n", encrypted_message);

    // Decrypt message and print
    decrypt(key, encrypted_message, decrypted_message);
    printf("Your decrypted message is: %s\n", decrypted_message);

    return 0;
}