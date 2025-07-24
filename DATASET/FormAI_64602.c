//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: visionary
#include <stdio.h>
#include <string.h>

void sanitizeURL(char* url) {
    // remove whitespace
    char* p1 = url;
    char* p2 = url;
    while (*p1) {
        if (*p1 != ' ') {
            *p2++ = *p1;
        }
        p1++;
    }
    *p2 = '\0';
    // check for http/https
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        // add http://
        char temp[100];
        strcpy(temp, "http://");
        strcat(temp, url);
        strcpy(url, temp);
    }
    // remove trailing slash
    if (url[strlen(url)-1] == '/') {
        url[strlen(url)-1] = '\0';
    }
}

int main() {
    char url[100];
    printf("Enter a URL: ");
    fgets(url, sizeof(url), stdin);
    sanitizeURL(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}