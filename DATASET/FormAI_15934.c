//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Sherlock Holmes
#include <stdio.h>

#define MAX_URL_LENGTH 200

/* define a function to sanitize the URL */
void sanitize_url(char *url)
{
    int i, j = 0;
    char sanitized[MAX_URL_LENGTH];

    /* iterate through each character in the URL */
    for (i = 0; url[i] != '\0'; i++) {
        /* if the character is a backslash, add an extra one to sanitize it */
        if (url[i] == '\\') {
            sanitized[j] = '\\';
            j++;
        }

        /* if the character is a double quote, add an extra one to sanitize it */
        if (url[i] == '\"') {
            sanitized[j] = '\"';
            j++;
        }

        /* if the character is a single quote, add an extra one to sanitize it */
        if (url[i] == '\'') {
            sanitized[j] = '\'';
            j++;
        }

        /* otherwise, just copy the character over as-is */
        sanitized[j] = url[i];
        j++;

        /* make sure the sanitized URL does not exceed the maximum length */
        if (j >= MAX_URL_LENGTH) {
            break;
        }
    }

    /* make sure the sanitized URL is null-terminated */
    sanitized[j] = '\0';

    /* copy the sanitized URL back to the original variable */
    strcpy(url, sanitized);
}

int main()
{
    char url[MAX_URL_LENGTH];

    /* prompt the user for a URL to sanitize */
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    /* sanitize the URL */
    sanitize_url(url);

    /* print the sanitized URL */
    printf("Sanitized URL: %s\n", url);

    return 0;
}