//FormAI DATASET v1.0 Category: Modern Encryption ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void encrypt(char *message, int key);

int main()
{
    char message[1000]; //array to store message
    int key; //integer key for encryption

    printf("Enter the message you want to encrypt: ");
    fgets(message, 1000, stdin); //scanning the input message
    printf("Enter the key for encryption: ");
    scanf("%d", &key); //scanning the key

    encrypt(message, key); //calling the encrypt function
    printf("Your encrypted message is: %s", message);

    return 0;
}

void encrypt(char *message, int key)
{
    int i;
    char ch;

    for( i=0; message[i] != '\0'; ++i)
    {
        ch = message[i];

        if(ch >= 'a' && ch <= 'z') //if character is lowercase
        {
            ch = ch + key; //adding the key to character
            if(ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1; //if character goes beyond 'z' it will start from 'a'
            }
            message[i] = ch; //encryption of lowercase character
        }
        else if(ch >= 'A' && ch <= 'Z') //if character is uppercase
        {
            ch = ch + key; //adding the key to character
            if(ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1; //if character goes beyond 'Z' it will start from 'A'
            }
            message[i] = ch; //encryption of uppercase character
        }
    }
}