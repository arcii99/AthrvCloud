//FormAI DATASET v1.0 Category: Text processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input_str[100], output_str[100];
    int i, j = 0;

    printf("Enter the string you want to process: ");
    fgets(input_str, sizeof(input_str), stdin);

    // Remove extra whitespaces from the input string
    for (i = 0; input_str[i] != '\0'; i++)
    {
        if (input_str[i] != ' ' || (i > 0 && input_str[i - 1] != ' '))
        {
            output_str[j++] = input_str[i];
        }
    }

    output_str[j] = '\0';

    // Capitalize the first letter of each word in the output string
    for (i = 0; output_str[i] != '\0'; i++)
    {
        if (i == 0 || (i > 0 && output_str[i - 1] == ' '))
        {
            if (output_str[i] >= 'a' && output_str[i] <= 'z')
            {
                output_str[i] = output_str[i] - 'a' + 'A';
            }
        }
        else
        {
            if (output_str[i] >= 'A' && output_str[i] <= 'Z')
            {
                output_str[i] = output_str[i] + 'a' - 'A';
            }
        }
    }

    printf("\nProcessed String: %s\n", output_str);

    return 0;
}