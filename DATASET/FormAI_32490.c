//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: innovative
#include <stdio.h>
#include <string.h>

int main() {
    char url[1000], sanitized_url[1000];
    int i, j = 0;

    printf("Enter the URL to sanitize: ");
    fgets(url, sizeof(url), stdin);

    // remove any trailing newline character from the input
    url[strcspn(url, "\n")] = 0;

    // remove any protocol from the URL
    if(strncmp(url, "http://", 7) == 0) {
        strcpy(url, url+7);
    } else if(strncmp(url, "https://", 8) == 0) {
        strcpy(url, url+8);
    }

    // remove any www subdomain from the URL
    if(strncmp(url, "www.", 4) == 0) {
        strcpy(url, url+4);
    }

    // remove any query parameters from the URL
    for(i = 0; url[i]; i++) {
        if(url[i] == '?') {
            break;
        } else {
            sanitized_url[j++] = url[i];
        }
    }
    sanitized_url[j] = '\0';

    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}