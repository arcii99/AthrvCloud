//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 500

// function to sanitize the given URL string
char* sanitize_URL(char* url)
{
    // remove the whitespace characters from the beginning and end of the URL
    char* sanitized_url = url;

    while (isspace(*sanitized_url))
        sanitized_url++;

    for (size_t i = strlen(sanitized_url) - 1; i > 0 && isspace(sanitized_url[i]); i--)
        sanitized_url[i] = '\0';

    // convert the URL string to lowercase
    for (char* p = sanitized_url; *p; ++p)
        *p = tolower(*p);

    // remove the query string from the URL
    char* query_string_start = strchr(sanitized_url, '?');

    if (query_string_start)
        *query_string_start = '\0';

    // remove any trailing slashes from the URL
    size_t length = strlen(sanitized_url);

    if (length > 1 && sanitized_url[length - 1] == '/')
        sanitized_url[length - 1] = '\0';

    // remove any duplicate slashes from the URL
    char* p = sanitized_url;

    while (*p && *(p + 1))
    {
        if (*p == '/' && *(p + 1) == '/')
        {
            char* q = p + 1;

            while (*q == '/')
                q++;

            memmove(p + 1, q, strlen(q) + 1);
        }

        p++;
    }

    // truncate the URL if it is too long
    if (strlen(sanitized_url) > MAX_URL_LENGTH)
        sanitized_url[MAX_URL_LENGTH] = '\0';

    return sanitized_url;
}

int main()
{
    // test the URL sanitizer function
    char url[MAX_URL_LENGTH] = "    HTTPs://eXPamle.ORG:883//paTH/to/fiLe.html?VARIABLE1=value1&variable2=value2    ";

    printf("Original URL: %s\n", url);

    char* sanitized_url = sanitize_URL(url);

    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}