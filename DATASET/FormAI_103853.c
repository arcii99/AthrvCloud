//FormAI DATASET v1.0 Category: HTML beautifier ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// Function to check if a character is a whitespace character
bool is_whitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

// Function to remove leading whitespace characters from a string
char* remove_leading_whitespace(char* str)
{
    int i, j;
    char* new_str = malloc(strlen(str) + 1);

    for (i = 0; is_whitespace(str[i]); i++)
    {
        // Do nothing, just skip the whitespace characters
    }

    for (j = 0; str[i] != '\0'; j++, i++)
    {
        new_str[j] = str[i];
    }

    new_str[j] = '\0';

    return new_str;
}

// Function to beautify the input HTML code
void beautify_html(char* html)
{
    int i, j;
    bool in_tag = false;
    int indentation_level = 0;

    // Remove leading whitespace characters from the input HTML
    html = remove_leading_whitespace(html);

    for (i = 0; html[i] != '\0'; i++)
    {
        if (html[i] == '<')
        {
            in_tag = true;
            printf("%c", html[i]);

            if (html[i + 1] == '/')
            {
                indentation_level--;
            }

            printf("\n");

            for (j = 0; j < indentation_level; j++)
            {
                printf("    ");
            }

            if (html[i + 1] != '/')
            {
                indentation_level++;
            }
        }
        else if (html[i] == '>')
        {
            in_tag = false;
            printf("%c", html[i]);
            printf("\n");
        }
        else if (!in_tag)
        {
            printf("%c", html[i]);

            if (html[i] == '\n' || html[i] == '\r')
            {
                for (j = 0; j < indentation_level; j++)
                {
                    printf("    ");
                }
            }
        }
        else
        {
            printf("%c", html[i]);
        }
    }
}

int main()
{
    // Example input HTML code
    char html[] = "<html><head><title>Example Title</title></head><body><p>Example Paragraph</p></body></html>";

    // Beautify the input HTML code
    beautify_html(html);

    return 0;
}