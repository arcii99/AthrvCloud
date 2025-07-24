//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautifyHTML(char* htmlCode);

int main()
{
    char code[5000];
    printf("Enter the HTML code to beautify:\n");
    fgets(code, 5000, stdin);
    beautifyHTML(code);
    printf("\nThe beautified code is:\n%s", code);
    return 0;
}

void beautifyHTML(char* htmlCode) 
{
    int indentSize = 0;
    char formattedCode[5000];
    int formattedCodeIndex = 0;

    char* pch = strtok(htmlCode, "<>");
    while (pch != NULL)
    {
        if (pch[0] != '/')
        {
            for (int i = 0; i < indentSize; i++)
            {
                strcat(formattedCode, "\t");
                formattedCodeIndex++;
            }
            strcat(formattedCode, "<");
            strcat(formattedCode, pch);
            strcat(formattedCode, ">");

            if (strcmp(pch, "br") != 0 && strcmp(pch, "img") != 0)
            {
                strcat(formattedCode, "\n");
                formattedCodeIndex++;
                indentSize++;
            }
        }
        else
        {
            indentSize--;
            formattedCodeIndex -= 5;
            for (int i = 0; i < indentSize; i++)
            {
                strcat(formattedCode, "\t");
                formattedCodeIndex++;
            }
            strcat(formattedCode, "</");
            strcat(formattedCode, pch + 1);
            strcat(formattedCode, ">\n");
        }

        pch = strtok(NULL, "<>");
    }

    strcpy(htmlCode, formattedCode);
}