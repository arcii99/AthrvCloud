//FormAI DATASET v1.0 Category: Encryption ; Style: high level of detail
#include<stdio.h>
#include<string.h>

void encrypt(char* str, int key) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        // Encrypt only uppercase and lowercase letters
        if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')) {
            // Convert uppercase letters to lowercase letters
            if(str[i]>='A' && str[i]<='Z') {
                str[i] = str[i] + 32;
            }
            // Encrypting formula: c = (p + k) % 26, where c is the ciphertext, p is plaintext and k is the key
            str[i] = (str[i] + key - 'a') % 26 + 'a';
        }
    }
}

void decrypt(char* str, int key) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        // Decrypt only uppercase and lowercase letters
        if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')) {
            // Convert uppercase letters to lowercase letters
            if(str[i]>='A' && str[i]<='Z') {
                str[i] = str[i] + 32;
            }
            // Decryption formula: p = (c - k) % 26, where c is the ciphertext, p is plaintext and k is the key
            str[i] = (str[i] - key - 'a' + 26) % 26 + 'a';
        }
    }
}

int main() {
    char message[1000];
    int key;
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter key value for encryption: ");
    scanf("%d", &key);
    // Encrypting message using the key
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    // Decrypting message using the same key
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}