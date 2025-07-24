//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum length of a valid URL
#define MAX_URL_LENGTH 100

/**
 * Function to sanitize a URL by removing any potential malicious code
 * and ensuring it adheres to the correct format.
 */
void sanitizeURL(char *url) {
    // Check if URL is longer than maximum valid length
    if (strlen(url) > MAX_URL_LENGTH) {
        printf("Error: URL exceeds maximum valid length.\n");
        exit(EXIT_FAILURE);
    }
    
    // Remove any potential malicious code
    char *maliciousCode = "<script>";
    char *foundCode = strstr(url, maliciousCode);
    if (foundCode != NULL) {
        int index = foundCode - url;
        memmove(&url[index], &url[index + strlen(maliciousCode)],
                strlen(&url[index + strlen(maliciousCode)]) + 1);
    }

    // Add "http://" to the beginning of the URL if it is not present
    char *http = "http://";
    if (strncmp(url, http, strlen(http)) != 0) {
        memmove(&url[strlen(http)], &url[0], strlen(url) + 1);
        memcpy(&url[0], http, strlen(http));
    }

    // Ensure the URL ends with a forward slash
    char *lastChar = &url[strlen(url) - 1];
    if (*lastChar != '/') {
        char newUrl[MAX_URL_LENGTH];
        strcpy(newUrl, url);
        strcat(newUrl, "/");
        strcpy(url, newUrl);
    }
}

int main() {
    char url[MAX_URL_LENGTH];

    // Input a URL to sanitize
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = 0; // Remove newline character

    // Sanitize the URL and print the result
    sanitizeURL(url);
    printf("Sanitized URL: %s\n", url);

    return 0;
}