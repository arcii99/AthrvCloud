//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitize(char *url);

int main()
{
    char url[100];

    printf("Enter a URL: ");
    fgets(url, 100, stdin);

    sanitize(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}

void sanitize(char *url)
{
    char *p = url;

    while (*p)
    {
        if (*p == ' ')
        {
            *p = '+';
        }
        else if (!isalnum(*p) && *p != '-' && *p != '_' && *p != '.' && *p != '/')
        {
            *p = '%';
            *(p + 1) = toupper(*(p + 1));
            *(p + 2) = toupper(*(p + 2));
        }

        p++;
    }
}