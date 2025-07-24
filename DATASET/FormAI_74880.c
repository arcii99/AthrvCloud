//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

void sanitize_url(char *url) {
    char sanitized_url[MAX_URL_LENGTH];
    int j = 0;

    for (int i = 0; url[i] != '\0'; i++) {
        // Only copy over alphanumeric and some special characters
        if (isalnum(url[i]) ||
            url[i] == '.' || url[i] == '-' || url[i] == '_' ||
            url[i] == '/' || url[i] == ':' || url[i] == '?' ||
            url[i] == '&' || url[i] == '=') {
            sanitized_url[j++] = url[i];
        }
    }

    // Null terminate the sanitized URL
    sanitized_url[j] = '\0';

    // Copy the sanitized URL back into the original buffer
    strncpy(url, sanitized_url, MAX_URL_LENGTH);
}

int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    sanitize_url(url);

    printf("\nSanitized URL: %s\n", url);

    return 0;
}