//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: calm
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// This function sanitizes a URL by removing any invalid characters and ensuring it starts with "http://"
char* sanitizeUrl(char* url) {
    // Remove any whitespace from the beginning and end of the URL
    char* sanitizedUrl = strdup(url);
    char* end;

    while (isspace(*sanitizedUrl)) {
        sanitizedUrl++;
    }

    end = sanitizedUrl + strlen(sanitizedUrl) - 1;
    while (end > sanitizedUrl && isspace(*end)) {
        end--;
    }
    *(end + 1) = '\0';

    // Ensure the URL starts with "http://" or "https://"
    if (strncmp(sanitizedUrl, "http://", 7) != 0 && strncmp(sanitizedUrl, "https://", 8) != 0) {
        char* temp = malloc(strlen(sanitizedUrl) + 8); // Add space for "http://"
        strcpy(temp, "http://");
        strcat(temp, sanitizedUrl);
        free(sanitizedUrl);
        sanitizedUrl = temp;
    }

    // Remove invalid characters from the URL
    char* p = sanitizedUrl;
    while (*p) {
        if (!isalnum(*p) && *p != '-' && *p != '_' && *p != '.' && *p != '/') {
            *p = '_';
        }
        p++;
    }

    return sanitizedUrl;
}

int main() {
    char* url = "example! url with spaces? and other invalid characters";
    char* sanitizedUrl = sanitizeUrl(url);
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitizedUrl);
    free(sanitizedUrl);
    return 0;
}