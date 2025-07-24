//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to sanitize URL by removing dangerous characters
char *sanitizeURL(char *url) {
    char sanitized[1000];
    int j = 0;
    for (int i = 0; i < strlen(url); i++) {
        char c = url[i];
        // check if character is alphanumeric or a safe symbol
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '-' || c == '_' || c == '.' || 
            c == '/' || c == ':' || c == '?') {
            sanitized[j++] = c;
        }
        // ignore spaces and other unsafe symbols
        else if (c == ' ' || c == '\n' || c == '\r' || 
                 c == '\t' || c == '<' || c == '>') {
            continue;
        }
        // convert all other characters to hex format
        else {
            char hex[10];
            sprintf(hex, "%%%02X", c);
            // append the hex code to the sanitized URL
            for (int k = 0; k < strlen(hex); k++, j++) {
                sanitized[j] = hex[k];
            }
        }
    }
    sanitized[j] = '\0';
    url = sanitized;
    return url;
}

int main() {
    char url[1000];
    printf("Enter URL to sanitize: ");
    fgets(url, sizeof(url), stdin);
    // remove newline character
    url[strcspn(url, "\n")] = 0;
    char *sanitizedURL = sanitizeURL(url);
    printf("Sanitized URL: %s\n", sanitizedURL);
    return 0;
}