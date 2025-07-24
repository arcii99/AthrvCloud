//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_MSG_LEN 1000
#define MAX_KEY_LEN 50

// Define the encryption key
char key[MAX_KEY_LEN] = "c0rrUpt3dT3ch";

void encrypt(char *message, int key_len) {
    int i;

    // Generate a random seed for the encryption
    srand(time(NULL));

    // Loop through every character in the message
    for (i = 0; message[i] != '\0'; ++i) {
        // Generate a random number between 0 and key_len
        int random_num = (rand() % key_len);

        // XOR the character with the corresponding character in the encryption key
        message[i] ^= key[random_num];
    }
}

void decrypt(char *message, int key_len) {
    int i;

    // Loop through every character in the message
    for (i = 0; message[i] != '\0'; ++i) {
        // Generate a random number between 0 and key_len
        int random_num = (rand() % key_len);

        // XOR the character with the corresponding character in the decryption key
        message[i] ^= key[random_num];
    }
}

int main() {
    char message[MAX_MSG_LEN];

    printf("Enter your message: ");
    fgets(message, MAX_MSG_LEN, stdin);

    // Remove newline character from the end of the message
    message[strcspn(message, "\n")] = '\0';

    encrypt(message, strlen(key));
    printf("Encrypted message: %s\n", message);

    decrypt(message, strlen(key));
    printf("Decrypted message: %s\n", message);

    return 0;
}