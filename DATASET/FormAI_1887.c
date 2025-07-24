//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Ken Thompson
/*
ASCII ART Generator Program
Author: [Your Name]
Date: [Date]

Description: This program generates ASCII art from user inputted text.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100]; // User inputted text
    int i, j, k; // Variables for loops

    printf("Enter text to generate ASCII art: ");
    scanf("%[^\n]", input); // Read input with spaces

    int len = strlen(input); // Length of inputted text

    // ASCII Art generator
    for(i=0; i<5; i++)
    {
        for(j=0; j<len; j++)
        {
            for(k=0; k<5; k++)
            {
                if(i==2 && k==2)
                    printf("%c",input[j]); // Prints the inputted text in the center of the art
                else
                    printf("%c",'*'); // Prints asterisks otherwise
            }
        }
        printf("\n"); // Creates a new line after each row
    }

    return 0; // Makes sure to return 0 to indicate successful completion
}