//FormAI DATASET v1.0 Category: HTML beautifier ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1000];
    char output[1000];
    int count = 0;
    char indent[] = "    ";

    printf("Enter your HTML code:\n");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, "<>");

    while (token != NULL)
    {
        if (token[0] == '/')
        {
            count--;
        }

        for (int i=0; i<count; i++)
        {
            strcat(output, indent);
        }

        strcat(output, "<");
        strcat(output, token);
        strcat(output, ">");

        if (token[0] != '/')
        {
            count++;
        }

        strcat(output, "\n");
        token = strtok(NULL, "<>");
    }

    printf("Your beautified HTML code is:\n%s", output);

    return 0;
}