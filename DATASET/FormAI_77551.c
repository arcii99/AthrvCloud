//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitize(char *url);

int main() {
    char url[100];

    printf("Enter URL to sanitize: ");
    fgets(url, 100, stdin);

    // remove newline character from input
    url[strcspn(url, "\n")] = 0;

    printf("Your URL: %s\n", url);
    
    // call sanitize function
    sanitize(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}

void sanitize(char *url) {
    
    printf("Sanitizing URL...\n");

    // replace all whitespace characters with '%20'
    for(int i = 0; i < strlen(url); i++) {
        if(url[i] == ' ' || url[i] == '\t') {
            url[i] = '%';
            url[i+1] = '2';
            url[i+2] = '0';
        }
    }

    // capitalize the first letter of each word for added security
    for(int i = 0; i < strlen(url); i++) {
        if(i == 0 || (url[i-1] == '%' && url[i] == '2' && url[i+1] == '0')) {
            url[i] = toupper(url[i]);
        } else {
            url[i] = tolower(url[i]);
        }
    }

    printf("URL sanitized successfully!\n");
}