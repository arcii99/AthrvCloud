//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void encrypt(char message[], int key);

int main()
{
    char message[MAX_SIZE];
    int key;

    printf("Enter the message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}

void encrypt(char message[], int key)
{
    int len = strlen(message);

    for (int i = 0; i < len; i++)
    {
        if (message[i] == ' ')
        {
            continue;
        }
        else
        {
            message[i] = (message[i] - 'a' + key) % 26 + 'a';
        }
    }
}