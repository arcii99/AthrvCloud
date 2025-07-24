//FormAI DATASET v1.0 Category: Encryption ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the input string using Caesar Cipher
void encrypt(char* input_string, int key)
{
    // Loop through each character in the input string
    for (int i = 0; i < strlen(input_string); i++)
    {
        // If current character is a letter
        if (isalpha(input_string[i]))
        {
            // Shift the letter by the key value and keep it within A-Z or a-z range
            input_string[i] = (char) (((toupper(input_string[i]) - 'A' + key) % 26) + 'A');
        }
    }
}

int main()
{
    char input_string[100];
    int key;

    // Get input string from user
    printf("Enter a string to encrypt (in uppercase or lowercase): ");
    fgets(input_string, 100, stdin);

    // Remove the trailing newline character from input
    input_string[strcspn(input_string, "\n")] = '\0';

    // Get the key value from user
    printf("Enter a key value: ");
    scanf("%d", &key);

    // Encrypt the input string using Caesar Cipher
    encrypt(input_string, key);

    // Print the encrypted string
    printf("Encrypted string: %s", input_string);

    return 0;
}