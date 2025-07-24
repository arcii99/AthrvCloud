//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: distributed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to sanitize URL
void sanitizeURL(char *url)
{
    // converting all characters to lowercase
    int i;
    for (i = 0; url[i]; i++)
    {
        url[i] = tolower(url[i]);
    }

    // check if URL begins with http:// or https://
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0)
    {
        // if not, add https:// to the beginning of URL
        memmove(url + 8, url, strlen(url) + 1);
        strncpy(url, "https://", 8);
    }

    // check if URL ends with a '/'
    if (url[strlen(url) - 1] == '/')
    {
        url[strlen(url) - 1] = '\0';
    }
}

int main()
{
    char url[100];

    // take input URL from user
    printf("Enter URL: ");
    scanf("%s", url);

    sanitizeURL(url);

    // print sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}