//FormAI DATASET v1.0 Category: Text processing ; Style: authentic
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100], output[100];
    int i, j;

    printf("Enter a string: ");
    fgets(input, 100, stdin);

    // Removing any punctuation marks from the input string
    for (i = 0, j = 0; i < strlen(input); i++)
    {
        if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z'))
        {
            output[j] = input[i];
            j++;
        }
    }
    output[j] = '\0'; // Terminating the output string

    // Converting the input string into title case
    for (i = 0; i < strlen(output); i++)
    {
        if (i == 0)
        {
            output[i] = toupper(output[i]);
        }
        else if (output[i] == ' ')
        {
            output[i + 1] = toupper(output[i + 1]);
        }
    }

    // Printing the final processed string
    printf("Processed string: ");
    puts(output);

    return 0;
}