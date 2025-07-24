//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    // Initialize variables
    char url[256];
    char sanitized_url[256];
    int i, j, len;

    // Get user input
    printf("Enter URL:");
    fgets(url, sizeof(url), stdin);

    // Remove leading and trailing whitespaces
    i = 0;
    while (isspace((unsigned char)url[i])) {
        i++;
    }
    j = strlen(url) - 1;
    while (j >= 0 && isspace((unsigned char)url[j])) {
        j--;
    }
    url[j+1] = '\0';
    strcpy(sanitized_url, &url[i]);

    // Check for "http://" or "https://" and remove if it exists
    if (strstr(sanitized_url, "http://") != NULL) {
        memmove(&sanitized_url[0], &sanitized_url[7], strlen(&sanitized_url[7]) + 1);
    } else if (strstr(sanitized_url, "https://") != NULL) {
        memmove(&sanitized_url[0], &sanitized_url[8], strlen(&sanitized_url[8]) + 1);
    }

    // Replace spaces with %20
    len = strlen(sanitized_url);
    for (i = 0; i < len; i++) {
        if (sanitized_url[i] == ' ') {
            memmove(&sanitized_url[i+3], &sanitized_url[i+1], len - i);
            memmove(&sanitized_url[i], "%20", 3);
            len += 2;
        }
    }

    // Check for invalid characters and replace with underscore
    len = strlen(sanitized_url);
    for (i = 0; i < len; i++) {
        if (!(isalnum(sanitized_url[i]) || sanitized_url[i] == '-' || sanitized_url[i] == '_' || sanitized_url[i] == '.' || sanitized_url[i] == '/')) {
            sanitized_url[i] = '_';
        }
    }

    // Add "http://" to the beginning if it is not present
    if (strncmp(sanitized_url, "http://", 7) != 0 && strncmp(sanitized_url, "https://", 8) != 0) {
        memmove(&sanitized_url[7], &sanitized_url[0], strlen(sanitized_url) + 1);
        memmove(&sanitized_url[0], "http://", 7);
    }

    // Output sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}