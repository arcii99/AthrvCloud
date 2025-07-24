//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *sanitize(char *url) {
    char *newUrl = (char *)malloc(strlen(url) + 1);
    int i, j = 0;
    for(i = 0; url[i] != '\0'; i++) {
        if(isalnum(url[i]) || url[i] == '-' || url[i] == '_' || url[i] == '.' || url[i] == '/') {
            newUrl[j++] = url[i];
        }
    }
    newUrl[j] = '\0';
    return newUrl;
}
int main() {
    char url[100];
    printf("Enter the URL to be sanitized: ");
    scanf("%s", url);
    char *newUrl = sanitize(url);
    printf("Sanitized URL: %s\n", newUrl);
    free(newUrl);
    return 0;
}