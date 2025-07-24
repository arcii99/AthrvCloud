//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sanitize a URL
char *url_sanitize(char *url) {
    // Remove the protocol from the URL (http:// or https://)
    char *protocol = strstr(url, "://");
    if (protocol != NULL) {
        url = protocol + 3;
    }
    
    // Remove any trailing slashes
    char *path = strstr(url, "/");
    if (path != NULL) {
        *path = '\0';
    }
    
    // Remove any query parameters or fragments
    char *query = strstr(url, "?");
    if (query != NULL) {
        *query = '\0';
    }
    
    char *fragment = strstr(url, "#");
    if (fragment != NULL) {
        *fragment = '\0';
    }
    
    // Return the sanitized URL
    return url;
}

// Main function
int main() {
    // Test the sanitizer with some example URLs
    char *url1 = "https://www.example.com/path/to/page?query=string#fragment";
    char *url2 = "http://www.example.com/foo/bar//";
    
    printf("Original URL 1: %s\n", url1);
    printf("Sanitized URL 1: %s\n", url_sanitize(url1));
    
    printf("Original URL 2: %s\n", url2);
    printf("Sanitized URL 2: %s\n", url_sanitize(url2));
    
    return 0;
}