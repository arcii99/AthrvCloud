//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1000 // maximum length of a URL

// function to sanitize a URL and return it as a new string
char* sanitize_url(char* url) {
    char* sanitized_url = (char*) malloc(MAX_URL_LENGTH * sizeof(char)); // allocate memory for sanitized URL
    int sanitized_index = 0; // index for the sanitized URL
    int url_length = strlen(url); // get length of original URL
    
    for (int i = 0; i < url_length; i++) {
        char c = url[i];
        
        if (isalpha(c)) { // convert all alphabetic characters to lowercase
            sanitized_url[sanitized_index++] = tolower(c);
        } else if (isdigit(c) || c == '-' || c == '_' || c == '.') { // allow digits, hyphens, underscores, and periods
            sanitized_url[sanitized_index++] = c;
        }
    }
    
    sanitized_url[sanitized_index] = '\0'; // terminate sanitized URL string
    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH]; // original URL string
    printf("Enter a URL for sanitization: ");
    scanf("%s", url);
    
    char* sanitized_url = sanitize_url(url); // get sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);
    
    free(sanitized_url); // free memory allocated for sanitized URL
    
    return 0; // exit program
}