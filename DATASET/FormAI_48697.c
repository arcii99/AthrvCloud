//FormAI DATASET v1.0 Category: Encryption ; Style: random
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char message[100], key[100], encrypted[100];
    int i, j=0, k=0, x, y;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);

    // remove newline character from inputs
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    // convert message to uppercase
    for(i=0; message[i]; i++)
    {
        message[i] = toupper(message[i]);
    }

    // convert key to uppercase
    for(i=0; key[i]; i++)
    {
        key[i] = toupper(key[i]);
    }

    // encrypt the message using Vigenere Cipher
    for(i=0; i<strlen(message); i++)
    {
        x = message[i] - 'A';
        y = key[j] - 'A';

        encrypted[i] = ((x + y) % 26) + 'A';

        j++;
        if(j >= strlen(key))
        {
            j = 0;
        }
    }
    encrypted[i] = '\0';

    // print the encrypted message
    printf("Encrypted message: %s\n", encrypted);

    return 0;
}