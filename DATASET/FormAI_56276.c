//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/* Function to check if a given character is valid in a URL */
bool isValidChar(char ch) {
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')
            || (ch >= '0' && ch <= '9') || ch == '-' || ch == '_'
            || ch == '.' || ch == '~');
}

/* Function to remove the invalid characters from a URL */
char* sanitizeURL(char* url) {
    int i, j;
    char* sanitized = (char*) malloc(strlen(url) + 1);

    for (i = 0, j = 0; i < strlen(url); i++) {
        if (isValidChar(url[i])) {
            sanitized[j] = url[i];
            j++;
        }
    }

    sanitized[j] = '\0'; // Add null terminator at the end
    return sanitized;
}

int main() {
    char url[100], *sanitizedURL;

    printf("Enter a URL: ");
    fgets(url, sizeof(url), stdin);

    /* Remove new line character '\n' from the input string */
    if (url[strlen(url) - 1] == '\n') {
        url[strlen(url) - 1] = '\0';
    }

    /* Sanitize the URL */
    sanitizedURL = sanitizeURL(url);
    
    printf("Sanitized URL: %s\n", sanitizedURL);

    free(sanitizedURL); // Free the memory allocated for the sanitized URL

    return 0;
}