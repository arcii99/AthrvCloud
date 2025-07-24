//FormAI DATASET v1.0 Category: HTML beautifier ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HTML_SIZE 10000
#define MAX_LINE_SIZE 1000
#define INDENT_SIZE 4

int main()
{
    char html[MAX_HTML_SIZE];
    char line[MAX_LINE_SIZE];
    int indent = 0;
    int i, j, k;

    printf("Enter the HTML code: \n");
    fgets(html, MAX_HTML_SIZE, stdin);

    printf("Beautiful HTML code:\n");

    for (i = 0, j = 0; i < strlen(html); i++)
    {
        if (html[i] == '<')
        {
            if (html[i+1] == '/')
            {
                indent -= INDENT_SIZE;
            }

            for (k = 0; k < indent; k++)
            {
                line[j++] = ' ';
            }

            if (html[i+1] != '/')
            {
                indent += INDENT_SIZE;
            }
        }

        line[j++] = html[i];

        if (html[i] == '>')
        {
            line[j++] = '\n';
        }
    }

    line[j] = '\0';

    printf("%s", line);

    return 0;
}