//FormAI DATASET v1.0 Category: Encryption ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, int key);

int main()
{
    char message[1000];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, 1000, stdin);

    printf("Enter encryption key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message, int key)
{
    int i;

    for(i = 0; message[i] != '\0'; ++i)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
    }
}