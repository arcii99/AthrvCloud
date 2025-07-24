//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(int key, char* message)
{
    int i;
    int message_len = strlen(message);
    char* encrypted_message = malloc(message_len * sizeof(char));

    for (i = 0; i < message_len; i++)
    {
        encrypted_message[i] = message[i] + key;
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

int main()
{
    int key;
    char message[100];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    printf("Enter a key to use for encryption: ");
    scanf("%d", &key);

    encrypt(key, message);

    return 0;
}