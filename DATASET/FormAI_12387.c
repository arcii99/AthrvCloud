//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROTATION 13 // Define ROTATION operation for Caesar Cipher

void caesarCipher(char *message, int key) {
    int i=0;
    char c;
    while (message[i]) {       // Iterate message character by character
        c=message[i];          // Get character
        if (c >= 'a' && c <= 'z') {
            c= (c-'a'+key)%26+'a'; // Lowercase letter
        } else if (c >= 'A' && c <= 'Z') {
            c= (c-'A'+key)%26+'A'; // Uppercase letter
        }
        message[i]=c; // Replace character with rotated character
        i++;         
    }
}

int main() {
    char message[100], encryptedMessage[100], decryptedMessage[100];
    int key;
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);  // Get message from user
    printf("Enter key: ");
    scanf("%d", &key);          // Get key from user
    // Encrypt the message
    memcpy(encryptedMessage, message, strlen(message));
    caesarCipher(encryptedMessage, key);
    printf("Encrypted message: %s\n", encryptedMessage); 
    // Decrypt the message
    memcpy(decryptedMessage, encryptedMessage, strlen(encryptedMessage));
    caesarCipher(decryptedMessage, 26-key);
    printf("Decrypted message: %s\n", decryptedMessage);
    return 0;
}