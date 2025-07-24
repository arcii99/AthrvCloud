//FormAI DATASET v1.0 Category: Modern Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* plaintext, int key){
    int i;
    for(i = 0; i < strlen(plaintext); i++){
        plaintext[i] += key;
    }
}

void decrypt(char* ciphertext, int key){
    int i;
    for(i = 0; i < strlen(ciphertext); i++){
        ciphertext[i] -= key;
    }
}

int main(){
    char message[100];
    int key;
    
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter key: ");
    scanf("%d", &key);
    
    // remove newline character from message string
    int len = strlen(message);
    if (message[len-1] == '\n'){
        message[len-1] = '\0';
    }
    
    // encrypt the message
    encrypt(message, key);
    
    printf("Encrypted message: %s\n", message);
    
    // decrypt the message
    decrypt(message, key);
    
    printf("Decrypted message: %s\n", message);
    
    return 0;
}