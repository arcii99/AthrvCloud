//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: intelligent
#include <stdio.h>
#include <string.h>

int main(){
    char url[100];
    printf("Enter a URL to sanitize: ");
    fgets(url, 100, stdin);
    url[strlen(url)-1] = '\0';

    // Convert the URL to lowercase
    for (int i = 0; i < strlen(url); i++) {
        if (url[i] >= 'A' && url[i] <= 'Z') {
            url[i] = url[i] + 32;
        }
    }

    // Remove any trailing whitespace
    int end = strlen(url) - 1;
    while (end >= 0 && url[end] == ' ') {
        url[end] = '\0';
        end--;
    }

    // Check if the URL starts with "https://" or "http://"
    if (strncmp(url, "https://", 8) != 0 && strncmp(url, "http://", 7) != 0) {
        char newUrl[strlen(url) + 8];
        strcpy(newUrl, "https://");
        strcat(newUrl, url);
        strcpy(url, newUrl);
    }

    printf("Sanitized URL: %s\n", url);
    return 0;
}