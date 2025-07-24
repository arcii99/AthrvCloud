//FormAI DATASET v1.0 Category: HTML beautifier ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input_html[10000];
    char output_html[10000];
    int input_len, output_len, temp_len;
    int i, j, k;
    int indent_level = 0;
    int bracket_flag = 0; // for keeping track of open and close brackets

    printf("Enter HTML code (max 9999 characters): \n");
    fgets(input_html, 10000, stdin);

    input_len = strlen(input_html);

    // Removing extra spaces
    for(i = 0, j = 0; i < input_len; i++)
    {
        if((input_html[i] != ' ') && (input_html[i] != '\t'))
        {
            output_html[j++] = input_html[i];
        }
        if((input_html[i] == '>') && (i < input_len-1) && (input_html[i+1] != '<'))
        {
            output_html[j++] = '\n';
            for(k = 0; k < indent_level; k++)
            {
                output_html[j++] = '\t';
            }
        }
    }

    output_len = strlen(output_html);

    // Adding indentation
    for(i = 0; i < output_len; i++)
    {
        if(output_html[i] == '<')
        {
            if(output_html[i+1] == '/')
            {
                indent_level--; // decrease indent level for end tags
            }
            else
            {
                if(bracket_flag == 1) // if opening bracket exists
                {
                    output_html[i] = '\n'; // add newline before new tag - opening bracket
                    for(k = 0; k < indent_level; k++)
                    {
                        output_html[i+k+1] = '\t'; // add tabs for proper indentation
                    }
                }
                else
                {
                    bracket_flag = 1; // first opening bracket found
                }
                indent_level++; // increase indent level for start tags
            }
        }
        else if(output_html[i] == '/')
        {
            if(output_html[i+1] == '>')
            {
                indent_level--; // decrease indent level for self-closing tags
            }
        }
    }
    printf("Beautified HTML code:\n\n%s", output_html);
    return 0;
}