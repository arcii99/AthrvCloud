//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: minimalist
#include <stdio.h>  // Standard input/output library
#include <string.h> // String library

int main()
{
    char ccl_input[50]; // C Cat Language input, limited to 50 characters
    char ccl_output[50]; // C Cat Language output, limited to 50 characters

    printf("Enter C Cat Language phrase: ");
    fgets(ccl_input, sizeof(ccl_input), stdin); // Read input from user

    // Iterate through every character in the input string
    for(int i = 0; i < strlen(ccl_input); i++)
    {
        switch(ccl_input[i])
        {
            case 'c':
                strcat(ccl_output, "meow"); // Concatenate "meow" to output string
                break;
            case 'C':
                strcat(ccl_output, "MEOW"); // Concatenate "MEOW" to output string
                break;
            case ' ':
                strcat(ccl_output, " "); // Concatenate space character to output string
                break;
            default:
                // Ignore any other characters, as they are not part of C Cat Language
                break;
        }
    }

    printf("Translated phrase: %s\n", ccl_output); // Print translated phrase

    return 0; // End program
}