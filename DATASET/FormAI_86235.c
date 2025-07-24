//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to remove special characters from the URL
char *sanitize(char *url)
{
    int len = strlen(url), i, j = 0;
    char *temp = (char *)malloc((len + 1) * sizeof(char));
    for (i = 0; i < len; i++)
    {
        if (isalnum(url[i]))
        {
            temp[j++] = url[i];
        }
    }
    temp[j] = '\0';
    return temp;
}

int main()
{
    char url[100];
    printf("Welcome to the C URL Sanitizer!\n");
    printf("Please enter a URL to sanitize:\n");
    scanf("%s", url);
    char *sanitized_url = sanitize(url);
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}