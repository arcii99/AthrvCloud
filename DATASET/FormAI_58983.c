//FormAI DATASET v1.0 Category: Modern Encryption ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function declaration */
void encrypt(char *message, int key);
void decrypt(char *message, int key);

/* Encrypt function */
void encrypt(char *message, int key){
    while(*message){
        *message = (*message) + key; /* Incrementing the ASCII value of each character in the message by the key */
        message++;
    }
}

/* Decrypt function */
void decrypt(char *message, int key){
    while(*message){
        *message = (*message) - key; /* Decrementing the ASCII value of each character in the message by the key */
        message++;
    }
}

/* Main function */
int main(){
    char message[1000];
    int key;
    printf("Enter message to encrypt: ");
    gets(message);
    printf("Enter key: ");
    scanf("%d", &key);
    
    // Encryption
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decryption
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}