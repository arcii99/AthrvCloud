//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HTML_SIZE 1000
#define MAX_LINE_CHARS 80
#define TAB_SIZE 4

void beautify(char *html, int len, char *out);
char *generate_spaces(int num_spaces);

int main()
{
    char html_input[MAX_HTML_SIZE];
    char html_output[MAX_HTML_SIZE];

    printf("Enter HTML code: ");
    fgets(html_input, MAX_HTML_SIZE, stdin);

    beautify(html_input, strlen(html_input), html_output);

    printf("Beautified HTML code:\n%s", html_output);

    return 0;
}

void beautify(char *html, int len, char *out)
{
    int indent_level = 0;
    char *line = strtok(html, "\n");
    char curr_line[MAX_LINE_CHARS];

    while (line != NULL)
    {
        int line_length = strlen(line);

        if (line_length == 0)
        {
            line = strtok(NULL, "\n");
            continue;
        }

        strncpy(curr_line, line, line_length + 1);
        curr_line[line_length] = '\0';

        if (curr_line[0] == '<')
        {
            if (curr_line[1] == '/')
            {
                indent_level--;
            }

            if (indent_level > 0)
            {
                sprintf(out, "%s\n%s%s", out, generate_spaces(indent_level * TAB_SIZE), curr_line);
            }
            else
            {
                sprintf(out, "%s\n%s", out, curr_line);
            }

            if (curr_line[1] != '/')
            {
                indent_level++;
            }
        }
        else
        {
            sprintf(out, "%s\n%s%s", out, generate_spaces((indent_level - 1) * TAB_SIZE), curr_line);
        }

        line = strtok(NULL, "\n");
    }

    sprintf(out, "%s\n", out);
}

char *generate_spaces(int num_spaces)
{
    char *spaces = malloc(num_spaces + 1);
    memset(spaces, ' ', num_spaces);
    spaces[num_spaces] = '\0';
    return spaces;
}