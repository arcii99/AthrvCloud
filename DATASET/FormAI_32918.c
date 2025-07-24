//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitize_url(char *url);

int main() {
    char url[100];

    printf("Enter a URL: ");
    fgets(url, 100, stdin);

    sanitize_url(url);

    printf("The sanitized URL is: %s", url);

    return 0;
}

void sanitize_url(char *url) {
    int i = 0, j = 0, len = strlen(url);

    while (i < len) {
        if (url[i] == ' ') { // Replace spaces with %20
            url[j++] = '%';
            url[j++] = '2';
            url[j++] = '0';
            i++;
        } else if (url[i] == '/') {
            if (i + 1 < len && url[i+1] == '/') { // Replace double forward slashes with single forward slash
                url[j++] = url[i++];
            } else { // Do not modify single forward slashes
                url[j++] = url[i++];
            }
        } else if (url[i] == '?') { // Remove all query strings
            break;
        } else { // Copy all other characters as is
            url[j++] = url[i++];
        }
    }

    url[j] = '\0'; // Add string terminator
}