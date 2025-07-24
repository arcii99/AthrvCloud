//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//function to remove unwanted characters
char *sanitizeURL(char *url) {
    int length = strlen(url);
    char *sanitizedURL = (char*)malloc(length * sizeof(char));
    int index = 0;
    for(int i = 0; i < length; i++) {
        //check if character is alphanumeric or a forward slash
        if(isalnum(url[i]) || url[i] == '/') {
            sanitizedURL[index++] = url[i];
        }
    }
    sanitizedURL[index] = '\0';
    return sanitizedURL;
}

int main() {
    printf("Input URL to sanitize: ");
    char urlString[500];
    fgets(urlString, 500, stdin); //get input from user
    char *sanitized = sanitizeURL(urlString);
    printf("Sanitized URL: %s\n", sanitized);
    free(sanitized);
    return 0;
}