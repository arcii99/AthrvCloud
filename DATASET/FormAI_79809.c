//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to sanitize the URL
char *sanitize_url(char *url) {
    int i, j = 0, len = strlen(url);
    char *sanitized_url = malloc(len + 1);

    for (i = 0; i < len; i++) {
        // check if the character is alphanumeric or a valid URL character
        if (isalnum(url[i]) || url[i] == '.' || url[i] == '-' || url[i] == '_' || url[i] == '/') {
            sanitized_url[j++] = url[i];
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {
    char url[100];
    printf("Enter the URL to sanitize:");
    scanf("%s", url);

    // sanitize the URL
    char *sanitized_url = sanitize_url(url);

    printf("Sanitized URL: %s\n", sanitized_url);

    // free the memory allocated for sanitized_url
    free(sanitized_url);

    return 0;
}