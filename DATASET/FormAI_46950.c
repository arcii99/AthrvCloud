//FormAI DATASET v1.0 Category: Modern Encryption ; Style: synchronous
#include <stdio.h>
#include <string.h>

void encrypt(char *message, int key)
{
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; i++)
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
    
    for(i = 0; message[i] != '\0'; i++)
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

int main()
{
    char message[100], choice;
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("\nEnter key: ");
    scanf("%d", &key);

    printf("\nSelect an option:\n");
    printf("1. Encrypt the message\n");
    printf("2. Decrypt the message\n");
    scanf(" %c", &choice);

    switch(choice)
    {
        case '1':
            encrypt(message, key);
            printf("\nEncrypted message: %s", message);
            break;
        case '2':
            decrypt(message, key);
            printf("\nDecrypted message: %s", message);
            break;
        default:
            printf("\nInvalid option!");
    }

    return 0;
}