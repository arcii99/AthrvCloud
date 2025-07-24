//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 255

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = 0;
    
    // Check if URL starts with "http://" or "https://"
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        printf("Invalid URL. Please enter a URL that starts with http:// or https://\n");
        return 1;
    }
    
    // Check if URL contains whitespace
    if (strchr(url, ' ') != NULL) {
        printf("Invalid URL. Please enter a URL without any whitespace\n");
        return 1;
    }
    
    // Check if URL contains only alphanumeric characters and certain special characters
    int i;
    for (i = 0; i < strlen(url); i++) {
        char c = url[i];
        if (!isalnum(c) && c != '.' && c != ':' && c != '/' && c != '?' && c != '&' && c != '=') {
            printf("Invalid URL. Please enter a URL containing only alphanumeric characters and certain special characters\n");
            return 1;
        }
    }
    
    // Check if URL is too long
    if (strlen(url) > MAX_URL_LENGTH) {
        printf("Invalid URL. Please enter a URL shorter than %d characters\n", MAX_URL_LENGTH);
        return 1;
    }
    
    // Sanitize URL by removing query string and fragment
    char *query = strchr(url, '?');
    if (query != NULL) {
        *query = '\0';
    }
    char *fragment = strchr(url, '#');
    if (fragment != NULL) {
        *fragment = '\0';
    }
    
    printf("Sanitized URL: %s\n", url);
    return 0;
}