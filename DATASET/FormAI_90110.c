//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *sanitize_url(char *url) {
    char *new_url = malloc(strlen(url) + 1);
    int i = 0;
    while (*url) {
        if (*url == ' ') {
            new_url[i++] = '+';
        } else if (isalnum(*url) || *url == '-' || *url == '_' || *url == '.' || *url == '/') {
            new_url[i++] = *url;
        } else if (*url == '%') {
            char hex[3];
            hex[0] = *(++url);
            hex[1] = *(++url);
            hex[2] = '\0';
            new_url[i++] = (char) strtol(hex, NULL, 16);
        }
        url++;
    }
    new_url[i] = '\0';
    return new_url;
}

int main() {
    char url[] = "https://www.google.com/search?q=c url sanitizer&oq=c+url&aqs=chrome.1.69i57j0l4j46j69i60.6142j1j7&sourceid=chrome&ie=UTF-8";
    char *sanitized_url = sanitize_url(url);
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}