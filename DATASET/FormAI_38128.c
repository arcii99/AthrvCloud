//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: shocked
#include <stdio.h>
#include <string.h>

#define MAX_URL_LEN 1000

void sanitizeUrl(char* url)
{
    // Remove any whitespace characters from the beginning and end of the URL
    char* temp = url;
    while (*temp == ' ')
        temp++;

    size_t len = strlen(temp);
    while (len > 0 && temp[len - 1] == ' ')
    {
        temp[len - 1] = '\0';
        len--;
    }

    // Remove any 'http://' or 'https://' prefixes from the URL
    if (strncmp(temp, "http://", 7) == 0 || strncmp(temp, "https://", 8) == 0)
    {
        memmove(temp, temp + (temp[4] == 's' ? 8 : 7), strlen(temp + (temp[4] == 's' ? 8 : 7)) + 1);
    }

    // Remove any trailing slashes from the URL
    len = strlen(temp);
    while (len > 0 && temp[len - 1] == '/')
    {
        temp[len - 1] = '\0';
        len--;
    }

    // Replace any consecutive forward slashes with a single forward slash
    char* prev = temp;
    char* curr = strchr(temp, '/');
    while (curr)
    {
        if (curr[1] == '/')
            memmove(curr + 1, curr + 2, strlen(curr + 2) + 1);

        prev = curr;
        curr = strchr(prev + 1, '/');
    }

    // Remove any fragments or query strings from the URL
    curr = strchr(temp, '#');
    if (curr)
        *curr = '\0';

    curr = strchr(temp, '?');
    if (curr)
        *curr = '\0';

    // Convert any uppercase characters in the URL to lowercase
    for (size_t i = 0; i < strlen(temp); i++)
    {
        if (temp[i] >= 'A' && temp[i] <= 'Z')
            temp[i] = temp[i] - 'A' + 'a';
    }
}

int main()
{
    char url[MAX_URL_LEN];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LEN, stdin);
    sanitizeUrl(url);
    printf("Sanitized URL: %s\n", url);

    return 0;
}