//FormAI DATASET v1.0 Category: Modern Encryption ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to perform the encryption
void encrypt(char *input_text, char *key) {
    int input_length = strlen(input_text);
    int key_length = strlen(key);
    
    // repeating the key until it is at least the same length as the message
    char repeated_key[input_length];
    int i, j = 0;
    for (i = 0; i < input_length; i++) {
        if (j == key_length) {
            j = 0;
        }
        repeated_key[i] = key[j];
        j++;
    }
    
    // performing the encryption
    for (i = 0; i < input_length; i++) {
        int char_value = (int)input_text[i] + (int)repeated_key[i];
        if (char_value > 126) {
            char_value = char_value - 95;
        }
        input_text[i] = (char)char_value;
    }
}

// function to perform the decryption
void decrypt(char *input_text, char *key) {
    int input_length = strlen(input_text);
    int key_length = strlen(key);
    
    // repeating the key until it is at least the same length as the message
    char repeated_key[input_length];
    int i, j = 0;
    for (i = 0; i < input_length; i++) {
        if (j == key_length) {
            j = 0;
        }
        repeated_key[i] = key[j];
        j++;
    }
    
    // performing the decryption
    for (i = 0; i < input_length; i++) {
        int char_value = (int)input_text[i] - (int)repeated_key[i];
        if (char_value < 32) {
            char_value = char_value + 95;
        }
        input_text[i] = (char)char_value;
    }
}

int main() {
    char input_text[100];
    char key[100];
    
    // getting the input text and key from the user
    printf("Enter the text to encrypt/decrypt which should not exceed 100 characters: ");
    fgets(input_text, 100, stdin);
    input_text[strcspn(input_text, "\n")] = 0; // removing the newline character from input_text
    printf("Enter the key for encryption/decryption which should not exceed 100 characters: ");
    fgets(key, 100, stdin);
    key[strcspn(key, "\n")] = 0; // removing the newline character from key
    
    // encrypting the input text and printing the result
    encrypt(input_text, key);
    printf("Encrypted text: %s\n", input_text);
    
    // decrypting the encrypted text and printing the result
    decrypt(input_text, key);
    printf("Decrypted text: %s\n", input_text);
    
    return 0;
}