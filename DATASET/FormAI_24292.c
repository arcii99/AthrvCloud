//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: mathematical
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define URL_MAX 1024

// function to check if a character is a valid url character
int is_valid_char(char c) {
    return isalpha(c) || isdigit(c) || c == '.' || c == '/';
}

// function to sanitize a url
char* sanitize_url(char* url) {
    char* sanitized_url = (char*)malloc(URL_MAX * sizeof(char));
    int i = 0, j = 0;

    while(url[i] != '\0') {
        if(is_valid_char(url[i])) {
            sanitized_url[j++] = url[i];
        }
        i++;
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {
    char url[URL_MAX];
    printf("Enter a URL: ");
    fgets(url, URL_MAX, stdin);

    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    
    free(sanitized_url);
    return 0;
}