//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: happy
#include <stdio.h>
#include <string.h>

void sanitizeUrl(char *url) {
    int len = strlen(url);

    // Check for invalid characters
    for(int i=0; i<len; i++) {
        if(url[i] == '<' || url[i] == '>' || url[i] == '&' || url[i] == '\'') {
            url[i] = '_';
        }
    }

    // Remove trailing slash
    if(url[len-1] == '/') {
        url[len-1] = '\0';
    }
}

int main() {
    char url[100];

    printf("Welcome to the unique URL sanitizer program!\n");

    // Get URL from user
    printf("Please enter a URL to sanitize: ");
    scanf("%99s", url);

    // Sanitize URL
    sanitizeUrl(url);

    // Print sanitized URL
    printf("Your sanitized URL is: %s\n", url);

    // Celebrate the sanitized URL
    printf("Hooray! Your URL has been sanitized! Now go ahead and use it safely!\n");

    return 0;
}