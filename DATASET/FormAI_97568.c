//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 100

void sanitizeUrl(char* url);

int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    sanitizeUrl(url);

    printf("Cleaned URL: %s\n", url);

    return 0;
}

void sanitizeUrl(char* url) {
    int len = strlen(url);

    // Check for "http://" or "https://"
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        // If not present, add "http://"
        char* newUrl = malloc(len + 8);
        if (newUrl == NULL) {
            printf("Error: Out of memory!\n");
            exit(1);
        }
        strcpy(newUrl, "http://");
        strcat(newUrl, url);
        strcpy(url, newUrl);
        free(newUrl);
        len += 7;
    }

    // Remove extra slashes
    int shift = 0;
    for (int i = 7; i < len; i++) {
        if (url[i] == '/' && url[i-1] == '/') {
            shift++;
        } else {
            url[i-shift] = url[i];
        }
    }
    len -= shift;

    // Remove trailing slash
    if (url[len-1] == '/') {
        url[len-1] = '\0';
        len--;
    }

    // Remove any query parameters
    char* queryStart = strchr(url, '?');
    if (queryStart != NULL) {
        *queryStart = '\0';
        len = queryStart - url;
    }
}