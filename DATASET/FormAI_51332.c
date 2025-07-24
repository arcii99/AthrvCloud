//FormAI DATASET v1.0 Category: Modern Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the value of key
#define KEY 2

// Function to encrypt the message
void encrypt(char message[], int key)
{
    int len = strlen(message);

    // iterate through each character
    for (int i = 0; i < len; i++)
    {
        // process lower case letters
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        }
        // process upper case letters
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
    }
}

int main()
{
    char message[100];

    printf("Please enter the message to encrypt: ");
    fgets(message, 100, stdin);

    // remove newline from message
    message[strcspn(message, "\n")] = 0;

    // call the encrypt function
    encrypt(message, KEY);

    printf("The encrypted message is: %s", message);

    return 0;
}