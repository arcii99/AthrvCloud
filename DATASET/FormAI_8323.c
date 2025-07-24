//FormAI DATASET v1.0 Category: HTML beautifier ; Style: cheerful
#include <stdio.h>   // Standard Input/Output library
#include <stdlib.h>  // Standard Library
#include <string.h>  // String library for strlen and strcpy

int main()
{
    char code[10000], output[10000]; // Variables to store user input and formatted output
    int i, j, k, len, indent = 0; // Variables to use in loops

    printf("Enter your dirty HTML code: "); // Prompt user to input HTML code
    fgets(code, 10000, stdin); // Store user input in code variable

    len = strlen(code); // Get length of input code

    for(i=0, j=0; i<len; i++) // Loop through input code
    {
        if(code[i] == '<') // Check if current character is opening tag
        {
            indent += 4; // Increase indentation by 4 spaces
            output[j++] = code[i]; // Add opening tag to output variable
            output[j++] = '\n'; // Add new line character after opening tag
            for(k=0; k<indent; k++) // Loop through indentation spaces
                output[j++] = ' '; // Add indentation spaces to output variable
        }
        else if(code[i] == '>') // Check if current character is closing tag
        {
            output[j++] = '\n'; // Add new line character before closing tag
            indent -= 4; // Decrease indentation by 4 spaces
            for(k=0; k<indent; k++) // Loop through indentation spaces
                output[j++] = ' '; // Add indentation spaces to output variable
            output[j++] = code[i]; // Add closing tag to output variable
        }
        else // If current character is neither opening nor closing tag
            output[j++] = code[i]; // Simply add it to output variable
    }

    output[j] = '\0'; // Add null character to end of output variable

    printf("\nYour formatted HTML code is: \n\n%s", output); // Display formatted code to user

    return 0; // Return 0 to indicate successful completion of program
}