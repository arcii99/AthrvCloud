//FormAI DATASET v1.0 Category: Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program will encrypt a message using the Caesar Cipher method

int main()
{
    char message[100];
    int key, i;

    printf("Enter a message: ");
    gets(message); // takes input of the message to be encrypted

    printf("Enter a key: ");
    scanf("%d", &key); // takes input of the key to be used for encryption

    for(i = 0; i < strlen(message); i++)
    {
        // encrypt each character of the message
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = (message[i] - 'a' + key) % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = (message[i] - 'A' + key) % 26 + 'A';
        }
    }

    printf("Encrypted message: %s", message);

    return 0;
}