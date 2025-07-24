//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sanitizeUrl(char *url) {
    // Convert the URL to lower case
    for (int i = 0; url[i]; i++)
        url[i] = tolower(url[i]);

    // Remove the protocol from the URL
    char *ptr = strstr(url, "://");
    if (ptr != NULL)
        strcpy(url, ptr + 3);

    // Remove the www subdomain from the URL
    if (strncmp(url, "www.", 4) == 0)
        strcpy(url, url + 4);

    // Replace all '.' characters with '_'
    for (int i = 0; url[i]; i++)
        if (url[i] == '.')
            url[i] = '_';
}

int main() {
    char url[100];

    printf("Enter a URL to sanitize:\n");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = 0; // Remove the newline character from the input

    sanitizeUrl(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}