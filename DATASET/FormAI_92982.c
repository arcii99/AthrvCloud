//FormAI DATASET v1.0 Category: Encryption ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This function will encrypt the message using a simple XOR encryption algorithm
void encrypt(char *message, char *key){
    int message_length = strlen(message);
    int key_length = strlen(key);

    for(int i = 0; i < message_length; i++){
        message[i] = message[i] ^ key[i % key_length];
    }
}

// This function will decrypt the message using the same XOR encryption algorithm
void decrypt(char *message, char *key){
    encrypt(message, key);  // To decrypt, we just have to encrypt again with the same key
}

int main(){
    char message[100];
    char key[100];

    printf("Enter the message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter the encryption key: ");
    fgets(key, 100, stdin);

    encrypt(message, key);

    printf("Encrypted message: %s", message);

    decrypt(message, key);

    printf("Decrypted message: %s", message);

    return 0;
}