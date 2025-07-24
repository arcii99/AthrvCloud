//FormAI DATASET v1.0 Category: Text processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 1000

int main()
{
    char input[MAX_SIZE], output[MAX_SIZE];
    int i, j = 0;

    printf("Enter some text: ");
    fgets(input, MAX_SIZE, stdin);

    for (i = 0; i < strlen(input); i++)
    {
        if (isalpha(input[i]))
        {
            // Convert to lowercase and add to output
            output[j] = tolower(input[i]);
            j++;
        }
        else if (input[i] == ' ' && input[i+1] != ' ')
        {
            // Add a '-' to output for whitespace
            output[j] = '-';
            j++;
        }
        // Ignore any other characters
    }

    output[j] = '\0'; // Add null character to end the string

    printf("\nProcessed text: %s\n", output);

    return 0;
}