//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char url[1000];
    printf("Enter a URL: ");
    scanf("%s", url);

    // check if protocol is present and add if not
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        char newUrl[1000];
        sprintf(newUrl, "http://%s", url);
        strcpy(url, newUrl);
    }

    // remove trailing slash if present
    int len = strlen(url);
    if (url[len - 1] == '/') {
        url[len - 1] = '\0';
    }

    // sanitize parameters
    char* pos = strchr(url, '?');
    if (pos != NULL) {
        *pos = '\0';
    }

    // convert entire url to lowercase
    int i;
    for (i = 0; url[i]; i++) {
        url[i] = tolower(url[i]);
    }

    printf("Sanitized URL: %s\n", url);

    return 0;
}