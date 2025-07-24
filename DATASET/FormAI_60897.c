//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sanitize(char* url) {
    // Remove any query string or fragment identifiers from the URL
    char* question_mark_ptr = strchr(url, '?');
    if (question_mark_ptr != NULL) {
        *question_mark_ptr = '\0';
    }

    char* hashmark_ptr = strchr(url, '#');
    if (hashmark_ptr != NULL) {
        *hashmark_ptr = '\0';
    }

    // Remove any trailing slashes, except in the case of the root URL "/"
    size_t len = strlen(url);
    if (len > 1 && url[len-1] == '/') {
        url[len-1] = '\0';
    }

    // Convert all characters to lowercase
    for (int i = 0; i < len; i++) {
        url[i] = tolower(url[i]);
    }
}

int main() {
    char url_buffer[256];

    printf("Enter a URL to sanitize: ");
    fgets(url_buffer, sizeof(url_buffer), stdin);

    sanitize(url_buffer);

    printf("Sanitized URL: %s\n", url_buffer);

    return 0;
}