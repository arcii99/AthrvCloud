//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* sanitizeUrl(char *url){
    //remove whitespace
    char* sanitized_url = calloc(strlen(url) + 1, sizeof(char));
    int idx_sanitized = 0;
    for(int i = 0; url[i]; i++){
        if(!isspace(url[i])){
            sanitized_url[idx_sanitized++] = url[i];
        }
    }
    //add http if not included
    if(strncmp(sanitized_url, "http", 4) != 0){
        char *temp_url = calloc(strlen(sanitized_url) + 8, sizeof(char));
        memcpy(temp_url, "https://", 8);
        memcpy(temp_url + 8, sanitized_url, strlen(sanitized_url));
        free(sanitized_url);
        return temp_url;
    }
    return sanitized_url;
}

int main(){
    char url[] = "www.google.com";
    char *sanitized_url = sanitizeUrl(url);
    printf("Sanitized URL: %s\n", sanitized_url);

    char url2[] = "https://facebook.com";
    char *sanitized_url2 = sanitizeUrl(url2);
    printf("Sanitized URL: %s\n", sanitized_url2);

    free(sanitized_url);
    free(sanitized_url2);
    return 0;
}