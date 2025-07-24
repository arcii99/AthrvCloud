//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* This program sanitizes a URL by:
 * - converting to lowercase
 * - removing whitespace
 * - replacing backslashes with forward slashes
 * - removing any characters that are not alphanumeric or forward slashes
 */

#define MAX_URL_LENGTH 256

void sanitize_url(char *url);

int main()
{
    char url[MAX_URL_LENGTH];

    // get user input
    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    sanitize_url(url);

    printf("The sanitized URL is: %s\n", url);

    return 0;
}

void sanitize_url(char* url)
{
    int i, j;

    // convert to lowercase
    for (i = 0; url[i]; i++) {
        url[i] = tolower(url[i]);
    }

    // remove whitespace
    for (i = 0, j = 0; url[i]; i++) {
        if (!isspace(url[i])) {
            url[j++] = url[i];
        }
    }
    url[j] = '\0';

    // replace backslashes with forward slashes
    for (i = 0; url[i]; i++) {
        if (url[i] == '\\') {
            url[i] = '/';
        }
    }

    // remove any non-alphanumeric or slash characters
    for (i = 0, j = 0; url[i]; i++) {
        if (isalnum(url[i]) || url[i] == '/') {
            url[j++] = url[i];
        }
    }
    url[j] = '\0';
}