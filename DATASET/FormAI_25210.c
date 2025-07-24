//FormAI DATASET v1.0 Category: HTML beautifier ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    char input[1000];
    char output[10000];
    char indentChar = ' ';
    int indentSize = 4;
    int indentLevel = 0;
    bool inTag = false, inAttribute = false, inValue = false, inQuote = false, inComment = false;
    int charCount = 0, outputCount = 0;
    printf("Enter the HTML to beautify:\n");

    fgets(input, sizeof(input), stdin); // Read input from user

    for (int i = 0; i < strlen(input); i++)
    {
        if (!inComment)
        {
            if (input[i] == '<')
            {
                inTag = true;
                inAttribute = false;
                inValue = false;
                inQuote = false;
                charCount--;
                indentLevel++;
            }
            else if (input[i] == '>')
            {
                inTag = false;
                inAttribute = false;
                inValue = false;
                inQuote = false;
            }
            else if (inTag && input[i] == '/')
            {
                indentLevel--;
            }
            else if (!inTag && input[i] == ' ' && !inQuote)
            {
                continue;
            }
            else if (inTag && input[i] == ' ')
            {
                if (!inAttribute)
                    inAttribute = true;
            }
            else if (inAttribute && input[i] != ' ' && input[i] != '=')
            {
                inValue = true;
                charCount--;
            }
            else if (inValue && input[i] == '"' || input[i] == '\'')
            {
                if (!inQuote)
                    inQuote = true;
                else
                    inValue = false;
            }
            else if (inQuote && input[i] == '"' || input[i] == '\'')
            {
                inQuote = false;
                inValue = false;
            }
            else if (input[i] == '<' && input[i + 1] == '!')
            {
                inComment = true;
            }

            if (charCount % 60 == 0 && !inTag)
            {
                output[outputCount] = '\n';
                outputCount++;
                for (int j = 0; j < indentLevel * indentSize; j++)
                {
                    output[outputCount] = indentChar;
                    outputCount++;
                }
            }
            output[outputCount] = input[i];
            outputCount++;
            charCount++;
        }
        else if (input[i] == '-' && input[i + 1] == '-' && input[i + 2] == '>')
        {
            inComment = false;
            i += 2;
        }
    }

    printf("The beautified HTML is:\n%s", output);

    return 0;
}