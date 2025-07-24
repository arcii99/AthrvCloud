//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: curious
#include <stdio.h>
#include <string.h>

#define MAX_URL_LENGTH 256

void sanitizeUrl(char* url) {
    int i;
    int j = 0;
    char sanitizedUrl[MAX_URL_LENGTH];
    int urlLength = strlen(url);

    for(i = 0; i < urlLength; i++) {
        if(url[i] == ' ' || url[i] == '\n' || url[i] == '\r') {
            continue; // Ignore whitespace characters
        }
        else if(url[i] == '<' || url[i] == '>' || url[i] == '"' || url[i] == '\'') {
            continue; // Ignore characters that can cause issues with HTML and Javascript
        }
        else {
            sanitizedUrl[j++] = url[i]; // Copy safe characters to new string
        }
    }

    sanitizedUrl[j] = '\0'; // Terminate string

    strcpy(url, sanitizedUrl); // Overwrite original URL with sanitized version
}

int main(int argc, char** argv) {
    char url[MAX_URL_LENGTH];

    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    sanitizeUrl(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}