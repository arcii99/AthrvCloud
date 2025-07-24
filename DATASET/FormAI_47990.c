//FormAI DATASET v1.0 Category: Modern Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LEN = 100; // Maximum length of input string

// Function to perform encryption of input string
void encrypt(char *str, char *key) {
    int len = strlen(key), i, j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] += key[j] - 'a'; 
        j++;
        if (j == len) j = 0;
    }
}

// Function to perform decryption of input string
void decrypt(char *str, char *key) {
    int len = strlen(key), i, j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] -= key[j] - 'a'; 
        j++;
        if (j == len) j = 0;
    }
}

int main() {
    char str[MAX_LEN], key[MAX_LEN];
    printf("Enter a string to be encrypted: ");
    fgets(str, MAX_LEN, stdin);
    str[strcspn(str, "\n")] = 0; // Remove the newline character from input

    printf("Enter the encryption key: ");
    fgets(key, MAX_LEN, stdin);
    key[strcspn(key, "\n")] = 0; // Remove the newline character from input

    printf("\nBefore Encryption: %s\n", str);
    
    // Perform encryption
    encrypt(str, key);

    printf("After Encryption: %s\n", str);
    
    // Perform decryption
    decrypt(str, key);

    printf("After Decryption: %s\n", str);
    
    return 0;
}