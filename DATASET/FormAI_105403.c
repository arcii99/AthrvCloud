//FormAI DATASET v1.0 Category: modern Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a message using Caesar cipher
char *caesarCipher(char *message, int key)
{
    char *result = (char *)malloc(sizeof(char) * (strlen(message) + 1));

    for (int i = 0; message[i] != '\0'; ++i)
    {
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            result[i] = 'a' + ((message[i] - 'a' + key) % 26);
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            result[i] = 'A' + ((message[i] - 'A' + key) % 26);
        }
        else
        {
            result[i] = message[i];
        }
    }

    result[strlen(message)] = '\0';
    return result;
}

int main()
{
    char message[100], *cipher;
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    // Call the function to encrypt the message using Caesar cipher
    cipher = caesarCipher(message, key);

    printf("Encrypted message: %s", cipher);

    free(cipher);
    return 0;
}