//FormAI DATASET v1.0 Category: Modern Encryption ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to perform the XOR encryption
void encrypt(char text[], char key[]) {
    int key_len = strlen(key);
    int text_len = strlen(text);
    int i;

    // Loop to perform the XOR operation on each character of the text with key
    for (i = 0; i < text_len ;i++) {
        text[i] = text[i] ^ key[i % key_len];
    }
}

// Function to perform the XOR decryption
void decrypt(char text[], char key[]) {
    // Decryption is just the reverse of encryption
    encrypt(text, key);
}

int main() {
    char text[100], key[100];
    printf("Enter the text to be encrypted: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter the key for encryption: ");
    fgets(key, sizeof(key), stdin);

    // Removing the newline character from the input strings
    text[strcspn(text, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    encrypt(text, key);
    printf("Encrypted text: %s\n", text);
    decrypt(text, key);
    printf("Decrypted text: %s\n", text);

    return 0;
}