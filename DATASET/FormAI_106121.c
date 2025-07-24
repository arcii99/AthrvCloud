//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 256

char* sanitize_url(char url[]);

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter the URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    
    char *sanitized_url = sanitize_url(url);
    
    printf("Sanitized URL: %s\n", sanitized_url);
    
    free(sanitized_url);
    return 0;
}

char* sanitize_url(char url[]) {
    int i, j;
    char *sanitized_url = malloc(sizeof(char) * MAX_URL_LENGTH);
    for(i = 0, j = 0; url[i] != '\0'; i++) {
        if(isalnum(url[i])) {
            sanitized_url[j] = url[i];
            j++;
        } else if(url[i] == ':' && url[i+1] == '/' && url[i+2] == '/') {
            sanitized_url[j] = url[i];
            sanitized_url[j+1] = url[i+1];
            sanitized_url[j+2] = url[i+2];
            j += 3;
            i += 2;
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}