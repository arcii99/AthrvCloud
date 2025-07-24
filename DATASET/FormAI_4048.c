//FormAI DATASET v1.0 Category: Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* input, int key) {
    for(int i=0; i<strlen(input); ++i) {
        input[i] = input[i] + key;
    }
}

void decrypt(char* input, int key) {
    for(int i=0; i<strlen(input); ++i) {
        input[i] = input[i] - key;
    }
}

int main() {
    char message[100];
    int key;
    
    printf("Enter the message to be encrypted: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}