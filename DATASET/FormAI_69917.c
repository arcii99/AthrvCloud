//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype for URL sanitizer
char* sanitize_url(char* url);

int main()
{
    // Test cases
    char url1[] = "https://www.example.com/path?query=example";
    char url2[] = "ftp://user:password@www.example.com/path";
    char url3[] = "http://www.example.com/#fragment";

    // Print original URLs
    printf("Original URLs:\n");
    printf("%s\n%s\n%s\n", url1, url2, url3);

    // Sanitize URLs using sanitize_url function
    char* sanitized1 = sanitize_url(url1);
    char* sanitized2 = sanitize_url(url2);
    char* sanitized3 = sanitize_url(url3);

    // Print sanitized URLs
    printf("\nSanitized URLs:\n");
    printf("%s\n%s\n%s\n", sanitized1, sanitized2, sanitized3);

    // Free memory for sanitized URLs
    free(sanitized1);
    free(sanitized2);
    free(sanitized3);

    return 0;
}

/*
 * sanitize_url - Function to sanitize URL by removing any sensitive information
 * such as username, password and fragment identifier
 *
 * @param: url - pointer to url string to be sanitized
 * @return: pointer to sanitized url string
 */
char* sanitize_url(char* url)
{
    // Allocate memory for sanitized url string
    char* sanitized = malloc(strlen(url) + 1);

    // Check for valid memory allocation
    if(sanitized == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Copy original url to sanitized url string
    strcpy(sanitized, url);

    // Find protocol separator (e.g. "://" in "http://")
    char* protocol = strstr(sanitized, "://");

    if(protocol != NULL) {
        // Find username and password separator (e.g. "@" in "user:pass@")
        char* auth = strchr(protocol + 3, '@');

        if(auth != NULL) {
            // Replace username:password@ with empty string
            memmove(protocol + 3, auth + 1, strlen(auth));
            sanitized[strlen(sanitized) - strlen(auth) - 3] = '\0';
        }
    }

    // Find fragment identifier (e.g. "#" in "http://example.com/page#section")
    char* fragment = strchr(sanitized, '#');

    if(fragment != NULL) {
        // Remove fragment identifier and everything after it
        *fragment = '\0';
    }

    return sanitized;
}