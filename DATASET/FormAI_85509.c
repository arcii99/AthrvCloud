//FormAI DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define KEY 3 // The shift key

void encrypt(char *str)
{
    char c, *ptr = str;
    while (*ptr != '\0') // Loop through the input string
    {
        c = *ptr;

        // Check if the character is a lowercase letter
        if (c >= 'a' && c <= 'z')
        {
            c = ((c - 'a' + KEY) % 26) + 'a'; // Shift the character KEY positions to the right
            *ptr = c;
        }

        // Check if the character is an uppercase letter
        else if (c >= 'A' && c <= 'Z')
        {
            c = ((c - 'A' + KEY) % 26) + 'A'; // Shift the character KEY positions to the right
            *ptr = c;
        }

        ptr++; // Move to the next character
    }
}

int main()
{
    char str[100];
    printf("Enter a string to encrypt: ");
    fgets(str, sizeof(str), stdin);
    encrypt(str);
    printf("Encrypted string: %s", str);
    return 0;
}