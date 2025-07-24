//FormAI DATASET v1.0 Category: Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char msg[1000];
    char key[100];
    int msgLength, keyLength, i, j;

    printf("Enter your secret message: ");
    fgets(msg, 1000, stdin);

    printf("Enter your encryption key: ");
    fgets(key, 100, stdin);

    msgLength = strlen(msg) - 1; 
    keyLength = strlen(key) - 1;
    j = 0;

    if(keyLength < msgLength)
    {
        // Repeat the key until it's the same length as the message
        for(i = keyLength; i < msgLength; i++)
        {
            key[i] = key[j];
            j++;

            if(j == keyLength)
            {
                j = 0;
            }
        }
    }

    // Encryption process
    for(i = 0; i < msgLength; i++)
    {
        msg[i] = ((msg[i] + key[i]) % 26) + 'A';
    }

    printf("\nYour encrypted message: %s\n", msg);

    return 0;
}