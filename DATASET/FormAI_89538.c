//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: romantic
#include <stdio.h>
#include <string.h>
#define MAX_URL_LENGTH 500

char* removeQueryString(char* url){
    char* ptr = strstr(url, "?");
    if(ptr != NULL){
        *ptr = '\0';
    }
    return url;
}

int main(){
    char url[MAX_URL_LENGTH];
    printf("Enter the URL: ");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = '\0'; // remove trailing newline
    printf("Original URL: %s\n", url);
    char* sanitizedUrl = removeQueryString(url);
    printf("Sanitized URL: %s\n", sanitizedUrl);
    return 0;
}