//FormAI DATASET v1.0 Category: Encryption ; Style: bold
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//function to encrypt the string using XOR cipher
void encrypt(char* str, char key)
{
    int len = strlen(str);
    for(int i=0; i<len; i++)
    {
        str[i] = str[i] ^ key;
        key++;
    }
}

//function to decrypt the string using XOR cipher
void decrypt(char* str, char key)
{
    int len = strlen(str);
    for(int i=0; i<len; i++)
    {
        str[i] = str[i] ^ key;
        key++;
    }
}

int main()
{
    char message[100];
    char key;
    printf("Enter the message to encrypt: ");
    scanf("%[^\n]s",message);
    printf("Enter the encryption key: ");
    fflush(stdin);
    scanf("%c",&key);

    //encrypt the message
    encrypt(message, key);
    printf("\nThe encrypted message is: %s", message);

    //decrypt the message
    decrypt(message, key);
    printf("\nThe decrypted message is: %s", message);

    return 0;
}