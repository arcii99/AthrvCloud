//FormAI DATASET v1.0 Category: HTML beautifier ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char html[10000];
    int i, j, k, l, m, n, o, p;
    printf("Enter the HTML code:\n");
    fgets(html, 10000, stdin);

    i = 0;
    while (html[i] != '\0')
    {
        if (html[i] == '<')
        {
            j = i;
            while (html[j] != '>')
            {
                j++;
            }
            printf("<");
            for (k = i+1; k < j; k++)
            {
                printf("%c",toupper(html[k]));
            }
            printf(">");
            i = j;
        }
        else
        {
            printf("%c", html[i]);
        }
        i++;
    }

    return 0;
}