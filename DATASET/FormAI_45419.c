//FormAI DATASET v1.0 Category: String manipulation ; Style: unmistakable
#include <stdio.h>
#include <string.h>

int main()
{
    // Declare variables for user input and result string
    char str[100], result[100];
    int length, i, j = 0;

    // Get input from user
    printf("Enter a string: ");
    gets(str);

    // Get length of string
    length = strlen(str);

    // Loop through string backwards and append to result string
    for(i = length - 1; i >= 0; i--)
    {
        char c = str[i];

        // Check if character is a letter
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            // Convert letter to ASCII code and add to result string
            int ascii_code = (int) c;
            sprintf(&result[j], "%d", ascii_code);
            j += strlen(&result[j]);
        }
        else
        {
            // If not a letter, simply add to result string
            result[j] = c;
            j++;
        }
    }

    // Null terminate result string
    result[j] = '\0';

    // Print result string
    printf("\nResult: %s\n", result);

    return 0;
}