//FormAI DATASET v1.0 Category: Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char *plaintext, char *key);

int main() {
    char *message = "peace and love";
    char *key = "abc123";
    char *encrypted_message;
    
    encrypted_message = encrypt(message, key);
    
    printf("Original Message: %s\n", message);
    printf("Encrypted Message: %s\n", encrypted_message);
    
    free(encrypted_message);
    return 0;
}

char* encrypt(char *plaintext, char *key) {
    int i, j = 0;
    char *encrypted = malloc(sizeof(char) * (strlen(plaintext) + 1));
    int key_length = strlen(key);
    
    for(i = 0; i < strlen(plaintext); i++) {
        char xored = plaintext[i] ^ key[j];
        encrypted[i] = xored;
        
        j++;
        if(j == key_length) {
            j = 0;
        }
    }
    encrypted[i] = '\0';
    return encrypted;
}