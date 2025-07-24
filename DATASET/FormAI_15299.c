//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *sanitizeURL(char *url) {
    char *sanitizedUrl = malloc(strlen(url) + 1);
    memset(sanitizedUrl, 0, strlen(url) + 1);  // Initialize the new string with zero

    int i = 0;
    while (*url) {
        if (isalnum(*url) || *url == '.' || *url == '/' || *url == '-') {
            sanitizedUrl[i++] = *url++;
        } else {
            url++;
        }
    }

    return sanitizedUrl;
}

int main() {
    char url[] = "http://www.example.com/?id=1234&code=<script>alert('hacked');</script>";
    char *sanitizedUrl = sanitizeURL(url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitizedUrl);

    free(sanitizedUrl);

    return 0;
}