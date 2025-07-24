//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sanitize URL inputs
char* sanitizeURL(char* url) {
    int len = strlen(url);
    char* sanitizedURL = malloc(sizeof(char) * (len + 1));  // Allocate memory for sanitized URL
    
    int j = 0;  // Counter for new URL
    for (int i = 0; i < len; i++) {
        if (url[i] == ' ') {  // If space, replace with '%20'
            sanitizedURL[j++] = '%';
            sanitizedURL[j++] = '2';
            sanitizedURL[j++] = '0';
        } else if (url[i] == '<' || url[i] == '>') {  // If '<' or '>', replace with '%3C' or '%3E'
            sanitizedURL[j++] = '%';
            sanitizedURL[j++] = (url[i] == '<') ? '3' : 'E';
            sanitizedURL[j++] = (url[i] == '<') ? 'C' : '8';
        } else {  // Otherwise, keep character as is
            sanitizedURL[j++] = url[i];
        }
    }
    
    sanitizedURL[j] = '\0';  // Append null terminator
    return sanitizedURL;
}

int main() {
    char url[100];
    printf("Enter a URL to sanitize: ");
    fgets(url, 100, stdin);
    
    char* sanitized = sanitizeURL(url);
    printf("Sanitized URL: %s\n", sanitized);
    
    free(sanitized);  // Free memory allocated for sanitized URL
    
    return 0;
}