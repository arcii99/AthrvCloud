//FormAI DATASET v1.0 Category: Text processing ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 1000 // Maximum number of characters allowed in input string

int main()
{
    char input[MAX_CHARS];  // Input string
    int length; // Length of input string

    printf("Enter a string: ");
    fgets(input, MAX_CHARS, stdin); // Getting input from user including spaces
    length = strlen(input); // Calculating length of input string

    // Converting all characters to uppercase
    for (int i = 0; i < length; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            input[i] = input[i] - 'a' + 'A';
        }
    }

    // Printing the reversed string
    printf("Reversed string: ");
    for (int i = length - 2; i >= 0; i--)
    {
        printf("%c", input[i]);
    }
    printf("\n");

    // Removing all vowel characters from the string
    printf("String without vowels: ");
    for (int i = 0; i < length; i++)
    {
        if (!(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U'))
        {
            printf("%c", input[i]);
        }
    }
    printf("\n");
    return 0;
}