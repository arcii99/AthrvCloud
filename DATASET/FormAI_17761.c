//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Sanitize the URL and remove any unwanted characters
char *sanitizeURL(char *url) {
    // Create a new string to hold the sanitized URL
    char *sanitized = malloc(strlen(url) + 1);
    strcpy(sanitized, url);
    int i, j = 0;
    bool skip = false;

    // Loop through each character in the URL string
    for (i = 0; i < strlen(url); i++) {
        // Check if the character is a valid URL character
        if ((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z')
            || (url[i] >= '0' && url[i] <= '9') || url[i] == '.' || url[i] == '/'
            || url[i] == ':' || url[i] == '?' || url[i] == '=' || url[i] == '&' || url[i] == '_') {
            // If the character is valid, add it to the sanitized string
            sanitized[j] = url[i];
            j++;
            skip = false;
        }
        else if (!skip) {
            // If the character is invalid and we haven't already skipped a character,
            // add an underscore to the sanitized string and skip the next character
            sanitized[j] = '_';
            j++;
            skip = true;
        }
    }

    // Add a null terminator to the end of the sanitized string
    sanitized[j] = '\0';
    return sanitized;
}

int main() {
    char url[100];
    printf("Enter a URL to sanitize: ");
    fgets(url, 100, stdin);
    // Remove the newline character from the end of the input
    url[strcspn(url, "\n")] = '\0';
    char *sanitized = sanitizeURL(url);
    printf("Sanitized URL: %s\n", sanitized);
    free(sanitized);
    return 0;
}