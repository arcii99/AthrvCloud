//FormAI DATASET v1.0 Category: Modern Encryption ; Style: multivariable
#include <stdio.h>
#include <string.h>

#define KEY1 7
#define KEY2 13

// Encrypts each character in the string using two keys
void encrypt(char *str, int key1, int key2) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        int letter = str[i];
        letter = (letter * key1) + key2;
        str[i] = letter;
    }
}

// Decrypts each character in the string using two keys
void decrypt(char *str, int key1, int key2) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        int letter = str[i];
        letter = (letter - key2) / key1;
        str[i] = letter;
    }
}

int main() {
    char message[100];
    printf("Enter your message: ");
    fgets(message, 100, stdin);

    // Encrypt the message using two keys
    encrypt(message, KEY1, KEY2);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message using the same two keys
    decrypt(message, KEY1, KEY2);
    printf("Decrypted message: %s\n", message);

    return 0;
}