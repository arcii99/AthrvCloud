//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitizeURL(char* url) {
    int i, j = 0;
    char sanitizedURL[strlen(url) + 1];
    
    for(i = 0; i < strlen(url); i++) {
        if(url[i] == '<' || url[i] == '>' || url[i] == '&' || url[i] == '\"' || url[i] == '\'') {
            continue;
        } else {
            sanitizedURL[j] = url[i];
            j++;
        }
    }
    
    sanitizedURL[j] = '\0';
    strcpy(url, sanitizedURL);
}

int main() {
    char url[] = "https://www.google.com/search?q=<script>alert('hacked')</script>";
    
    printf("Before sanitization: %s\n", url);
    
    sanitizeURL(url);
    
    printf("After sanitization: %s\n", url);
    
    return 0;
}