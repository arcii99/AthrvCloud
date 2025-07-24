//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize the URL
void sanitize_url(char* url) {
    // Convert the URL to lowercase
    for (int i = 0; url[i]; i++) {
      url[i] = tolower(url[i]);
    }
    
    // Check for dangerous characters
    char* dangerous_chars = "<>&\"";
    char* safe_chars = "  ";
    char* p = NULL;
    while ((p = strpbrk(url, dangerous_chars)) != NULL) {
        int i = p - url;
        url[i] = safe_chars[0];
        memmove(&url[i+1], &url[i+2], strlen(&url[i+2]) + 1);
    }

    // Check for protocol, and add http:// if missing
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        char* new_url = calloc(MAX_URL_LENGTH, sizeof(char));
        if (new_url == NULL) {
            perror("Error: failed to allocate memory");
            exit(EXIT_FAILURE);
        }
        strcat(new_url, "http://");
        strcat(new_url, url);
        strcpy(url, new_url);
        free(new_url);
    }
}

// Main function to prompt the user for input, sanitize it, and display the result
int main() {
    char url[MAX_URL_LENGTH];
    printf("Please enter a URL to sanitize:\n");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = 0; // Remove new line character
    
    // Sanitize the URL
    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}