//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *sanitize(char *url) {
    char *sanitized = malloc(strlen(url) + 1);
    char *s = sanitized;
    while (*url) {
        if (isalnum(*url) || *url == '.' || *url == '_' || *url == '/') {
            *s++ = *url++;
        } else if (*url == '?') {
            *s++ = *url++;
            // remove query string
            while (*url && *url != '#') {
                url++;
            }
        } else if (*url == '&') {
            *s++ = *url++;
            // remove query parameter
            while (*url && *url != '=') {
                url++;
            }
        } else if (*url == '#') {
            break; // ignore fragment identifier
        } else {
            url++; // skip invalid character
        }
    }
    *s = '\0'; // add null terminator
    return sanitized;
}

int main(void) {
    char url[] = "https://www.example.com/?param1=value1&param2=value2#fragment";
    char *sanitized = sanitize(url);
    printf("%s\n", sanitized);
    free(sanitized);
    return 0;
}