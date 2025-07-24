//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Define the maximum length of a URL for our program.
 * We choose 255 as a reasonable limit for this example.
 * Change as necessary for your use case.
 */
#define MAX_URL_LENGTH 255

/*
 * This function sanitizes a URL by removing any characters outside of the
 * standard ASCII range (i.e. non-ASCII characters), as well as any characters
 * that are not allowed in a URL according to the RFC 3986 standard.
 */
char *sanitize_url(char *url) {
    char *sanitized_url = malloc(MAX_URL_LENGTH + 1); // +1 for null terminator
    if (sanitized_url == NULL) {
        return NULL; // out of memory
    }

    int i, j;
    for (i = 0, j = 0; url[i] != '\0' && i < MAX_URL_LENGTH; i++) {
        if (url[i] < 0 || url[i] > 127) {
            // character outside ASCII range
            continue;
        }
        if (isalnum(url[i]) || url[i] == '-' || url[i] == '_' || url[i] == '.' || url[i] == '~' ||
            url[i] == '/' || url[i] == ':' || url[i] == '?' || url[i] == '#' || url[i] == '[' ||
            url[i] == ']' || url[i] == '@' || url[i] == '!' || url[i] == '$' || url[i] == '&' ||
            url[i] == '\'' || url[i] == '(' || url[i] == ')' || url[i] == '*' || url[i] == '+' ||
            url[i] == ',' || url[i] == ';' || url[i] == '=' || url[i] == '%') {
            // character allowed in URL, copy to sanitized URL
            sanitized_url[j] = url[i];
            j++;
        }
    }

    sanitized_url[j] = '\0'; // add null terminator
    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH + 1]; // +1 for null terminator
    char *sanitized_url;

    // get user input
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH + 1, stdin);
    url[strcspn(url, "\n")] = '\0'; // remove newline character

    // sanitize the URL
    sanitized_url = sanitize_url(url);
    if (sanitized_url == NULL) {
        printf("Sanitization failed: out of memory.\n");
        return 1;
    }

    // print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // clean up memory
    free(sanitized_url);

    return 0;
}