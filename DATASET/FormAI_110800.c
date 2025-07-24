//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encryption function
void encrypt(char *str, int key)
{
    int i;
    int len = strlen(str);

    // Iterate through each character of the string
    for(i = 0; i < len; i++)
    {
        // Apply the encryption formula
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = ((str[i] - 'a') + key) % 26 + 'a';
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = ((str[i] - 'A') + key) % 26 + 'A';
        }
    }
}

// Decryption function
void decrypt(char *str, int key)
{
    int i;
    int len = strlen(str);

    // Iterate through each character of the string
    for(i = 0; i < len; i++)
    {
        // Apply the decryption formula
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = ((str[i] - 'a') - key + 26) % 26 + 'a';
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = ((str[i] - 'A') - key + 26) % 26 + 'A';
        }
    }
}

int main()
{
    char str[100];
    int key;
    int choice;

    printf("Enter the string to be encrypted/decrypted: ");
    fgets(str, 100, stdin);
    printf("Enter the key: ");
    scanf("%d", &key);

    // Prompt user for encryption/decryption
    printf("Enter 1 to encrypt the string, 2 to decrypt the string: ");
    scanf("%d", &choice);

    // Perform encryption/decryption
    switch(choice)
    {
        case 1:
            encrypt(str, key);
            printf("Encrypted string: %s\n", str);
            break;
        case 2:
            decrypt(str, key);
            printf("Decrypted string: %s\n", str);
            break;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}