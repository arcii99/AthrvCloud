//FormAI DATASET v1.0 Category: Encryption ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encryption function
char* encrypt(char* str, int key) {
    char* encrypted = (char*) malloc(strlen(str) * sizeof(char));
    for(int i=0; i<strlen(str); i++) {
        char c = str[i];
        if(c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' + key) % 26;
        } else if(c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' + key) % 26;
        }
        encrypted[i] = c;
    }
    return encrypted;
}

// Decryption function
char* decrypt(char* str, int key) {
    char* decrypted = (char*) malloc(strlen(str) * sizeof(char));
    for(int i=0; i<strlen(str); i++) {
        char c = str[i];
        if(c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' - key + 26) % 26;
        } else if(c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' - key + 26) % 26;
        }
        decrypted[i] = c;
    }
    return decrypted;
}

int main() {
    char plaintext[100];
    int key;
    printf("Enter plaintext: ");
    gets(plaintext);
    printf("Enter encryption key: ");
    scanf("%d", &key);

    char* encrypted = encrypt(plaintext, key);
    printf("Encrypted text: %s\n", encrypted);

    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted text: %s\n", decrypted);
    return 0;
}