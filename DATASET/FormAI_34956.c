//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main() {
    char url[1000], *ptr;
    int i, j;

    printf("Enter a URL: ");
    gets(url);

    // Remove query parameters
    ptr = strchr(url, '?');
    if (ptr != NULL) {
        *ptr = '\0';
    }

    // Remove fragments
    ptr = strchr(url, '#');
    if (ptr != NULL) {
        *ptr = '\0';
    }

    printf("Sanitized URL: %s\n", url);

    return 0;
}