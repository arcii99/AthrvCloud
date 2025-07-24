//FormAI DATASET v1.0 Category: Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char message[100], key[100], encrypted_message[100];
    int i, j = 0;

    // Get message and key from user
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter encryption key: ");
    fgets(key, 100, stdin);

    // Remove new line character from message and key
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    // Encrypt the message
    for(i = 0; i < strlen(message); i++)
    {
        if(j == strlen(key))
        {
            j = 0;
        }
        encrypted_message[i] = (((message[i] + key[j]) % 26) + 'a');
        j++;
    }
    encrypted_message[i] = '\0';

    printf("Encrypted Message: %s\n", encrypted_message);

    return 0;
}