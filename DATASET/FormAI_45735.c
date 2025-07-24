//FormAI DATASET v1.0 Category: HTML beautifier ; Style: authentic
#include <stdio.h>
#include <string.h>

int main() 
{
    // read in the HTML code
    char htmlCode[1000];
    printf("Enter the HTML code to beautify:\n");
    fgets(htmlCode, 1000, stdin);

    // beautify the code
    char beautifiedCode[1000] = "";
    int indentLevel = 0; // keep track of current indentation level
    char *token = strtok(htmlCode, "<>"); // split the code into tokens using angle brackets as delimiters
    while (token != NULL) 
    {
        // check if token is an opening tag
        if (token[0] == '/')
        {
            indentLevel--; // decrease the indentation level
        }
        else if (token[strlen(token) - 1] != '/')
        {
            // add current indentation
            for (int i = 0; i < indentLevel; i++)
            {
                strcat(beautifiedCode, "\t");
            }
            indentLevel++; // increase the indentation level
        }
        
        strcat(beautifiedCode, "<");
        strcat(beautifiedCode, token);
        strcat(beautifiedCode, ">\n");
        token = strtok(NULL, "<>");
    }

    // print out the beautified code
    printf("Beautified HTML code:\n%s", beautifiedCode);

    return 0;
}