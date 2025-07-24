//FormAI DATASET v1.0 Category: Modern Encryption ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int main()
{
    char input[MAX];
    char key[MAX];
    char output[MAX];
    int i, j, k = 0;

    //Getting input from the user
    printf("Enter the message to be encrypted: ");
    fgets(input, MAX, stdin);
    input[strcspn(input, "\n")] = 0;

    //Getting key from the user
    printf("Enter the key for encryption: ");
    fgets(key, MAX, stdin);
    key[strcspn(key, "\n")] = 0;

    //Converting input and key to uppercase
    for(i = 0; i < strlen(input); i++)
    {
        input[i] = toupper(input[i]);
    }
    for(i = 0; i < strlen(key); i++)
    {
        key[i] = toupper(key[i]);
    }

    //Encrypting the message using Vigenere Cipher
    for(i = 0; i < strlen(input); i++)
    {
        if(input[i] >= 'A' && input[i] <= 'Z')
        {
            output[i] = (((input[i] - 'A') + (key[k] - 'A')) % 26) + 'A';
            k++;
            if(k >= strlen(key))
            {
                k = 0;
            }
        }
        else
        {
            output[i] = input[i];
        }
    }

    printf("Encrypted message: %s\n", output);

    //Decrypting the message
    char decrypted[MAX];
    k = 0;
    for(i = 0; i < strlen(output); i++)
    {
        if(output[i] >= 'A' && output[i] <= 'Z')
        {
            decrypted[i] = (((output[i] - 'A') - (key[k] - 'A') + 26) % 26) + 'A';
            k++;
            if(k >= strlen(key))
            {
                k = 0;
            }
        }
        else
        {
            decrypted[i] = output[i];
        }
    }

    printf("Decrypted message: %s\n", decrypted);
    return 0;
}