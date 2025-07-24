//FormAI DATASET v1.0 Category: Modern Encryption ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char message[100], key[100], encrypted[100] = "", decrypted[100] = "";
    int i, j, k;

    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin);

    printf("Enter the key to encrypt the message with: ");
    fgets(key, 100, stdin);

    // Trim newline character from message and key
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    // Encryption
    for (i = 0, j = 0; i < strlen(message); i++, j++)
    {
        if (j == strlen(key))
        {
            j = 0;
        }
        k = message[i] ^ key[j];
        sprintf(encrypted, "%s%x", encrypted, k);
    }

    printf("\nEncrypted Message: %s\n", encrypted);

    // Decryption
    for (i = 0, j = 0; i < strlen(encrypted); i += 2, j++)
    {
        sscanf(&encrypted[i], "%2x", &k);
        decrypted[j] = k ^ key[j % strlen(key)];
    }

    printf("\nDecrypted Message: %s\n", decrypted);

    return 0;
}