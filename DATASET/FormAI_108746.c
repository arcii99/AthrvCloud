//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char url[100];
    printf("Enter URL to sanitize:\n");
    scanf("%s", url);

    // Convert URL to lowercase
    for (int i = 0; i < strlen(url); i++) {
        url[i] = tolower(url[i]);
    }

    // Remove http:// and https:// prefixes
    const char* prefixes[] = {"http://", "https://"};
    for (int i = 0; i < 2; i++) {
        size_t prefix_len = strlen(prefixes[i]);
        if (strncmp(url, prefixes[i], prefix_len) == 0) {
            memmove(url, url + prefix_len, strlen(url) - prefix_len + 1);
            break;
        }
    }

    // Remove trailing slashes
    size_t url_len = strlen(url);
    if (url[url_len - 1] == '/') {
        url[url_len - 1] = '\0';
    }

    // Remove query parameters
    char* qmark_pos = strchr(url, '?');
    if (qmark_pos != NULL) {
        *qmark_pos = '\0';
    }

    // Add http:// prefix if missing
    if (strncmp(url, "http", 4) != 0) {
        memmove(url + 4, url, strlen(url) + 1);
        strncpy(url, "http", 4);
    }

    printf("Sanitized URL: %s\n", url);
    return 0;
}