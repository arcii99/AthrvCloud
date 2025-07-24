//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void sanitizeUrl(char* url) {
    // Declare variables
    int len = strlen(url);
    char sanitizedUrl[len+1];
    int currentIndex = 0;
    int i;

    // Loop through all characters in the URL
    for (i = 0; i < len; i++) {
        char currentChar = url[i];

        // Check if current character is alphanumeric or a dash or underscore
        if (isalnum(currentChar) || currentChar == '-' || currentChar == '_') {
            // Add current character to the sanitized URL
            sanitizedUrl[currentIndex++] = currentChar;
        }
        // Check if current character is a period
        else if (currentChar == '.') {
            // Check if the previous character was not a period
            if (i > 0 && url[i-1] != '.') {
                // Add current character to the sanitized URL
                sanitizedUrl[currentIndex++] = currentChar;
            }
        }
    }

    // Add null terminator to the end of the sanitized URL
    sanitizedUrl[currentIndex] = '\0';

    // Replace URL with sanitized URL
    strcpy(url, sanitizedUrl);
}

int main() {
    // Declare variables
    char url[100];

    // Get URL from user
    printf("Enter a URL: ");
    fgets(url, sizeof(url), stdin);

    // Remove newline character from input
    url[strcspn(url, "\n")] = 0;

    // Sanitize the URL
    sanitizeUrl(url);

    // Print sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}