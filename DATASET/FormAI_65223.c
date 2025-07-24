//FormAI DATASET v1.0 Category: Modern Encryption ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY 4 // shift key value

void encrypt(char* message, int key);

int main()
{
    char message[100];
    int key;

    printf("Enter your message: ");
    fgets(message, 100, stdin);

    printf("Enter encryption key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}

void encrypt(char* message, int key)
{
    char ch;
    int i;

    for(i = 0; message[i] != '\0'; ++i)
    {
        ch = message[i];

        if(isalpha(ch))
        {
            ch = tolower(ch);
            ch = ((ch - 'a') + key) % 26 + 'a';
        }

        message[i] = ch;
    }
}