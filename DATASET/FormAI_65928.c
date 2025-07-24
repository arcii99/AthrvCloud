//FormAI DATASET v1.0 Category: Encryption ; Style: random
#include <stdio.h>
#include <string.h>

#define KEY 0x23 

void encrypt(char *str)
{
    int length = strlen(str);
    for (int i = 0; i < length; i++) 
    {
        str[i] ^= KEY;
    }
}

void decrypt(char *str)
{
    int length = strlen(str);
    for (int i = 0; i < length; i++) 
    {
        str[i] ^= KEY;
    }
}

int main() 
{
    char message[1000];
    char encryptedMessage[1000];
    char decryptedMessage[1000];

    printf("Enter a message to encrypt: ");
    fgets(message, 1000, stdin);

    printf("\nOriginal message: %s\n", message);

    //encrypting the message
    encrypt(message);
    strcpy(encryptedMessage, message);
    printf("Encrypted message: %s\n", encryptedMessage);

    //decrypting the message
    decrypt(encryptedMessage);
    strcpy(decryptedMessage, encryptedMessage);
    printf("Decrypted message: %s\n", decryptedMessage);

    return 0;
}