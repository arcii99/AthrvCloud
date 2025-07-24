//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: invasive
#include<stdio.h>
#include<string.h>

//function to sanitize URL
void sanitizeURL(char *url) {
    char sanitizedUrl[100];
    int sanitizedIndex = 0;

    for (int i = 0; url[i] != '\0'; i++) {
        if ((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9')) {
            //valid character, copy to sanitizedUrl
            sanitizedUrl[sanitizedIndex++] = url[i];
        }
        else {
            //invalid character, ignore
            continue;
        }
    }

    //append null character to sanitizedUrl
    sanitizedUrl[sanitizedIndex] = '\0';

    //update url with sanitizedUrl
    strcpy(url, sanitizedUrl);
}

int main() {
    char url[100];

    //get input from user
    printf("Enter URL to sanitize: ");
    scanf("%s", url);

    //sanitize URL
    sanitizeURL(url);

    //print sanitized URL
    printf("Sanitized URL: %s", url);

    return 0;
}