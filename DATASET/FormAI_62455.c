//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1024

char* sanitize_url(char* url){
    char* sanitized_url = calloc(MAX_URL_LENGTH, sizeof(char));
    int index = 0;
    int url_length = strlen(url);
    
    for(int i=0; i<url_length; i++){
        if(isalnum(url[i]) || url[i] == '.' || url[i] == '-' || url[i] == '_'){
            sanitized_url[index] = url[i];
            index++;
        }
    }
    
    return sanitized_url;
}

int main(){
    char* url = "https://www.example.com/products/?category=books&price_range=$10-$20";
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s", sanitized_url);
    free(sanitized_url);
    return 0;
}