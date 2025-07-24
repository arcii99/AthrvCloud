//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 200

char* sanitize(char *url) {
    char *sanitized_url = malloc(MAX_URL_LENGTH * sizeof(char));
    int i, j=0;

    for(i=0; url[i]!='\0'; i++) { 
        // check for invalid characters and remove any non-alphanumeric characters except for colon and forward slash
        if(isalnum(url[i]) || url[i] == ':' || url[i] == '/') { 
            sanitized_url[j++] = url[i]; 
        }
    }

    sanitized_url[j] = '\0'; // add null terminator at the end of the sanitized string
    return sanitized_url;
}

int main() {
    char *url;
    char *sanitized_url;

    printf("Enter a URL to be sanitized: ");
    scanf("%s", url);

    sanitized_url = sanitize(url);

    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}