//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_SIZE 1024

char *sanitize_url(char *raw_url);

int main() {
    char raw_url[MAX_URL_SIZE];
    printf("Enter a URL to sanitize: ");
    fgets(raw_url, MAX_URL_SIZE, stdin);

    char *sanitized_url = sanitize_url(raw_url);

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}

char *sanitize_url(char *raw_url) {
    char *sanitized_url = calloc(MAX_URL_SIZE, sizeof(char));
    int sanitized_url_index = 0;

    for (int i = 0; i < strlen(raw_url); i++) {

        if (raw_url[i] == ' ') { // Replace spaces with '+'
            sanitized_url[sanitized_url_index++] = '+';
        } else if (raw_url[i] == '&') { // Replace '&' with '%26'
            strcat(sanitized_url, "%26");
            sanitized_url_index += 3;
        } else if (raw_url[i] == '%') { // Replace '%' with '%25'
            strcat(sanitized_url, "%25");
            sanitized_url_index += 3;
        } else if (raw_url[i] >= '0' && raw_url[i] <= '9' || // Preserve alphanumeric characters
                   raw_url[i] >= 'A' && raw_url[i] <= 'Z' ||
                   raw_url[i] >= 'a' && raw_url[i] <= 'z' ||
                   raw_url[i] == '-' ||
                   raw_url[i] == '_' ||
                   raw_url[i] == '.' ||
                   raw_url[i] == '~') {
            sanitized_url[sanitized_url_index++] = raw_url[i];
        }
    }

    return sanitized_url;
}