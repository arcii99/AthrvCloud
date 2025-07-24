//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("The Case of the Digital Watermarking\n");
    printf("By Sherlock Holmes\n");

    char message[100];
    char key[100];

    printf("\nEnter the message to be watermarked: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the watermark key: ");
    fgets(key, sizeof(key), stdin);

    // Removing the newline character from the input strings
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    printf("\nThe message entered is: %s\n", message);
    printf("The watermark key entered is: %s\n", key);

    // Encrypting the message with the watermark key
    int watermark_size = strlen(key);
    for (int i = 0; i < strlen(message); i++)
    {
        message[i] += key[i % watermark_size];
    }

    printf("\nThe watermarked message is: %s\n", message);

    // Decrypting the watermarked message
    for (int i = 0; i < strlen(message); i++)
    {
        message[i] -= key[i % watermark_size];
    }

    printf("\nThe decrypted message is: %s\n", message);

    printf("\nCase Solved!");

    return 0;
}