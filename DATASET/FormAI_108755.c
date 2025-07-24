//FormAI DATASET v1.0 Category: Encryption ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function to encrypt the given message
void encrypt(char* message, int key)
{
    int len = strlen(message);
    int i;
    for(i=0;i<len;i++)
    {
        message[i] = (message[i] + key) % 128;
    }
}

//function to decrypt the given message
void decrypt(char* message, int key)
{
    int len = strlen(message);
    int i;
    for(i=0;i<len;i++)
    {
        message[i] = (message[i] - key + 128) % 128;
    }
}

//main function to test en/decrypt functions
int main()
{
    char message[100];
    int key;

    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]s", message);
    printf("Enter the encryption key (between 1 and 127): ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}