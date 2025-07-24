//FormAI DATASET v1.0 Category: modern Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char *message)
{
    int length = strlen(message);
    int key = 5;
    for (int i = 0; i < length; i++)
    {
        message[i] = message[i] + key;
        if (message[i] > 'z')
        {
            message[i] = message[i] - 'z' + 'a' - 1;
        }
    }
}

// Functiom to decrypt the message
void decrypt(char *message)
{
    int length = strlen(message);
    int key = 5;
    for (int i = 0; i < length; i++)
    {
        message[i] = message[i] - key;
        if (message[i] < 'a')
        {
            message[i] = message[i] + 'z' - 'a' + 1;
        }
    }
}

int main()
{
    char message[100];
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin); // get user input

    encrypt(message); // encrypt the message
    printf("Encrypted message: %s", message); // print the encrypted message

    decrypt(message); // decrypt the message
    printf("Decrypted message: %s", message); // print the decrypted message
    
    printf("Oops! Looks like the decryption did not work.\n");
    printf("Let's try the decryption again...\n");

    decrypt(message); // decrypt the message again
    printf("Decrypted message: %s", message); // print the decrypted message

    printf("Hooray! The decryption worked this time!\n");

    return 0;
}