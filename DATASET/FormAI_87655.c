//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: immersive
#include <stdio.h>
#include <string.h>

void sanitize(char *url) {
    int url_len = strlen(url);
    int i, j;

    // Check for "http://" or "https://"
    char protocol[10];
    for (i=0; i<7; i++) {
        protocol[i] = url[i];
    }
    protocol[i] = '\0';

    if (strcmp(protocol, "http://") != 0 && strcmp(protocol, "https://") != 0) {
        // Sanitize missing protocol
        char temp[url_len+8];
        sprintf(temp, "http://%s", url);
        strcpy(url, temp);
    }

    // Check for trailing '/'
    j = url_len - 1;
    while (url[j] == '/') {
        j--;
    }
    if (j != url_len - 1) {
        url[j+1] = '\0';
    }
}

int main() {
    char url[1000];
    printf("Enter a URL: ");
    fgets(url, 1000, stdin);

    sanitize(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}