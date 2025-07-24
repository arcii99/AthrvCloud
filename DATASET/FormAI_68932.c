//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 200

int main()
{
    // Input URL
    char url[MAX_URL_LENGTH];
    printf("Enter URL: ");
    scanf("%s", url);
    
    // Determine if URL contains http:// or https://
    bool has_http = strstr(url, "http://") != NULL;
    bool has_https = strstr(url, "https://") != NULL;
    
    // Remove http:// or https:// from URL
    char* sanitized_url = url;
    if (has_http) {
        sanitized_url += strlen("http://");
    } else if (has_https) {
        sanitized_url += strlen("https://");
    }
    
    // Remove trailing / from URL
    if (sanitized_url[strlen(sanitized_url) - 1] == '/') {
        sanitized_url[strlen(sanitized_url) - 1] = '\0';
    }
    
    // Print sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);
    
    return 0;
}