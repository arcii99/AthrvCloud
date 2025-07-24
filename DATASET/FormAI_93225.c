//FormAI DATASET v1.0 Category: Modern Encryption ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char* message, char* key);
void decrypt(char* message, char* key);

int main(){
    char message[100], key[100];
    printf("Enter the message to be encrypted : ");
    fgets(message, 100, stdin);
    printf("Enter the key to be used for encryption : ");
    fgets(key, 100, stdin);

    printf("\nOriginal Message : %s", message);

    encrypt(message, key);
    printf("\nEncrypted Message : %s", message);

    decrypt(message, key);
    printf("\nDecrypted Message : %s", message);

    return 0;
}

void encrypt(char* message, char* key){
    int message_length = strlen(message) - 1, key_length = strlen(key) - 1;
    int i, j;
    for(i = 0; i < message_length; i++){
        message[i] = message[i] ^ key[i % key_length];
    }
}

void decrypt(char* message, char* key){
    int message_length = strlen(message) - 1, key_length = strlen(key) - 1;
    int i, j;
    for(i = 0; i < message_length; i++){
        message[i] = message[i] ^ key[i % key_length];
    }
}