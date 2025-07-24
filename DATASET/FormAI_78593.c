//FormAI DATASET v1.0 Category: modern Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("\n\n============= Modern Encryption =============\n\n");

    // ask user to input a message to encrypt
    char message[1000];
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    // declare a key for encryption and decryption
    int key = 5;

    // create variables to store the encrypted and decrypted message
    char encrypted[1000];
    char decrypted[1000];

    // loop through each character in the message
    for (int i = 0; i < strlen(message); i++)
    {
        // encrypt lowercase letters
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            encrypted[i] = (message[i] + key - 'a') % 26 + 'a';
        }
        // encrypt uppercase letters
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            encrypted[i] = (message[i] + key - 'A') % 26 + 'A';
        }
        // leave spaces and other characters as is
        else
        {
            encrypted[i] = message[i];
        }
    }

    // add null terminator to encrypted message
    encrypted[strlen(message)] = '\0';

    // loop through each character in the encrypted message
    for (int i = 0; i < strlen(encrypted); i++)
    {
        // decrypt lowercase letters
        if (encrypted[i] >= 'a' && encrypted[i] <= 'z')
        {
            decrypted[i] = (encrypted[i] - key - 'a' + 26) % 26 + 'a';
        }
        // decrypt uppercase letters
        else if (encrypted[i] >= 'A' && encrypted[i] <= 'Z')
        {
            decrypted[i] = (encrypted[i] - key - 'A' + 26) % 26 + 'A';
        }
        // leave spaces and other characters as is
        else
        {
            decrypted[i] = encrypted[i];
        }
    }

    // add null terminator to decrypted message
    decrypted[strlen(encrypted)] = '\0';

    // print the encrypted and decrypted messages
    printf("\n\nEncrypted message: %s\n\n", encrypted);
    printf("Decrypted message: %s\n\n", decrypted);

    return 0;
}