//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: active
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitize_url(char* url) {
    char safe_url[256] = "";
    int j = 0;
    for (int i=0; i<strlen(url); i++) {
        if (isalnum(url[i]) || url[i] == '/' || url[i] == '.' || url[i] == '-') {
            safe_url[j] = url[i];
            j++;
        }
    }
    strcpy(url, safe_url);
}

int main() {
    char url[256] = "http://www.example.com/path/to/file.html?param=value";
    printf("Original URL: %s\n", url);

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}