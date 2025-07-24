//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: lively
#include <stdio.h>
#include <string.h>

void sanitize_url(char* url) {
    int len = strlen(url);
    char sanitized_url[len+1];
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (url[i] == ' ') {
            sanitized_url[j++] = '%';
            sanitized_url[j++] = '2';
            sanitized_url[j++] = '0';
        } else {
            sanitized_url[j++] = url[i];
        }
    }

    strncpy(url, sanitized_url, strlen(sanitized_url)+1);
}

int main() {
    char url[] = "https://livechat.websit%20e.com/chat_log";
    printf("Unsanitized URL: %s\n", url);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}