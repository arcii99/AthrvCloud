//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitize(char *url) {
    int j, k;

    // Remove leading and trailing spaces
    while (*url == ' ') url++;
    j = strlen(url) - 1;
    while (j > 0 && url[j] == ' ') {
        url[j] = '\0';
        j--;
    }

    // Remove line breaks and tabs
    for (k = 0, j = 0; url[j] != '\0'; ++j) {
        if (url[j] != '\n' && url[j] != '\r' && url[j] != '\t') {
            url[k++] = url[j];
        }
    }
    url[k] = '\0';

    // Remove 'javascript' and 'data' schemes
    if (strncmp(url, "javascript:", 11) == 0 || strncmp(url, "data:", 5) == 0) {
        url[0] = '\0';
        return;
    }

    // Remove scheme if present
    char *scheme_pointer = strstr(url, "://");
    if (scheme_pointer != NULL) {
        scheme_pointer += 3;
        memmove(url, scheme_pointer, strlen(scheme_pointer) + 1);
    }

    // Remove trailing slash
    j = strlen(url) - 1;
    if (j > 0 && url[j] == '/') {
        url[j] = '\0';
    }

    // Replace relative paths with absolute paths
    char *slash_pointer = strstr(url, "/");
    if (slash_pointer != NULL && slash_pointer - url <= 1) {
        memmove(url, slash_pointer, strlen(slash_pointer) + 1);
    }
}

int main() {
    char url[] = "     https://www.example.com/   \t\n";
    printf("Before: %s\n", url);
    sanitize(url);
    printf("After:  %s\n", url);

    char url2[] = "JavaScript:alert('Hello, world!')";
    printf("Before: %s\n", url2);
    sanitize(url2);
    printf("After:  %s\n", url2);
}