//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: minimalist
#include <stdio.h>
#include <string.h>

char *sanitize(char *url) {
    char *sanitized = malloc(256);
    memset(sanitized, 0, 256);
    
    int j = 0;
    for(int i = 0; i < strlen(url); i++) {
        if(url[i] == ' ') {
            sanitized[j++] = '%';
            sanitized[j++] = '2';
            sanitized[j++] = '0';
        } else if(url[i] == '/') {
            sanitized[j++] = url[i];
        } else if(url[i] >= '0' && url[i] <= '9') {
            sanitized[j++] = url[i];
        } else if(url[i] >= 'a' && url[i] <= 'z') {
            sanitized[j++] = url[i];
        } else if(url[i] >= 'A' && url[i] <= 'Z') {
            sanitized[j++] = url[i];
        } else {
            sanitized[j++] = '%';
            char hex[3];
            snprintf(hex, 3, "%02x", url[i]);
            memcpy(sanitized+j, hex, 2);
            j += 2;
        }
    }
    
    return sanitized;
}

int main() {
    char *url = "https://www.example.com/path?query#fragment";
    char *sanitized = sanitize(url);
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized);
    free(sanitized);
    return 0;
}