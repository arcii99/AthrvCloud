//FormAI DATASET v1.0 Category: Encryption ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string using a cyberpunk style algorithm
void encrypt(char *str)
{
    int i, key = 7, length = strlen(str);
    char c;

    // Iterate through each character in the string and perform the encryption
    for (i = 0; i < length; i++) {
        c = str[i];
        if (c >= 'a' && c <= 'z') {
            c = (((c - 'a') + key) % 26) + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = (((c - 'A') + key) % 26) + 'A';
        } else if (c >= '0' && c <= '9') {
            c = (((c - '0') + key) % 10) + '0';
        }
        str[i] = c;
    }
}

int main()
{
    char message[100];

    // Get input from the user
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);

    // Remove the newline character that fgets adds to the end of the input
    message[strcspn(message, "\n")] = 0;

    // Encrypt the message using our cyberpunk style algorithm
    encrypt(message);

    // Output the encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}