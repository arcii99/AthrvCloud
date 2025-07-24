//FormAI DATASET v1.0 Category: Encryption ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// The key for the Caesar cipher
#define KEY 5

int main()
{
    // Welcome message
    printf("\n|----------------------|\n| Welcome to Mind Bender |\n|----------------------|\n\n");

    // Get the message to be encrypted
    char message[100];
    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin);

    // Display the original message
    printf("\nOriginal message: %s", message);

    // Encrypt the message
    int i = 0;
    char ch;
    while (message[i] != '\0')
    {
        ch = message[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + KEY;
            if (ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }

        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z')
        {
            ch = ch + KEY;
            if (ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }

        i++;
    }

    // Display the encrypted message
    printf("Encrypted message: %s\n", message);

    // Exit message
    printf("\n|-------------------------|\n| Thanks for using Mind Bender |\n|-------------------------|\n");

    return 0;
}