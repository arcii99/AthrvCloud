//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitize_url(char* url) {
    // Remove any potential script injection attacks
    char* javascript = "javascript:";
    char* index = strstr(url, javascript);
    while (index != NULL) {
        memset(index, ' ', strlen(javascript));
        index = strstr(url, javascript);
    }

    // Remove any potential SQL injection attacks
    char* dangerous_chars = "<>;\'\"%";
    int i, j;
    for (i = 0, j = 0; i < strlen(url); i++, j++) {
        if (strstr(dangerous_chars, &url[i]) != NULL) {
            j--;
        }
        else {
            url[j] = url[i];
        }
    }
    url[j] = '\0';
}

int main() {
    char url[100];
    printf("Enter a URL: ");
    scanf("%s", url);

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}