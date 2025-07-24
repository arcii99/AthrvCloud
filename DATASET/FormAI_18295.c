//FormAI DATASET v1.0 Category: Modern Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 128
#define XOR_KEY 0xAA

void encrypt(char *message, char *key);
void decrypt(char *message, char *key);
void print_error(char *message);

int main() {
    char message[MAX_LENGTH];
    char key[] = "mySecretKey";

    printf("Enter message to encrypt: ");
    fgets(message, MAX_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0';
    
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}

/*
 * Encrypts the message using XOR encryption with a given key
 */
void encrypt(char *message, char *key) {
    if (strlen(message) > MAX_LENGTH || strlen(key) == 0) {
        print_error("Invalid input");
        exit(1);
    }

    for (int i = 0; i < strlen(message); i++) {
        message[i] = message[i] ^ key[i % strlen(key)] ^ XOR_KEY;
    }
}

/*
 * Decrypts the message using XOR decryption with a given key
 */
void decrypt(char *message, char *key) {
    if (strlen(message) > MAX_LENGTH || strlen(key) == 0) {
        print_error("Invalid input");
        exit(1);
    }

    for (int i = 0; i < strlen(message); i++) {
        message[i] = message[i] ^ key[i % strlen(key)] ^ XOR_KEY;
    }
}

/*
 * Prints an error message and exits the program
 */
void print_error(char *message) {
    printf("Error: %s\n", message);
}