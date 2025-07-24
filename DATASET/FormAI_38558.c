//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitize_url(char* url) {
    // Replace all non-alphanumeric characters with underscores
    for (int i = 0; i < strlen(url); i++) {
        if (!isalnum(url[i])) {
            url[i] = '_';
        }
    }

    // Convert entire URL to lowercase
    for (int i = 0; i < strlen(url); i++) {
        url[i] = tolower(url[i]);
    }
}

int main() {
    char url[100];

    printf("Enter a URL to sanitize:\n");
    scanf("%s", url);

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}