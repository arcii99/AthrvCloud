//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Maximum length for a URL
#define URL_MAX_LENGTH 2083

// List of characters allowed in a URL
static const char* allowed_characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-._~:/?#[]@!$&'()*+,;=";

// Sanitizes the URL by removing any characters that are not allowed
char* sanitize_url(char* url) {
    // Allocate memory for the sanitized URL
    char* sanitized_url = (char*) malloc(sizeof(char) * URL_MAX_LENGTH);
    if (!sanitized_url) {
        fprintf(stderr, "Error: Unable to allocate memory for the sanitized URL.\n");
        return NULL;
    }

    int i, j;
    for (i = 0, j = 0; url[i] && j < URL_MAX_LENGTH-1; i++) {
        // Check if the character is allowed
        if (strchr(allowed_characters, url[i])) {
            sanitized_url[j++] = url[i];
        }
        else {
            // Replace the character with its hexadecimal representation
            char hex[3];
            snprintf(hex, 3, "%02X", url[i]);
            sanitized_url[j++] = '%';
            sanitized_url[j++] = toupper(hex[0]);
            sanitized_url[j++] = toupper(hex[1]);
        }
    }

    // Null terminate the sanitized URL
    sanitized_url[j] = '\0';

    return sanitized_url;
}

int main() {
    char url[URL_MAX_LENGTH];

    // Read the URL from the user
    printf("Enter the URL to sanitize: ");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = '\0';

    // Sanitize the URL
    char* sanitized_url = sanitize_url(url);
    if (!sanitized_url) {
        return 1;
    }

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // Free memory
    free(sanitized_url);

    return 0;
}