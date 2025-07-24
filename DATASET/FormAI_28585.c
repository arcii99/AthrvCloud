//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1000

// Check if the given character is a valid URL character
bool isValidCharacter(char c) {
    return isalnum(c) || c == '.' || c == '-' || c == '_' || c == '~';
}

// Sanitize the given URL by replacing invalid characters with their URL-encoded equivalents
char* sanitizeUrl(char* url) {
    int len = strlen(url);
    char encodedChar[4];
    char* sanitizedUrl = malloc(MAX_URL_LENGTH * sizeof(char));
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (isValidCharacter(url[i])) {
            sanitizedUrl[j++] = url[i];
        } else {
            sprintf(encodedChar, "%%%02X", url[i]); // Convert invalid character to hexadecimal format
            strcat(sanitizedUrl, encodedChar); // Append the encoded character to the URL
            j += 3;
        }
    }

    return sanitizedUrl;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize:\n");
    scanf("%[^\n]", url);
    getchar(); // Consume the newline character

    // Sanitize the given URL
    char* sanitizedUrl = sanitizeUrl(url);
    printf("Sanitized URL: %s\n", sanitizedUrl);

    free(sanitizedUrl);
    return 0;
}