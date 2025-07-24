//FormAI DATASET v1.0 Category: Modern Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* message, int key) {
    int len = strlen(message);
    char* encrypted = (char*) malloc(len + 1);
    strcpy(encrypted, message);
    
    for (int i = 0; i < len; i++) {
        if (encrypted[i] >= 'a' && encrypted[i] <= 'z') {
            encrypted[i] = ((encrypted[i] - 'a') + key) % 26 + 'a';
        } else if (encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            encrypted[i] = ((encrypted[i] - 'A') + key) % 26 + 'A';
        }
    }
    
    return encrypted;
}

int main() {
    char message[] = "Hello World!";
    int key = 7;
    
    printf("Original Message: %s\n", message);
    
    char* encrypted = encrypt(message, key);
    
    printf("Encrypted Message: %s\n", encrypted);
    
    free(encrypted);
    
    return 0;
}