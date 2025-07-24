//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

void sanitizeInput(char* inputString);

int main()
{
    char inputString[MAX_INPUT_LENGTH];
    printf("Enter Input: ");
    fgets(inputString, MAX_INPUT_LENGTH, stdin);
    
    // Pass input to sanitizer function
    sanitizeInput(inputString);
    
    printf("\nSanitized Input: %s\n", inputString);
    return 0;
}

void sanitizeInput(char* inputString)
{
    int inQuotes = 0;
    int i = 0, j = 0;
    char sanitizedString[MAX_INPUT_LENGTH];
    
    // Iterate through inputString
    while (inputString[i] != '\0' && i < MAX_INPUT_LENGTH)
    {
        if (inputString[i] == '"')
        {
            // Toggle inQuotes flag
            inQuotes = !inQuotes;
            sanitizedString[j] = inputString[i];
            i++;
            j++;
            continue; // No need to sanitize inside quotes
        }
        
        if (!inQuotes && !isalnum(inputString[i]))
        {
            // Use space to replace unwanted characters
            sanitizedString[j] = ' ';
        }
        else
        {
            sanitizedString[j] = inputString[i];
        }
        
        i++;
        j++;
    }
    
    // Add null terminator to sanitizedString
    sanitizedString[j] = '\0';
    
    // Copy sanitizedString back to inputString
    strcpy(inputString, sanitizedString);
}