//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: systematic
#include <stdio.h>  // Standard Input/Output Header File Library
#include <string.h> // String Header File Library
#include <ctype.h>  // Character Type Header File Library

int main()
{
    char str[100];          // Array to store input string
    int count[26] = {0};    // Array to store frequency of each alphabet (initialized to 0)

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Get input string (handles spaces and newlines)

    for (int i = 0; i < strlen(str); i++)
    {
        // Convert each character to uppercase to simplify counting
        char c = toupper(str[i]);

        // Check if character is an alphabet
        if (c >= 'A' && c <= 'Z')
        {
            count[c - 'A']++; // Increment frequency counter for corresponding alphabet
        }
    }

    printf("\nFrequency of each alphabet in the string:\n");

    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            printf("%c : %d\n", 'A' + i, count[i]); // Print frequency counter for corresponding alphabet
        }
    }

    return 0;
}