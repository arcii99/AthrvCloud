//FormAI DATASET v1.0 Category: Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *str, int key);

int main()
{
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter encryption key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}

void encrypt(char *str, int key)
{
    int i;

    for(i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
        {
            str[i] = (str[i] + key) % 26 + 'a';
        }
    }
}