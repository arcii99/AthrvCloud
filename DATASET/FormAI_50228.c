//FormAI DATASET v1.0 Category: Encryption ; Style: imaginative
#include <stdio.h>
#include <string.h>

#define KEY 10 // Encryption key

void encrypt(char* message)
{
    int length = strlen(message);
    for (int i = 0; i < length; i++)
    {
        if (message[i] == ' ')
            continue;
        message[i] = (message[i] + KEY) % 26 + 'A';
    }
}

int main()
{
    char message[100];
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Original message: %s", message);
    encrypt(message);
    printf("Encrypted message: %s", message);

    return 0;
}