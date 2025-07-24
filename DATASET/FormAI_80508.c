//FormAI DATASET v1.0 Category: Encryption ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

int main()
{
    char message[100];
    int key, choice, i;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter a key: ");
    scanf("%d", &key);

    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        for (i = 0; i < strlen(message); i++)
        {
            message[i] = message[i] + key;
        }

        printf("Encrypted message: %s\n", message);
    }
    else if (choice == 2)
    {
        for (i = 0; i < strlen(message); i++)
        {
            message[i] = message[i] - key;
        }

        printf("Decrypted message: %s\n", message);
    }
    else
    {
        printf("Invalid choice.\n");
    }

    return 0;
}