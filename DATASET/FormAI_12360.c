//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: relaxed
#include <stdio.h>
#include <string.h>

// Function to check if a given string can be translated
int canTranslate(char* s)
{
    if (*s == '\0') // If the string is empty, it can be translated
        return 1;

    if (*s != 'C') // If the string doesn't start with C, it cannot be translated
        return 0;

    s++; // Move the pointer to the next character
    int count = 1;

    while (*s != '\0')
    {
        if (*s != 'a' && *s != 't') // If the character is not a or t, it cannot be translated
            return 0;

        if (*s == 't')
        {
            count++; // Increment the count for each t encountered
            if (count > 2) // If there are more than 2 t's, it cannot be translated
                return 0;
        }

        s++; // Move the pointer to the next character
    }

    return count == 2; // If there are exactly 2 t's, it can be translated
}

// Function to translate a given string
char* translate(char* s)
{
    char* result = ""; // Initialize an empty string

    if (!canTranslate(s)) // If the string cannot be translated, return an empty string
        return result;

    while (*s != '\0')
    {
        if (*s == 'C') // If the character is C, append a Meow to the result string
            strcat(result, "Meow");
        else if (*s == 'a') // If the character is a, append a prrr to the result string
            strcat(result, "prrr");
        else if (*s == 't') // If the character is t, append a Meow to the result string
            strcat(result, "Meow");

        s++; // Move the pointer to the next character
    }

    return result;
}

// Main function
int main()
{
    char* input = "Cattat";
    char* output = translate(input);

    printf("Input string: %s\n", input);
    printf("Output string: %s\n", output);

    return 0;
}