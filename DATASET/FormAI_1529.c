//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to encrypt the string
void encrypt(char* str, int key)
{
    int len = strlen(str);
    for(int i=0; i<len; i++)
    {
        if(isupper(str[i])) // If the character is uppercase
            str[i] = (((str[i] - 65) + key) % 26) + 65;
        else if(islower(str[i])) // If the character is lowercase
            str[i] = (((str[i] - 97) + key) % 26) + 97;
    }
    printf("Encrypted string: %s\n", str);
}

// Function to decrypt the string
void decrypt(char* str, int key)
{
    int len = strlen(str);
    for(int i=0; i<len; i++)
    {
        if(isupper(str[i])) // If the character is uppercase
            str[i] = (((str[i] - 65) - key + 26) % 26) + 65;
        else if(islower(str[i])) // If the character is lowercase
            str[i] = (((str[i] - 97) - key + 26) % 26) + 97;
    }
    printf("Decrypted string: %s\n", str);
}

int main()
{
    char str[100];
    int key;

    printf("Enter the string to be encrypted: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Enter the key: ");
    scanf("%d", &key);

    encrypt(str, key);
    decrypt(str, key);

    return 0;
}