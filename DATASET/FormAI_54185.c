//FormAI DATASET v1.0 Category: HTML beautifier ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautifyHTML(char* input) 
{
    // Initialization
    int len = strlen(input);
    char output[len + 1];
    int indent = 0;
    int inTag = 0;

    for(int i = 0; i < len; i++)
    {
        // If the character is '<', begin a new tag
        if(input[i] == '<')
        {
            // If it's a closing tag, decrease the indent
            if(input[i+1] == '/')
            {
                indent--;
            }

            // Add the indent to the output
            for(int j = 0; j < indent; j++)
            {
                strncat(output, "\t", 1);
            }

            // Add the tag to the output
            strncat(output, &input[i], 1);

            // If it's an opening tag, increase the indent
            if(input[i+1] != '/')
            {
                indent++;
            }

            inTag = 1;
        }
        // If the character is '>', end the current tag
        else if(input[i] == '>')
        {
            strncat(output, &input[i], 1);
            strncat(output, "\n", 1);

            inTag = 0;
        }
        // Otherwise, add the character to the output
        else
        {
            if(!inTag) 
            {
                for(int j = 0; j < indent; j++)
                {
                    strncat(output, "\t", 1);
                }
            }

            strncat(output, &input[i], 1);
        }
    }

    // Printing the beautified HTML
    printf("%s", output);
}

int main()
{
    // Example HTML code
    char input[] = "<html><head><title>Page Title</title></head><body><h1>This is a Heading</h1><p>This is a paragraph.</p></body></html>";

    // Beautify the HTML
    beautifyHTML(input);

    return 0;
}