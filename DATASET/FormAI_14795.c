//FormAI DATASET v1.0 Category: Text processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1000], output[1000];
    int i, j;
    
    // Get user input
    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);
    
    // Remove extra white spaces
    for(i = 0, j = 0; i < strlen(input); i++)
    {
        // Check if current and next characters are spaces
        if(input[i] == ' ' && input[i+1] == ' ')
        {
            continue; // Skip extra space
        }
        output[j++] = input[i]; // Assign non-extra-space characters to output array
    }
    output[j] = '\0'; // Add null character at end of output array
    
    // Capitalize each word
    for(i = 0; i < strlen(output); i++)
    {
        // If first character in sentence or if previous character was a space, capitalize current character
        if(i == 0 || output[i-1] == ' ')
        {
            output[i] = toupper(output[i]); // Convert to uppercase
        }
        else
        {
            output[i] = tolower(output[i]); // Convert to lowercase
        }
    }
    
    // Print processed sentence
    printf("Processed sentence: %s", output);
    
    return 0;
}