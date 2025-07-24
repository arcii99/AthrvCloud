//FormAI DATASET v1.0 Category: modern Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16

void encrypt(char *plaintext, char *key) {
    int i;
    int len = strlen(plaintext);
    char *ciphertext = (char*)malloc(len + 1);
    memset(ciphertext, 0, len + 1);
    
    for(i = 0; i < len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % KEY_SIZE];
        printf("%02X", (unsigned char)ciphertext[i]);
    }
    printf("\n");
    free(ciphertext);
}

int main() {
    char plaintext[256];
    char key[KEY_SIZE + 1];
    printf("Enter plaintext: ");
    fgets(plaintext, 256, stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;
    printf("Enter key (16 hex characters): ");
    fgets(key, KEY_SIZE + 1, stdin);
    key[strcspn(key, "\n")] = 0;
    
    encrypt(plaintext, key);

    return 0;
}