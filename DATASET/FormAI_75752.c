//FormAI DATASET v1.0 Category: Encryption ; Style: innovative
#include <stdio.h>
#include <string.h>

int main()
{
    char message[100];
    int key = 7;

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    for(int i = 0; i < strlen(message); i++)
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

    printf("Encrypted message: %s", message);

    return 0;
}