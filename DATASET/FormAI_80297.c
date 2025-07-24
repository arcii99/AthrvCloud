//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitize(char *url) {
    int i, j;

    // Remove whitespace at the beginning and end of the URL
    while (isspace((unsigned char) *url)) url++;
    if (*url == 0) return;
    j = strlen(url) - 1;
    while (j >= 0 && isspace((unsigned char) url[j])) j--;
    url[j + 1] = 0;

    // Check for "http://" or "https://" at the beginning of the URL
    i = 0;
    if (strstr(url, "http://") == url || strstr(url, "https://") == url) {
        i = strlen("http://");
        if (strstr(url, "https://") == url) {
            i = strlen("https://");
        }
    }

    // Remove ".." and "./" from the URL
    for (; i < strlen(url); i++) {
        // Look for "/../"
        if (url[i] == '/' && url[i+1] == '.' && url[i+2] == '.' && url[i+3] == '/') {
            for (j = i - 1; j >= 0; j--) {
                if (url[j] == '/') {
                    memmove(url+j+1, url+i+4, strlen(url+i+4)+1);
                    i = j;
                    break;
                }
            }
        }
        // Look for "/./"
        if (url[i] == '/' && url[i+1] == '.' && url[i+2] == '/') {
            memmove(url+i+1, url+i+3, strlen(url+i+3)+1);
            i--;
        }
    }
}

int main() {
    char url[100] = "   https://www.example.com/../   ";
    printf("Original URL: %s\n", url);
    sanitize(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}