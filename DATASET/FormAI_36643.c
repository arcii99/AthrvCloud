//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* sanitizeUrl(char* url) {
    char* sanitizedUrl = malloc(strlen(url) + 1);
    int sanitizedUrlLength = 0;
    
    bool afterQuestionMark = false;
    
    for (int i = 0; i < strlen(url); ++i) {
        char currentChar = url[i];
        
        if (afterQuestionMark) {
            if (currentChar == '\0') {
                sanitizedUrl[sanitizedUrlLength++] = currentChar;
            }
        } else {
            if (currentChar == '?') {
                afterQuestionMark = true;
            } else if (currentChar == ' ') {
                sanitizedUrl[sanitizedUrlLength++] = '%';
                sanitizedUrl[sanitizedUrlLength++] = '2';
                sanitizedUrl[sanitizedUrlLength++] = '0';
            } else {
                sanitizedUrl[sanitizedUrlLength++] = currentChar;
            }
        }
    }
    
    return sanitizedUrl;
}

int main() {
    char url[] = "http://example.com/index.html?query=hello world";
    char* sanitizedUrl = sanitizeUrl(url);
    
    printf("%s\n", sanitizedUrl);
    
    free(sanitizedUrl);
    
    return 0;
}