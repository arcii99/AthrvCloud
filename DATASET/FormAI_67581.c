//FormAI DATASET v1.0 Category: modern Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

void encrypt(char *input, char *output, char *key) {
    int len = strlen(input);
    int key_len = strlen(key);
    int i, j;
    char *shifted = (char*)calloc(len, sizeof(char));
    
    // Rotate characters in input string based on key length
    for(i = 0; i < len; i++) {
        shifted[i] = input[(i+key_len)%len];
    }
    
    // XOR shifted input and key to generate output
    for(i = 0; i < len; i++) {
        output[i] = shifted[i]^key[i%key_len];
    }
    
    // Free allocated memory
    free(shifted);
}

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    char key[MAX_LENGTH];
    
    printf("Enter message to be encrypted (max %d characters):\n", MAX_LENGTH);
    fgets(input, MAX_LENGTH, stdin);
    
    printf("Enter encryption key (max %d characters):\n", MAX_LENGTH);
    fgets(key, MAX_LENGTH, stdin);
    
    // Remove trailing newline character from input and key
    input[strcspn(input, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';
    
    // Encrypt input using key
    encrypt(input, output, key);
    
    printf("Encrypted message:\n%s\n", output);
    
    return 0;
}