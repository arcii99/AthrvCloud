//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: rigorous
#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

void sanitize(char* url) {
    int length = strlen(url);
    char sanitizedUrl[MAX_LEN];
    int j = 0;
    
    for (int i = 0; i < length; i++) {
        // Check for special characters
        if (url[i] == '<' || url[i] == '>' || url[i] == '"' || url[i] == '\'' || url[i] == '(' || url[i] == ')' || url[i] == '{' || url[i] == '}' || url[i] == '|' || url[i] == '\\' || url[i] == '^' || url[i] == '`' || url[i] == '%') {
            continue;
        }
        // Check for spaces and tabs
        else if (url[i] == ' ' || url[i] == '\t') {
            sanitizedUrl[j] = '-';
            j++;
        }
        // Everything else is added to the sanitized URL
        else {
            sanitizedUrl[j] = url[i];
            j++;
        }
    }
    sanitizedUrl[j] = '\0';
    strcpy(url, sanitizedUrl);
}

int main() {
    char url[MAX_LEN];
    printf("Enter URL: ");
    fgets(url, MAX_LEN, stdin);
    sanitize(url);
    printf("Sanitized URL: %s", url);

    return 0;
}