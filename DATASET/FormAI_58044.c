//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitizeURL(char *url) {
    char *pattern_http = "http://";
    char *pattern_https = "https://";
    
    // Check if url starts with http:// or https://
    if (strncmp(url, pattern_http, strlen(pattern_http)) != 0 && strncmp(url, pattern_https, strlen(pattern_https)) != 0) {
        printf("URL should start with http:// or https://.\n");
        exit(1);
    }
    
    // Check if url has valid characters
    for (int i = strlen(pattern_http); i < strlen(url); i++) {
        if (!((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9') || url[i] == '.' || url[i] == '/' || url[i] == '?' || url[i] == '=')) {
            printf("Invalid character %c in URL.\n", url[i]);
            exit(1);
        }
    }
    
    // Check if url has query parameters and remove them
    char *p = strchr(url, '?');
    if (p != NULL) {
        int index = p - url;
        url[index] = '\0';
    }
}

int main() {
    char url[100];
    printf("Enter URL to Sanitize: ");
    scanf("%s", url);
    sanitizeURL(url);
    printf("Sanitized URL: %s\n", url);
    return 0; 
}