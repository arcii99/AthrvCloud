//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 256

// sanitize URL by removing any suspicious or harmful characters
// and replacing them with hyphens
void sanitize_url(char *url) {
    int i;
    int len = strlen(url);
    for (i = 0; i < len; i++) {
        if ((url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= 'a' && url[i] <= 'z') ||
            (url[i] >= '0' && url[i] <= '9') || url[i] == '/' || url[i] == '.' || url[i] == '-') {
            // valid character
        } else {
            // suspicious or harmful character, replace with hyphen
            url[i] = '-';
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./url-sanitizer <url>\n");
        return 1;
    }

    char url[MAX_URL_LENGTH];
    strncpy(url, argv[1], MAX_URL_LENGTH);

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}