//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: dynamic
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
  
// Function to sanitize a URL and return a new one with http:// prefix if not present
char* sanitize_url(char* url) 
{ 
    // Check URL for "http://" - if not present, add it
    const char prefix[] = "http://";
    if (memcmp(url, prefix, strlen(prefix)) != 0) {
        char* sanitized_url = malloc(strlen(url) + strlen(prefix) + 1);
        strcpy(sanitized_url, prefix);
        strcat(sanitized_url, url);
        return sanitized_url;
    }
    
    return url;
} 

int main() 
{ 
    // Test cases
    char url1[] = "www.google.com";          // Should become "http://www.google.com"
    char url2[] = "http://www.yahoo.com";    // Should stay the same

    char* sanitized1 = sanitize_url(url1);
    char* sanitized2 = sanitize_url(url2);

    printf("Original URL: %s\nSanitized URL 1: %s\nSanitized URL 2: %s\n", url1, sanitized1, sanitized2);

    // Free dynamically allocated memory
    free(sanitized1);
    return 0; 
}