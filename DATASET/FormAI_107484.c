//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: medieval
#include <stdio.h>
#include <string.h>

int main()
{
    char message[1000], key[1000], encrypted_message[1000];
    int i, j, k;
    
    // Get the message to be encrypted
    printf("Enter the message to be encrypted: ");
    fgets(message, 1000, stdin);

    // Get the encryption key
    printf("Enter the encryption key: ");
    fgets(key, 1000, stdin);

    // Remove newline characters from message and key
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    // Compute the length of message and key
    int message_length = strlen(message);
    int key_length = strlen(key);

    // Encrypt message using key
    for (i = 0, j = 0; i < message_length; i++, j++)
    {
        if (j == key_length)
        {
            j = 0;
        }
        k = key[j];
        encrypted_message[i] = (message[i] + k) % 256;
    }

    // Add watermark to the encrypted message
    strcpy(encrypted_message + message_length, "medievalwatermark");

    // Print the encrypted message with watermark
    printf("\nEncrypted message with watermark:\n");
    printf("%s\n", encrypted_message);
    
    return 0;
}