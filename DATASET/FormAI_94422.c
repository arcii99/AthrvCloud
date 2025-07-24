//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* url_sanitize(char* url) {
    char* sanitized_url = malloc(strlen(url) + 1); // allocate memory for the new sanitized string
    int sanitized_url_len = 0; // length of the new sanitized string
    
    for(int i = 0; url[i] != '\0'; i++) {
        if(isalpha(url[i]) || isdigit(url[i]) || url[i] == '-' || url[i] == '_' || url[i] == '.' || url[i] == '/') {
            sanitized_url[sanitized_url_len] = url[i]; // add allowed characters to the sanitized string
            sanitized_url_len++;
        }
        else if(url[i] == ' ') {
            sanitized_url[sanitized_url_len] = '+'; // replace spaces with '+'
            sanitized_url_len++;
        }
    }
    
    sanitized_url[sanitized_url_len] = '\0'; // add null terminator to the end of new sanitized string
    
    return sanitized_url;
}

int main(void) {
    char url[] = "https://www.example.com/my_page.html?q=test&name=bob smith";
    char* sanitized_url = url_sanitize(url);
    
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);
    
    free(sanitized_url); // free allocated memory
    
    return 0;
}