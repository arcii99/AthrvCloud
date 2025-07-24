//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: careful
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_URL_LEN 1000

// Function to sanitize URL by removing dangerous characters
void sanitize_url(char url[]) {
    char sanitized_url[MAX_URL_LEN+1];
    int url_len = strlen(url), sanitized_url_len = 0;
    bool is_scheme_present = false;
    for (int i = 0; i < url_len; i++) {
        if (url[i] == ':') {
            // Check if scheme is present
            if (i > 0 && isalpha(url[i-1])) {
                is_scheme_present = true;
                sanitized_url[sanitized_url_len++] = url[i];
            } else {
                // Otherwise remove the colon
                continue;
            }
        } else if (isalnum(url[i]) || url[i] == '.' || url[i] == '-' || url[i] == '_') {
            // Allow only alphanumeric characters, period, hyphen and underscore
            sanitized_url[sanitized_url_len++] = url[i];
        } else if (url[i] == '/') {
            // Add a forward slash only if scheme is present
            if (is_scheme_present) {
                sanitized_url[sanitized_url_len++] = url[i];
            }
        } else {
            // Remove all other characters
            continue;
        }
    }
    sanitized_url[sanitized_url_len] = '\0';
    // Copy the sanitized URL back to the original URL
    strcpy(url, sanitized_url);
}

int main() {
    char url[MAX_URL_LEN+1];
    printf("Enter the URL: ");
    fgets(url, MAX_URL_LEN+1, stdin);
    url[strcspn(url, "\r\n")] = '\0'; // Remove trailing newline
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}