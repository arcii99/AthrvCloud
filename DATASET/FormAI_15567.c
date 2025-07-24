//FormAI DATASET v1.0 Category: Encryption ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 256

int main()
{
    char message[256];
    char encrypted_message[256];
    char decrypted_message[256];
    int key[KEY_SIZE];
    int i, j;

    printf("Enter the message to be encrypted: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; // remove trailing newline character

    // Generate the key
    srand(1337);
    for (i = 0; i < KEY_SIZE; i++)
    {
        key[i] = rand() % 256;
    }

    // Encrypt the message
    for (i = 0; i < strlen(message); i++)
    {
        encrypted_message[i] = message[i] ^ key[i % KEY_SIZE];
    }
    encrypted_message[i] = '\0';

    // Print the encrypted message and key
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Encryption key: ");
    for (i = 0; i < KEY_SIZE; i++)
    {
        printf("%d ", key[i]);
    }
    printf("\n");

    // Decrypt the message using the same key
    for (i = 0; i < strlen(encrypted_message); i++)
    {
        decrypted_message[i] = encrypted_message[i] ^ key[i % KEY_SIZE];
    }
    decrypted_message[i] = '\0';

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}