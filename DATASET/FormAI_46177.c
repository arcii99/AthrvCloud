//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: futuristic
#include <stdio.h>
#include <string.h>

#define MAX_URL_LENGTH 1000

void sanitize(char* url) {
    int i, j = 0;
    char sanitized_url[MAX_URL_LENGTH];

    for (i = 0; i < strlen(url); i++) {
        // If character is alphanumeric
        if (isalnum(url[i])) {
            sanitized_url[j++] = url[i];
        } else if (url[i] == ':') {
            // Replace colon with forward slash
            sanitized_url[j++] = '/';
        } else if (url[i] == '/') {
            // Copy two forward slashes and continue
            sanitized_url[j++] = '/';
            sanitized_url[j++] = '/';
        }
    }

    // Add null terminator to end of sanitized URL
    sanitized_url[j] = '\0';

    // Copy sanitized URL back into original URL buffer
    strcpy(url, sanitized_url);
}

int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Replace newline character at end of URL with null terminator
    url[strlen(url)-1] = '\0';

    printf("Sanitizing URL...\n");

    // Sanitize the URL
    sanitize(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}