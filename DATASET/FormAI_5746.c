//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 1000

int is_valid_character(char c) {
    // Only allow alphanumeric characters, hyphens, underscores and periods
    if (c >= '0' && c <= '9')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c == '-' || c == '_' || c == '.')
        return 1;
    return 0;
}

void sanitize_url(char *url) {
    char *sanitized_url = (char *) malloc(MAX_URL_LENGTH * sizeof(char));
    int i = 0, j = 0;

    while (url[i] != '\0') {
        if (is_valid_character(url[i])) {
            sanitized_url[j] = url[i];
            j++;
        }
        i++;
    }
    sanitized_url[j] = '\0';

    strcpy(url, sanitized_url);
    free(sanitized_url);
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize:\n");
    fgets(url, MAX_URL_LENGTH, stdin);

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);
    return 0;
}