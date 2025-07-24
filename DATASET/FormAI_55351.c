//FormAI DATASET v1.0 Category: Encryption ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char encrypt(char input, int key){
    char result = input + key;
    return result;
}

char decrypt(char input, int key){
    char result = input - key;
    return result;
}

int main(){
    printf("Welcome to my unique encryption program!\n");
    printf("Please enter a message to be encrypted: ");
    char message[100];
    fgets(message, 100, stdin);
    printf("Message entered: %s\n", message);
    printf("Please enter a key to encrypt the message: ");
    int key;
    scanf("%d", &key);
    
    // encryption
    printf("Encrypting message...\n");
    int messageLength = strlen(message);
    char encryptedMessage[100];
    for(int i=0;i<messageLength;i++){
        char result = encrypt(message[i], key);
        encryptedMessage[i] = result;
    }
    printf("Encrypted message: %s\n", encryptedMessage);
    
    // decryption
    printf("Decrypting message...\n");
    char decryptedMessage[100];
    for(int i=0;i<messageLength;i++){
        char result = decrypt(encryptedMessage[i], key);
        decryptedMessage[i] = result;
    }
    printf("Decrypted message: %s\n", decryptedMessage);
    
    return 0;
}