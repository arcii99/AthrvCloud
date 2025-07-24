//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: scalable
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_URL_LENGTH 1000

char *sanitize_url(char *url) {
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    if(!sanitized_url) {
        return NULL;
    }
    int i = 0, j = 0;
    while(url[i]) {
        if(isalnum(url[i]) || url[i] == '-' || url[i] == '_' || url[i] == '.') {
            sanitized_url[j] = url[i];
            i++;
            j++;
        } else if(url[i] == '%') {
            if(isxdigit(url[i+1]) && isxdigit(url[i+2])) {
                sanitized_url[j] = url[i];
                sanitized_url[j+1] = url[i+1];
                sanitized_url[j+2] = url[i+2];
                i += 3;
                j += 3;
            } else {
                i++;
            }
        } else {
            i++;
        }
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH] = "http://www.example.com/foo bar?query=hello%world";
    printf("Original URL: %s\n", url);
    char *sanitized = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized);
    free(sanitized);
    return 0;
}