//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to sanitize URL
char* sanitize_url(char* url) {
    // remove whitespace from beginning and end
    char* sanitized_url = url;
    int i, j;
    for (i = 0; isspace(sanitized_url[i]); i++);
    for (j = strlen(sanitized_url) - 1; j >= i && isspace(sanitized_url[j]); j--);
    sanitized_url[j + 1] = '\0';
    sanitized_url = &sanitized_url[i];
    
    // check if there is a protocol specified
    char* protocol = "http://";
    char* protocol2 = "https://";
    if (memcmp(sanitized_url, protocol, strlen(protocol)) != 0 && memcmp(sanitized_url, protocol2, strlen(protocol2)) != 0) {
        // no protocol found, assume http
        char* new_url = (char*)malloc(strlen(sanitized_url) + strlen(protocol) + 1);
        strcpy(new_url, protocol);
        strcat(new_url, sanitized_url);
        sanitized_url = new_url;
    }
    
    // remove any trailing slashes
    if (sanitized_url[strlen(sanitized_url) - 1] == '/') {
        sanitized_url[strlen(sanitized_url) - 1] = '\0';
    }
    
    // remove any query parameters from the url
    char* query = strchr(sanitized_url, '?');
    if (query != NULL) {
        *query = '\0';
    }
    
    return sanitized_url;
}

int main() {
    char* url = "   https://www.example.com/page1.php?id=1234&name=John+Doe   ";
    char* sanitized_url = sanitize_url(url);
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}