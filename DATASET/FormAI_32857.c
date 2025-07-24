//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: peaceful
#include <stdio.h>
#include <string.h>

#define MAX_URL_LENGTH 255

char* sanitize_url(char* url) {
    char* sanitized_url = (char*) malloc(MAX_URL_LENGTH*sizeof(char));
    int sanitized_index = 0;

    for(int i = 0; i < strlen(url); i++) {
        if(url[i] == ' ') {
            sanitized_url[sanitized_index++] = '%';
            sanitized_url[sanitized_index++] = '2';
            sanitized_url[sanitized_index++] = '0';
        } else if(url[i] >= 'A' && url[i] <= 'Z') {
            sanitized_url[sanitized_index++] = url[i] + 32;
        } else {
            sanitized_url[sanitized_index++] = url[i];
        }

        if(sanitized_index >= MAX_URL_LENGTH) {
            break;
        }
    }

    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter URL to be sanitized: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}