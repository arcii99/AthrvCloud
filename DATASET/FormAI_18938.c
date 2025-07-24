//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char message[100];
    int key, i;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter a key value (1-25): ");
    scanf("%d", &key);

    for(i = 0; message[i] != '\0'; i++)
    {
        char c = message[i];

        if(c >= 'a' && c <= 'z')
        {
            c = c + key;

            if(c > 'z')
            {
                c = c - 'z' + 'a' - 1;
            }

            message[i] = c;
        }
        else if(c >= 'A' && c <= 'Z')
        {
            c = c + key;

            if(c > 'Z')
            {
                c = c - 'Z' + 'A' - 1;
            }

            message[i] = c;
        }
    }

    printf("Encrypted message: %s\n", message);

    return 0;
}