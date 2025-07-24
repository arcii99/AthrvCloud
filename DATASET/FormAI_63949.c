//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <string.h>

void sanitize(char* url) {
    // Remove parameters
    char* param_ptr = strchr(url, '?');
    if (param_ptr != NULL) {
        *param_ptr = '\0';
    }

    // Remove trailing /
    size_t len = strlen(url);
    if (len > 0 && url[len - 1] == '/') {
        url[len - 1] = '\0';
    }

    // Remove any non-alphanumeric characters
    size_t i = 0;
    while (url[i] != '\0') {
        if (!isalnum(url[i])) {
            memmove(&url[i], &url[i + 1], strlen(&url[i + 1]) + 1);
        } else {
            i++;
        }
    }

    // Convert to lowercase
    for (i = 0; url[i]; i++){
        url[i] = tolower(url[i]);
    }
}

int main() {
    char url[100];
    printf("Enter a URL: ");
    scanf("%s", url);

    sanitize(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}