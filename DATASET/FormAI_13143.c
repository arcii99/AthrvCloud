//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <string.h>

// Function to check if character is not an alphabet or a digit
int isSpecialChar(char c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return 0;
    else
        return 1;
}

// Function to remove all special characters from string
void removeSpecialChars(char *inputString, char *outputString)
{
    int i = 0, j = 0;
    
    // loop over each character in input string
    while(inputString[i] != '\0')
    {
        if(!isSpecialChar(inputString[i]))
        {
            outputString[j] = inputString[i];
            j++;
        }
        i++;
    }
    outputString[j] = '\0';
}

// Function to convert string to uppercase
void toUpperCase(char *string)
{
    int i = 0;
    while(string[i] != '\0')
    {
        if(string[i] >= 'a' && string[i] <= 'z')
            string[i] = string[i] - 32;
        i++;
    }
}

// Function to trim whitespace from string
void trim(char *inputString, char *outputString)
{
    int i = 0, j = 0;

    // Remove leading whitespace
    while(inputString[i] == ' ' || inputString[i] == '\n' || inputString[i] == '\r')
        i++;
    
    // Copy trimmed string
    while(inputString[i] != '\0')
    {
        outputString[j] = inputString[i];
        i++;
        j++;
    }
    
    // Remove trailing whitespace
    while(j > 0 && (outputString[j-1] == ' ' || outputString[j-1] == '\n' || outputString[j-1] == '\r'))
        j--;
    
    outputString[j] = '\0';
}

// Function to sanitize input string
void sanitize(char *inputString, char *outputString)
{
    // Remove special characters
    removeSpecialChars(inputString, outputString);
    
    // Convert to uppercase
    toUpperCase(outputString);
    
    // Trim whitespace
    trim(outputString, outputString);
}

// Main function
int main()
{
    char inputString[100];
    char outputString[100];
    
    // Get user input
    printf("Enter input string: ");
    fgets(inputString, 100, stdin);
    
    // Sanitize input and print output
    sanitize(inputString, outputString);
    printf("Sanitized string: %s\n", outputString);
    
    return 0;
}