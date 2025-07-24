//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX_URL_LENGTH 1000

bool is_valid_url_char(char c) {
    /* This function checks if the character is valid according to RFC 3986 */
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') ||
        (c == '-') || (c == '.') || (c == '_') || (c == '~') || (c == ':') || 
        (c == '/') || (c == '?') || (c == '#') || (c == '[') || (c == ']') || 
        (c == '@') || (c == '!') || (c == '$') || (c == '&') || (c == '\'') || 
        (c == '(') || (c == ')') || (c == '*') || (c == '+') || (c == ',') || 
        (c == ';') || (c == '=') || (c == '%')) {
        return true;
    }
    return false;
}

void sanitize_url(char* url) {
    /* This function removes any invalid characters from the URL */
    int len = strlen(url);
    char sanitized_url[MAX_URL_LENGTH];
    int j = 0;
    for(int i = 0; i < len; i++) {
        if(is_valid_url_char(url[i])) {
            sanitized_url[j++] = url[i];
        }
    }
    sanitized_url[j] = '\0';
    strcpy(url, sanitized_url);
}

bool validate_url(char* url) {
    /* This function validates the URL according to RFC 3986 */
    int len = strlen(url);
    int num_slashes = 0;
    int num_colons = 0;
    for(int i = 0; i < len; i++) {
        if(!is_valid_url_char(url[i])) {
            return false;
        }
        if(url[i] == '/' && num_slashes == 2) {
            return false;
        }
        if(url[i] == '/') {
            num_slashes++;
        }
        if(url[i] == ':' && num_colons == 1) {
            return false;
        }
        if(url[i] == ':') {
            num_colons++;
        }
    }
    if(num_slashes != 3 || num_colons < 1) {
        return false;
    }
    return true;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = '\0';
    
    sanitize_url(url);
    
    if(validate_url(url)) {
        printf("The sanitized URL is valid: %s\n", url);
    } else {
        printf("The sanitized URL is invalid!\n");
    }
    
    return 0;
}