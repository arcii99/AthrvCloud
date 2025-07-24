//FormAI DATASET v1.0 Category: Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Encryption function
void encrypt(char* message, int key) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        message[i] += key;
    }
}

//Decryption function
void decrypt(char* message, int key) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        message[i] -= key;
    }
}

int main() {
    int key;
    char message[100];

    //Ask for user input
    printf("Enter message to be encrypted: ");
    fgets(message, 100, stdin);
    printf("Enter encryption key: ");
    scanf("%d", &key);

    //Encrypt the message
    encrypt(message, key);
    printf("Encrypted message: %s", message);

    //Decrypt the message
    decrypt(message, key);
    printf("Decrypted message: %s", message);

    return 0;
}