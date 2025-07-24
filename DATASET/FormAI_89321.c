//FormAI DATASET v1.0 Category: Modern Encryption ; Style: funny
#include <stdio.h>
#include <string.h>

int main()
{
    char message[100];
    printf("Enter a secret message: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = 0;
    printf("\nEncrypting your secret message... Please wait.\n");

    int key = 5; // secret key for encryption
    for(int i=0; i<strlen(message); i++)
    {
        char ch = message[i];
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

    printf("\nCongratulations! Your secret message has been encrypted successfully!\n");
    printf("Here is the Encrypted message: %s\n", message);

    printf("\nTrying to decrypt your secret message... Please wait.\n");

    for(int i=0; i<strlen(message); i++)
    {
        char ch = message[i];
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

    printf("\nCongratulations! Your secret message has been decrypted successfully!\n");
    printf("Here is the Decrypted message: %s\n", message);

    printf("\nHa! You thought I was going to give you a serious encryption program, didn't you?\n");
    printf("Well, who said encrypting and decrypting messages can't be fun?\n");

    return 0;
}