//FormAI DATASET v1.0 Category: Encryption ; Style: satisfied
#include <stdio.h>
#include <string.h>

// Function to perform encryption
void encrypt(char* message, int key)
{
    int len = strlen(message);
    for (int i = 0; i < len; i++)
    {
        // If character is uppercase
        if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = (message[i] + key - 'A') % 26 + 'A';
        }
        // If character is lowercase
        else if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = (message[i] + key - 'a') % 26 + 'a';
        }
    }
}

int main()
{
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter key for encryption: ");
    scanf("%d", &key);

    // Encrypt message
    encrypt(message, key);

    printf("\nEncrypted message: %s\n", message);
    return 0;
}