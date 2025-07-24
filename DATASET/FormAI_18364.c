//FormAI DATASET v1.0 Category: File Encyptor ; Style: introspective
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define ENCRYPTION_KEY 5

void encrypt(char* string, int key) {
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        string[i] += key;
    }
}

void decrypt(char* string, int key) {
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        string[i] -= key;
    }
}

int main() {
    char string[MAX_STRING_LENGTH];
    printf("Please enter a string to encrypt: ");
    fgets(string, MAX_STRING_LENGTH, stdin);

    // Remove the newline character added by fgets()
    string[strcspn(string, "\n")] = 0;

    // Encrypt the string using a key
    encrypt(string, ENCRYPTION_KEY);
    printf("Encrypted string: %s\n", string);

    // Decrypt the string using the same key
    decrypt(string, ENCRYPTION_KEY);
    printf("Decrypted string: %s\n", string);

    return 0;
}