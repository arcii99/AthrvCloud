//FormAI DATASET v1.0 Category: HTML beautifier ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the HTML Beautifier Program!\n\n");
    printf("Please enter the HTML string that you want to beautify: ");

    char html[1000];
    fgets(html, sizeof(html), stdin);

    char indent[100] = "    ";
    int indentLevel = 0;
    int i = 0;

    while (html[i] != '\0')
    {
        if (html[i] == '<')
        {
            printf("%s<", indent);
            indentLevel++;
        }
        else if (html[i] == '>')
        {
            printf(">\n");
        }
        else if (html[i] == '/')
        {
            indentLevel--;
            printf("%s/", indent);
        }
        else
        {
            printf("%c", html[i]);
        }

        if (html[i] == '\n')
        {
            printf("\n");
        }

        for (int j = 0; j < indentLevel; j++)
        {
            printf("%s", indent);
        }

        i++;
    }

    return 0;
}