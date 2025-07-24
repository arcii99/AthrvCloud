//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 200

char* sanitize_url(char *original_url){
    char* sanitized_url = (char*)malloc(sizeof(char)*MAX_URL_LENGTH); //allocate memory
    int i, j=0;
    for(i=0; i<strlen(original_url); i++){
        if(original_url[i] == '@'){
            continue;
        }
        if(original_url[i] == '\''){
            sanitized_url[j++] = '"';
            continue;
        }
        sanitized_url[j++] = original_url[i];
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main(){
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = 0; //remove trailing newline character from input
    char *sanitized_url = sanitize_url(url);
    printf("The sanitized URL is: %s\n", sanitized_url);
    free(sanitized_url); //free memory to avoid memory leaks
    return 0;
}