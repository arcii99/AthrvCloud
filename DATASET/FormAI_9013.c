//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* sanitizeUrl(char* url) {
    char* sanitizedUrl = (char*) malloc(strlen(url) + 1);
    int i = 0;
    int j = 0;
    while(url[i]) {
        if((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9') || url[i] == '-' || url[i] == '.' || url[i] == '_' || url[i] == '~') {
            sanitizedUrl[j] = url[i];
            j++;
        }
        else if(url[i] == ' ') {
            sanitizedUrl[j] = '+';
            j++;
        }
        else {
            sanitizedUrl[j] = '%';
            sanitizedUrl[j+1] = (url[i] / 16 < 10) ? (url[i] / 16 + '0') : (url[i] / 16 - 10 + 'A');
            sanitizedUrl[j+2] = (url[i] % 16 < 10) ? (url[i] % 16 + '0') : (url[i] % 16 - 10 + 'A');
            j += 3;
        }
        i++;
    }
    sanitizedUrl[j] = '\0';
    return sanitizedUrl;
}

int main() {
    printf("Welcome to the URL Sanitizer program!\n");
    printf("Enter the URL you want to sanitize: ");
    char url[1000];
    scanf("%[^\n]", url);
    getchar();
    char* sanitizedUrl = sanitizeUrl(url);
    printf("\nSanitized URL: %s\n", sanitizedUrl);
    free(sanitizedUrl);
    return 0;
}