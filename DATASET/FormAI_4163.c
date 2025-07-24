//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char url[100];
    int i, j, len;

    printf("Enter URL: ");
    scanf("%s", url);

    len = strlen(url); // get length of URL

    // Convert the URL to lowercase
    for(i = 0; i < len; i++) {
        url[i] = tolower(url[i]);
    }

    // Remove any trailing slashes from the URL
    while(len > 0 && url[len - 1] == '/') {
        url[len - 1] = '\0';
        len--;
    }

    // Remove any non-alphanumeric characters from the URL
    for(i = 0, j = 0; i < len; i++) {
        if(isalnum(url[i])) {
            url[j++] = url[i];
        }
    }
    url[j] = '\0'; // null-terminate the sanitized URL

    printf("Sanitized URL: %s\n", url);

    return 0;
}