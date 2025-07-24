//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 200

int is_url(char* str){
    if(strncmp("http://", str, 7) == 0 || strncmp("https://", str, 8) == 0){
        return 1;
    }else{
        return 0;
    }
}

char* sanitize_url(char* url){
    char* sanitized = malloc(MAX_LENGTH * sizeof(char));
    if(is_url(url)){
        char* domain = strtok(url, "/");
        char* path = strtok(NULL, "");
        sprintf(sanitized, "%s/%s", domain, path);
    }else{
        strcpy(sanitized, "Invalid URL");
    }
    return sanitized;
}

int main(){
    char url[MAX_LENGTH];

    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_LENGTH, stdin);
    url[strcspn(url, "\n")] = 0;

    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s", sanitized_url);

    free(sanitized_url);
    return 0;
}