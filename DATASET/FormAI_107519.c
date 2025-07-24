//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: creative
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_URL_LENGTH 256

// Sanitizes the URL by removing any whitespace, converting to lowercase, and replacing any non-alphanumeric characters with underscores
void sanitizeURL(char* url) {
    int length = strlen(url);
    
    // Remove whitespace from the beginning and end of the URL
    int start = 0;
    while (isspace(url[start])) {
        start++;
    }
    int end = length - 1;
    while (isspace(url[end])) {
        end--;
    }
    if (end < start) {
        url[0] = '\0';
        return;
    }
    memmove(url, &url[start], end - start + 1);
    url[end - start + 1] = '\0';
    
    // Convert to lowercase
    for (int i = 0; i < length; i++) {
        url[i] = tolower(url[i]);
    }
    
    // Replace non-alphanumeric characters with underscores
    for (int i = 0; i < length; i++) {
        if (!isalnum(url[i])) {
            url[i] = '_';
        }
    }
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    sanitizeURL(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}