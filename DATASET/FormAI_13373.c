//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 100

/**
 * This function receives an url and sanitizes it, stripping all the unnecessary characters while
 * converting the rest to lowercase.
 */
char* sanitize_url(char* url) {
    char* sanitized_url = malloc(sizeof(char) * MAX_URL_LENGTH);
    int i = 0;
    int j = 0;
    char c;

    while ((c = url[i++]) != '\0') {
        if (isalpha(c) || isdigit(c) || c == ':' || c == '/' || c == '.') {
            // Convert all the letters to lowercase
            sanitized_url[j++] = tolower(c);
        }
    }

    // Add the null terminator at the end of the sanitized url
    sanitized_url[j] = '\0';

    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH];
    char* sanitized_url;

    printf("Enter a URL: ");
    scanf("%[^\n]%*c", url);

    sanitized_url = sanitize_url(url);

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}