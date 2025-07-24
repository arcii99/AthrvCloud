//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Ada Lovelace
/* 
 * Ada Lovelace Style - Unique C User Input Sanitizer Example Program
 * 
 * This program will demonstrate how to sanitize user input in C language. 
 * It will take user input as string and perform some validation and filtering to ensure 
 * that the input is free from any malicious characters and unwanted spaces.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function for trimming leading and trailing spaces from the string
void trim(char *str) 
{
    int start, end, len;
    len = strlen(str);
    start = 0;
    end = len - 1;

    // Trim leading spaces
    while (isspace(str[start])) 
    {
        start++;
    }

    // Trim trailing spaces
    while ((end >= start) && (isspace(str[end]))) 
    {
        end--;
    }

    // Shift characters to left
    memmove(str, str+start, end-start+1);

    // Add string terminator
    str[end-start+1] = '\0';
}

// Function for removing non-allowed characters from the string
void remove_characters(char *str, char *remove) 
{
    int i, j, len1, len2;
    len1 = strlen(str);
    len2 = strlen(remove);

    // Loop through each character of the input string
    for (i = j = 0; i < len1; i++) 
    {
        // Check if the character is allowed
        if (strchr(remove, str[i]) == NULL) 
        {
            // Add the character to the filtered string
            str[j++] = str[i];
        }
    }

    // Add string terminator
    str[j] = '\0';
}

int main(void)
{
    char input[50];
    char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-.";
    char remove_chars[] = "()[]{};:$`<>\\/";

    // Take user input as string
    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);

    // Trim leading and trailing spaces
    trim(input);

    // Remove non-allowed characters
    remove_characters(input, remove_chars);

    // Validate input length
    if (strlen(input) < 8) 
    {
        printf("Input is too short. Please enter at least 8 characters.\n");
        return 0;
    }

    // Validate input characters
    for (int i = 0; i < strlen(input); i++) 
    {
        if (strchr(allowed_chars, input[i]) == NULL) 
        {
            printf("Input contains invalid characters. Please enter only letters, digits, and special characters -_.\n");
            return 0;
        }
    }

    // Sanitize input is clean
    printf("The sanitized input is: %s\n", input);

    return 0;
}