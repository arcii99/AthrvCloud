//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: random
#include <stdio.h>
#include <string.h>

void sanitizeURL(char *url) {
    // convert URL to lowercase
    for(int i = 0; url[i]; i++){
        url[i] = tolower(url[i]);
    }

    //check for https/http
    if(strstr(url, "https://") || strstr(url, "http://")){
        // found one of the protocol prefixes
        printf("Valid URL protocol detected.\n");
    } else {
        // no protocol prefix found, add http:// prefix
        printf("No valid URL protocol detected. Adding http:// prefix.\n");
        char temp[255] = "http://";
        strcat(temp, url);
        strcpy(url, temp);
    }

    //remove trailing '/' from the URL
    int length = strlen(url);
    if(url[length-1] == '/') {
        url[length-1] = '\0';
        printf("Trailing slash removed from URL.\n");
    }
}

int main() {
    char url[255];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);
    sanitizeURL(url);
    printf("Sanitized URL: %s", url);
    return 0;
}