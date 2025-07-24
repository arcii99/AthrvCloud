//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_URL_SIZE 200

// function to remove spaces from a string
void remove_spaces(char* str) {
    char* s = str;
    while (*s != '\0') {
        if (*s == ' ') {
            memmove(s, s + 1, strlen(s + 1) + 1);
        } else {
            s++;
        }
    }
}

// function to remove trailing slash from a URL
void remove_trailing_slash(char* url) {
    int len = strlen(url);
    if (len > 1 && url[len - 1] == '/') {
        url[len - 1] = '\0';
    } 
}

// function to convert a string to lowercase
void to_lower(char* str) {
    char* s = str;
    while (*s != '\0') {
        *s = tolower(*s);
        s++;
    }
}

// function to sanitize a URL
void sanitize_url(char* url) {
    // remove spaces
    remove_spaces(url);
    
    // remove trailing slash
    remove_trailing_slash(url);
    
    // convert to lowercase
    to_lower(url);
}

int main() {
    char url[MAX_URL_SIZE];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_SIZE, stdin);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}