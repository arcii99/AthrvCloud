//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: creative
#include <stdio.h>
#include <string.h>
#define MAX_URL_LENGTH 100

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Remove any existing protocol
    memmove(url, url+strlen("http://"), strlen(url)-strlen("http://"));

    // Remove any trailing slash
    if (url[strlen(url)-1] == '/') {
        url[strlen(url)-1] = '\0';
    }

    // Remove query string
    char* questionMark = strchr(url, '?');
    if(questionMark != NULL) {
        *questionMark = '\0';
    }

    // Remove fragment identifier
    char* hashMark = strchr(url, '#');
    if(hashMark != NULL) {
        *hashMark = '\0';
    }

    printf("Sanitized URL: %s", url);

    return 0;
}