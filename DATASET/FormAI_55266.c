//FormAI DATASET v1.0 Category: modern Encryption ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void encrypt(char str[], int key);

int main()
{
    char message[100];
    int key;

    printf("Enter the message to encrypt: ");
    scanf("%[^\n]s", message);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}

void encrypt(char str[], int key)
{
    int i;
    srand(time(NULL));

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            continue;
        }
        else
        {
            int random = rand() % 10;
            str[i] = ((str[i] - 'A') + key + random) % 26 + 'A';
        }
    }
}