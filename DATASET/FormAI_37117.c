//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Function to encrypt the message using XOR
void encryptMessage(char *message, char *key) {
    int len = strlen(key);
    int i;
    for(i=0; message[i] != '\0'; i++) {
        message[i] ^= key[i % len];
    }
}

//Function to decrypt the message using XOR
void decryptMessage(char *message, char *key) {
    encryptMessage(message, key);
}

int main() {
    char message[100];
    char key[100];
    
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter key to encrypt message: ");
    fgets(key, 100, stdin);

    encryptMessage(message, key);  //Message encryption

    printf("Encrypted message: %s", message);  

    decryptMessage(message, key);  //Message decryption

    printf("Decrypted message: %s", message);

    return 0;
}