//FormAI DATASET v1.0 Category: String manipulation ; Style: expert-level
#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str)
{
    int i, j = strlen(str) - 1;
    char temp;
    
    for(i = 0; i < j; i++, j--)
    {
        // Swap characters
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to concatenate two strings
void concatenateStrings(char* str1, char* str2)
{
    int i, j;
    
    // Find the end of the first string
    i = strlen(str1);
    
    // Copy the second string to the end of the first string
    for(j = 0; str2[j] != '\0'; j++, i++)
    {
        str1[i] = str2[j];
    }
    
    // Add the null terminator at the end of the new string
    str1[i] = '\0';
}

int main()
{
    char str1[100], str2[100];
    
    // Get input strings from user
    printf("Enter string 1: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter string 2: ");
    fgets(str2, sizeof(str2), stdin);
    
    // Remove newline characters at the end of input strings
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';
    
    // Reverse the first string
    reverseString(str1);
    printf("Reversed string 1: %s\n", str1);
    
    // Concatenate the two strings
    concatenateStrings(str1, str2);
    printf("Concatenated string: %s\n", str1);
    
    return 0;
}