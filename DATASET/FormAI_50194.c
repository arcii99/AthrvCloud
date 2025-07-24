//FormAI DATASET v1.0 Category: Modern Encryption ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char *input, int key)
{
    int i;
    char ch;
    int length = strlen(input);

    for (i = 0; i < length; i++)
    {
        ch = input[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            // Add the key to the character
            ch = ((ch - 'A') + key) % 26 + 'A';
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            // Add the key to the character
            ch = ((ch - 'a') + key) % 26 + 'a';
        }
        input[i] = ch;
    }
}

int main()
{
    char message[100];
    int key;

    printf("Enter the message to be encrypted : ");
    scanf("%s", message);

    printf("Enter the key (1-25): ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("The encrypted message is : %s", message);

    return 0;
}