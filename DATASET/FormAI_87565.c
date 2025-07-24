//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter a key (1-25): ");
    scanf("%d", &key);

    // Ensure key is in range 1-25
    while (key < 1 || key > 25)
    {
        printf("Invalid key. Enter a key between 1 and 25: ");
        scanf("%d", &key);
    }

    // Encrypt the message
    for (int i = 0; i < strlen(message); i++)
    {
        char c = message[i];

        if (isalpha(c))
        {
            // Shift the letter by the key
            if (islower(c))
                c = ((c - 'a') + key) % 26 + 'a';
            else
                c = ((c - 'A') + key) % 26 + 'A';
        }

        message[i] = c;
    }

    printf("Encrypted message: %s", message);

    return 0;
}