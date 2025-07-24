//FormAI DATASET v1.0 Category: Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, int key);

int main()
{
    char message[1000];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, 1000, stdin);

    printf("Enter the encryption key: ");
    scanf("%d", &key);
    getchar(); // consume the newline character left by scanf()

    encrypt(message, key);

    printf("Encrypted message: %s", message);

    return 0;
}

void encrypt(char *message, int key)
{
    int len = strlen(message);
    for (int i = 0; i < len; i++)
    {
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
        // do not modify non-alphabetic characters
    }
}