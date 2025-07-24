//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitize_url(char* url){
    char* ptr = strchr(url, '#');
    if(ptr != NULL){
        *ptr = '\0';
    }
    ptr = strchr(url, '?');
    if(ptr != NULL){
        *ptr = '\0';
    }
    int len = strlen(url);
    if(len > 7 && strncmp(url, "http://", 7) == 0){
        memmove(url, &url[7], len - 6);
        len -= 7;
    }else if(len > 8 && strncmp(url, "https://", 8) == 0){
        memmove(url, &url[8], len - 7);
        len -= 8;
    }
    ptr = strrchr(url, '/');
    if(ptr == NULL){
        return;
    }
    int offset = ptr - url;
    if(offset == len - 1){
        *(ptr - 1) = '\0';
    }
}

int main(){
    char* url = malloc(sizeof(char) * 100);
    printf("Enter a URL: ");
    scanf("%s", url);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    free(url);
    return 0;
}