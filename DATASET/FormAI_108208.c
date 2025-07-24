//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int MAX_URL_LENGTH = 200;

// function to check if a given character is a valid URL character
int isValidURLChar(char c) {
    if(isalpha(c) || isdigit(c) || c == '.' || c == ':' || c == '/' || c == '-' || c == '_') {
        return 1;
    }
    return 0;
}

// function to remove any invalid characters from a given URL string
char* sanitizeURL(char* url) {
    int len = strlen(url);
    char* sanitized_url = (char*)malloc(MAX_URL_LENGTH);

    // loop through the characters in the URL and add only valid characters to the sanitized URL string
    int k = 0;
    for(int i=0; i<len; i++) {
        if(isValidURLChar(url[i])) {
            sanitized_url[k++] = url[i];
        }
    }
    sanitized_url[k] = '\0';

    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // remove new line character from the end of the URL string
    url[strcspn(url, "\r\n")] = 0;

    char* sanitized_url = sanitizeURL(url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}