//FormAI DATASET v1.0 Category: Modern Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEXT_SIZE 1000
#define KEY_SIZE 16

// Function to generate a random key
void generate_key(char key[]) {
    int i;
    srand(time(NULL));
    
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = 'a' + (rand() % 26);
    }
    key[i] = '\0';
}

// Function to encrypt the given text using the key
void encrypt_text(char text[], char key[]) {
    int i, k = 0;
    
    for (i = 0; text[i] != '\0'; i++) {
        text[i] = (text[i] + key[k]) % 128;
        k = (k + 1) % KEY_SIZE;
    }
}

// Function to decrypt the given text using the key
void decrypt_text(char text[], char key[]) {
    int i, k = 0;
    
    for (i = 0; text[i] != '\0'; i++) {
        text[i] = (text[i] - key[k] + 128) % 128;
        k = (k + 1) % KEY_SIZE;
    }
}

int main() {
    char key[KEY_SIZE + 1], text[MAX_TEXT_SIZE + 1];
    
    printf("Enter the text to be encrypted: ");
    fgets(text, MAX_TEXT_SIZE, stdin);
    text[strcspn(text, "\n")] = '\0'; // Removes the newline character
    
    generate_key(key);
    
    printf("Generated key: %s\n", key);
    
    encrypt_text(text, key);
    
    printf("Encrypted text: %s\n", text);
    
    decrypt_text(text, key);
    
    printf("Decrypted text: %s\n", text);
    
    return 0;
}