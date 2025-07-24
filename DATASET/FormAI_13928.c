//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitize_url(char *url);

int main() {
    char url[256];
    printf("Enter a URL: ");
    fgets(url, sizeof(url), stdin);
    sanitize_url(url);
    printf("Sanitized URL: %s", url);
    return 0;
}

void sanitize_url(char *url) {
    int i, j, len;
    char *tmp;
  
    // Remove leading and trailing spaces
    len = strlen(url);
    while (len > 0 && url[len - 1] == '\n') {
        url[--len] = '\0';
    }
    while (*url == ' ') {
        url++;
    }
  
    // Check for "javascript:" protocol
    if (strncmp(url, "javascript:", 11) == 0) {
        strcpy(url, "about:blank");
    }
  
    // Check for invalid protocol
    tmp = strstr(url, "://");
    if (tmp != NULL) {
        len = tmp - url + 3;
        if (strncmp(url, "http://", len) != 0 && strncmp(url, "https://", len) != 0) {
            memmove(url + 7, url, strlen(url) + 1);
            strncpy(url, "http://", 7);
        }
        url[len - 1] = '/';
    } else {
        memmove(url + 7, url, strlen(url) + 1);
        strncpy(url, "http://", 7);
        url[strlen(url)] = '/';
    }

    // Remove any duplicate slashes
    len = strlen(url);
    for (i = 0, j = 0; i < len; i++) {
        if (url[i] == '/' && (i == 0 || url[i - 1] != '/')) {
            url[j++] = url[i];
        }
    }
    url[j] = '\0';
}