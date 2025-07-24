//FormAI DATASET v1.0 Category: Encryption ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, int key);
void decrypt(char *message, int key);

int main()
{
    char message[100];  // declaring a char array to store the message
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);  // reading the message from the user

    printf("Enter encryption key: ");
    scanf("%d", &key);  // reading the encryption key from the user

    encrypt(message, key);  // calling the encrypt function to encrypt the message

    printf("\nEncrypted message: %s\n", message);  // displaying the encrypted message

    decrypt(message, key);  // calling the decrypt function to decrypt the message

    printf("\nDecrypted message: %s\n", message);  // displaying the decrypted message

    return 0;
}

void encrypt(char *message, int key)
{
    int i;
    char ch;

    for(i = 0; i < strlen(message); i++)
    {
        ch = message[i];

        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;

            if(ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;

            if(ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }
}

void decrypt(char *message, int key)
{
    int i;
    char ch;

    for(i = 0; i < strlen(message); i++)
    {
        ch = message[i];

        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch - key;

            if(ch < 'a')
            {
                ch = ch + 'z' - 'a' + 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch - key;

            if(ch < 'A')
            {
                ch = ch + 'Z' - 'A' + 1;
            }

            message[i] = ch;
        }
    }
}