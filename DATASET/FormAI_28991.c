//FormAI DATASET v1.0 Category: Modern Encryption ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char message[100], key[100], cipher[100];

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline characters from inputs
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    if(strlen(message) != strlen(key))
    {
        printf("Error: message and key must be the same length.");
        exit(0);
    }

    int i;
    for(i = 0; i < strlen(message); i++)
    {
        char c = message[i] ^ key[i];
        cipher[i] = c;
    }

    printf("Original message: %s\n", message);
    printf("Key: %s\n", key);
    printf("Encrypted message: %s\n", cipher);

    return 0;
}