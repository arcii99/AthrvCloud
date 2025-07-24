//FormAI DATASET v1.0 Category: Encryption ; Style: intelligent
#include <stdio.h>
#include <string.h>

#define MAX_STR 100

// Function to encrypt a given string
void encrypt(char *str, int key) {
    int len = strlen(str);
    
    for(int i=0;i<len;i++) {
        str[i] += key; // Adding the key value to each character
    }
}

// Function to decrypt an encrypted string
void decrypt(char *str, int key) {
    int len = strlen(str);
    
    for(int i=0;i<len;i++) {
        str[i] -= key; // Subtracting the key value from each character
    }
}

int main() {
    char input[MAX_STR], output[MAX_STR];
    int key;
    
    printf("Enter the string to be encrypted: ");
    scanf("%s", input);
    
    printf("Enter the key value for encryption: ");
    scanf("%d", &key);
    
    // Performing encryption
    strcpy(output, input);
    encrypt(output, key);

    printf("Encrypted string: %s\n", output);
    
    // Performing decryption
    decrypt(output, key);

    printf("Decrypted string: %s\n", output);
    
    return 0;
}