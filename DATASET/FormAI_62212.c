//FormAI DATASET v1.0 Category: Modern Encryption ; Style: shape shifting
#include <stdio.h>
#include <string.h>

// Function to shift the characters of a string
void encrypt(char* input_string, int key)
{
    int string_length = strlen(input_string);

    for (int i = 0; i < string_length; i++) {
        // Shift each character by the key
        input_string[i] = input_string[i] + key;

        // If the character overflows beyond 'z', wrap back to 'a'
        if (input_string[i] > 'z') {
            input_string[i] = input_string[i] - 26;
        }
    }
}

int main()
{
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter key to encrypt with: ");
    scanf("%d", &key);

    // Remove newline character from message as fgets includes it
    message[strcspn(message, "\n")] = 0;

    encrypt(message, key);

    printf("\nEncrypted message: %s", message);

    return 0;
}