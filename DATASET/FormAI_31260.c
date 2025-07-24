//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: retro
#include <stdio.h>
#include <string.h>

// function to sanitize URL
void sanitizeURL(char* url){
    // remove https:// or http:// from url if present
    if (strstr(url, "https://") != NULL){
        memmove(url, url+8, strlen(url));
    } else if (strstr(url, "http://") != NULL){
        memmove(url, url+7, strlen(url));
    }
    
    // remove any trailing slashes (/) from url
    int len = strlen(url);
    while (url[len-1] == '/'){
        url[len-1] = '\0';
        len--;
    }
    
    // remove any query string parameters from url
    char* qmark_ptr = strchr(url, '?');
    if (qmark_ptr != NULL){
        *qmark_ptr = '\0';
    }
}

int main(){
    // input url
    char url[] = "https://www.example.com/page/?param1=value1&param2=value2";
    printf("Original URL: %s\n", url);
    
    // sanitize url
    sanitizeURL(url);
    printf("Sanitized URL: %s\n", url);
    
    return 0;
}