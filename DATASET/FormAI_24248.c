//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void sanitize_url(char *url);

int main(void) {
    char url[MAX_LENGTH];

    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_LENGTH, stdin);

    sanitize_url(url);

    printf("Sanitized URL: %s", url);

    return 0;
}

void sanitize_url(char *url) {
    char sanitized[MAX_LENGTH];
    int i, j;
    char c;

    for (i = 0, j = 0; url[i] != '\0'; i++) {
        c = url[i];

        if (isalnum(c) || c == '.' || c == '/' || c == ':') {
            sanitized[j++] = c;
        }
    }

    sanitized[j] = '\0';

    if (strcmp(url, sanitized) != 0) {
        printf("Warning: URL contains invalid characters. Sanitizing...\n");
        strcpy(url, sanitized);
    }
}