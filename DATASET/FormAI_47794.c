//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitize(char *url) {
    // Remove whitespace characters from the beginning and end of the URL
    url[strcspn(url, "\r\n")] = '\0';
    while (isspace(*url)) {
        url++;
    }
    char *end = url + strlen(url) - 1;
    while (end > url && isspace(*end)) {
        end--;
    }
    *(end + 1) = '\0';

    // Check for scheme, and add http:// if there is none
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        char *new_url = malloc(strlen(url) + 8);
        strcpy(new_url, "http://");
        strcat(new_url, url);
        url = new_url;
    }

    // Remove any path or query string from the URL
    char *path = strstr(url, "/");
    if (path != NULL) {
        *path = '\0';
    }

    // Remove any port number from the URL
    char *port = strstr(url, ":");
    if (port != NULL) {
        *port = '\0';
    }
}

int main(void) {
    char url[256];
    printf("Enter a URL: ");
    fgets(url, sizeof(url), stdin);
    sanitize(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}