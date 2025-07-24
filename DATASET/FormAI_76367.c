//FormAI DATASET v1.0 Category: Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

char* encrypt(char* message, int key) {
    int len = strlen(message);
    char* cipher = (char*) malloc(sizeof(char) * len);
    for(int i = 0; i < len; i++) {
        cipher[i] = message[i] + key;
    }
    cipher[len] = '\0';
    return cipher;
}

char* decrypt(char* cipher, int key) {
    int len = strlen(cipher);
    char* message = (char*) malloc(sizeof(char) * len);
    for(int i = 0; i < len; i++) {
        message[i] = cipher[i] - key;
    }
    message[len] = '\0';
    return message;
}

int main() {
    char* message = "Hello, World!";
    int key = 5;
    char* cipher = encrypt(message, key);
    printf("Encrypted message: %s\n", cipher);
    char* decrypted_message = decrypt(cipher, key);
    printf("Decrypted message: %s\n", decrypted_message);
    return 0;
}