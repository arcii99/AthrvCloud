//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: shape shifting
#include<stdio.h>
#include<string.h>
#define MAX_URL_LENGTH 100

void sanitize_url(char *url) {
    int length = strlen(url);
    char sanitized_url[MAX_URL_LENGTH];
    int j = 0;
    for (int i = 0; i < length; i++) {
        if ((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9') || (url[i] == '/') || (url[i] == ':') || (url[i] == '.') || (url[i] == '-')) {
            sanitized_url[j] = url[i];
            j++;
        }
    }
    sanitized_url[j] = '\0';
    strcpy(url, sanitized_url);
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter the URL you want to sanitize: ");
    scanf("%s", url);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}