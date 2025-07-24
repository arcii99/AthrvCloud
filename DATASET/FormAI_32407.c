//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: active
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitizeUrl(char* url) {
    // Convert the URL to lowercase 
    for (int i = 0; i < strlen(url); i++) {
        url[i] = tolower(url[i]);
    }

    // Remove whitespace from the beginning and end of the URL
    int start = 0; 
    int end = strlen(url) - 1;

    while (isspace(url[start])) {
        start++;
    }

    while (isspace(url[end])) {
        end--;
    }

    for (int i = start; i < end + 1; i++) {
        url[i - start] = url[i];
    }
    url[end - start + 1] = '\0';

    // Check if the URL is valid by ensuring it starts with "http://" or "https://"
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        printf("Invalid URL.\n");
        return;
    }

    // Remove any consecutive forward slashes after the protocol
    int i = strncmp(url, "http://", 7) == 0 ? 7 : 8;
    int j = i;

    while (url[j] != '\0') {
        if (url[j] == '/' && url[j - 1] == '/') {
            while (url[j] == '/') {
                for (int k = j; k < strlen(url); k++) {
                    url[k] = url[k + 1];
                }
            }
        }
        j++;
    }

    // Remove any trailing slashes
    if (url[strlen(url) - 1] == '/') {
        url[strlen(url) - 1] = '\0';
    }
}

int main() {
    char url1[] = "hTTps://www.ExAmple.cOM//test////";
    char url2[] = "ftp://example.com/file/";
    char url3[] = "http://example.com/cgi-bin//search.pl?q=search+term";

    printf("Before sanitization:\n");
    printf("url1: %s\n", url1);
    printf("url2: %s\n", url2);
    printf("url3: %s\n", url3);

    sanitizeUrl(url1);
    sanitizeUrl(url2);
    sanitizeUrl(url3);

    printf("\nAfter sanitization:\n");
    printf("url1: %s\n", url1);
    printf("url2: %s\n", url2);
    printf("url3: %s\n", url3);

    return 0;
}