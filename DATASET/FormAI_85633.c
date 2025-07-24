//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: careful
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Check if a character is a valid URL character
bool isValid(char c) {
    return isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~';
}

// Sanitize a URL by removing any invalid characters and converting to lowercase
char *sanitize(char *url) {
    int len = strlen(url);
    char *sanitized = malloc(len + 1);

    int j = 0;
    for (int i = 0; i < len; i++) {
        char c = tolower(url[i]);
        if (isValid(c)) {
            sanitized[j++] = c;
        }
    }
    sanitized[j] = '\0';

    return sanitized;
}

// Example usage
int main() {
    char *url = "https://www.Example.com/some/path?query=string";
    char *sanitized = sanitize(url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized);

    free(sanitized);
    return 0;
}