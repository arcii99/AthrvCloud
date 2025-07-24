//FormAI DATASET v1.0 Category: Digital signal processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main()
{
    int i;
    char buffer[BUFFER_SIZE];
    printf("Welcome to the paranoid Digital Signal Processor!\n\n");
    printf("Please enter a text message to be processed:\n");
    fgets(buffer, BUFFER_SIZE, stdin); // Get user input
    printf("\nProcessing message...\n");

    // STEP 1: Remove all non-alphanumeric characters
    for(i = 0; buffer[i] != '\0'; ++i)
    {
        if(!(buffer[i] >= 'a' && buffer[i] <= 'z') &&
           !(buffer[i] >= 'A' && buffer[i] <= 'Z') &&
           !(buffer[i] >= '0' && buffer[i] <= '9'))
        {
            buffer[i] = ' ';
        }
    }

    // STEP 2: Reverse the string
    int length = strlen(buffer);
    for(i = 0; i < length / 2; ++i)
    {
        char temp = buffer[i];
        buffer[i] = buffer[length - i - 1];
        buffer[length - i - 1] = temp;
    }

    // STEP 3: Convert all characters to uppercase
    for(i = 0; buffer[i] != '\0'; ++i)
    {
        if(buffer[i] >= 'a' && buffer[i] <= 'z')
        {
            buffer[i] = buffer[i] - 32;
        }
    }

    // STEP 4: Output the processed message
    printf("\nProcessed message: %s\n", buffer);

    // STEP 5: Encrypt the message using a custom encryption algorithm
    for(i = 0; buffer[i] != '\0'; ++i)
    {
        buffer[i] = ((buffer[i] + 3) * 2) % 128;
    }

    // STEP 6: Output the encrypted message
    printf("\nEncrypted message: ");
    for(i = 0; buffer[i] != '\0'; ++i)
    {
        printf("%02X ", buffer[i]);
    }
    printf("\n");

    // STEP 7: Decrypt the message using the same custom encryption algorithm
    for(i = 0; buffer[i] != '\0'; ++i)
    {
        buffer[i] = (((buffer[i] / 2) - 3) + 128) % 128;
    }

    // STEP 8: Reverse the message back to the original order
    for(i = 0; i < length / 2; ++i)
    {
        char temp = buffer[i];
        buffer[i] = buffer[length - i - 1];
        buffer[length - i - 1] = temp;
    }

    // STEP 9: Output the decrypted message
    printf("\nDecrypted message: %s\n", buffer);

    return 0;
}