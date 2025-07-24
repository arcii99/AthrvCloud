//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: retro
#include <stdio.h>
#include <string.h>
#define MAX_URL_LENGTH 100

void sanitize(char* url);

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);
    sanitize(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}

void sanitize(char* url) {
    // Remove protocol
    char* protocol = "http://";
    if (strncmp(url, protocol, strlen(protocol)) == 0) {
        char* temp = url + strlen(protocol);
        memmove(url, temp, strlen(temp) + 1);
    }
    
    // Remove trailing slash
    if (url[strlen(url) - 1] == '/') {
        url[strlen(url) - 1] = '\0';
    }
    
    // Remove query params
    char* query_start = strchr(url, '?');
    if (query_start != NULL) {
        *query_start = '\0';
    }
    
    // Remove fragment
    char* fragment_start = strchr(url, '#');
    if (fragment_start != NULL) {
        *fragment_start = '\0';
    }
}