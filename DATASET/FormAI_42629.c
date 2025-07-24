//FormAI DATASET v1.0 Category: HTML beautifier ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    printf("Enter the HTML code:\n");

    char ch, prev_ch = '\0';

    while ((ch = getchar()) != EOF)
    {
        if (ch == ' ' && prev_ch == '<')
        {
            continue;
        }
        else if (ch == '\n' && prev_ch == '<')
        {
            putchar(prev_ch);
        }
        else if (ch == '>' && prev_ch == '/')
        {
            printf("%c", prev_ch);
        }
        else if (ch == '<' && prev_ch == '/')
        {
            printf("\n%c", prev_ch);
        }
        else if (ch == '>')
        {
            printf("%c\n", ch);
        }
        else if (ch == '<')
        {
            printf("\n%c", ch);
        }
        else
        {
            putchar(ch);
        }

        prev_ch = ch;
    }

    return 0;
}