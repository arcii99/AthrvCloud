//FormAI DATASET v1.0 Category: modern Encryption ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void encrypt(char message[], int key);
void decrypt(char message[], int key);

int main() {
    char message[MAX_LENGTH];
    int key = 5;
    
    printf("Enter a message to encrypt: ");
    fgets(message, MAX_LENGTH, stdin);
    
    encrypt(message, key);
    printf("Encrypted message: %s", message);
    
    decrypt(message, key);
    printf("Decrypted message: %s", message);
    
    return 0;
}

void encrypt(char message[], int key) {
    int i;
    char ch;
    for(i = 0; message[i] != '\0'; i++) {
        ch = message[i];
        if(ch >= 'a' && ch <= 'z') {
            ch = 'a' + ((ch - 'a' + key) % 26);
        } else if(ch >= 'A' && ch <= 'Z') {
            ch = 'A' + ((ch - 'A' + key) % 26);
        }
        message[i] = ch;
    }
}

void decrypt(char message[], int key) {
    encrypt(message, 26 - key);
}