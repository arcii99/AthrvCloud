//FormAI DATASET v1.0 Category: Encryption ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to encrypt message using Caesar cipher
void encrypt(char* message, int key)
{
    int i;

    for(i = 0; message[i] != '\0'; ++i){
        message[i] = (message[i] + key) % 26 + 'A';
    }
   
}

// function to decrypt message using Caesar cipher
void decrypt(char* message, int key)
{
    int i;

    for(i = 0; message[i] != '\0'; ++i){
        message[i] = (message[i] - key + 26) % 26 + 'A';
    }
    
}

int main()
{
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    
    printf("Enter encryption key: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s", message);

    decrypt(message, key);
    printf("Decrypted message: %s", message);

    return 0;
}