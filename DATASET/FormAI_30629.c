//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1024

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL (e.g. https://www.example.com): ");
    fgets(url, MAX_URL_LENGTH, stdin);
    
    // Remove newline char from fgets input
    url[strcspn(url, "\n")] = 0;
    
    // Check if URL already starts with http:// or https://
    if (strncmp(url, "http://", 7) && strncmp(url, "https://", 8)) {
        printf("Invalid URL. URL must start with 'http://' or 'https://'\n");
        return 1;
    }
    
    // Check for invalid characters in URL
    for (int i = 0; url[i] != '\0'; i++) {
        if (!isalnum(url[i]) && url[i] != ':' && url[i] != '.' && url[i] != '-' && url[i] != '/') {
            printf("Invalid character in URL: '%c'\n", url[i]);
            return 1;
        }
        
        // Remove any extra slashes (e.g. http:///example.com)
        if (url[i] == '/' && url[i-1] == '/') {
            memmove(&url[i-1], &url[i], strlen(&url[i]) + 1);
            i--;
        }
    }
    
    printf("Sanitized URL: %s\n", url);
    return 0;
}