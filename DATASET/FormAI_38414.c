//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_URL_LENGTH 1000

//Function to remove special characters from the URL
char* sanitizeURL(char* url){
    char* sanitizedURL = malloc(sizeof(char) * MAX_URL_LENGTH);
    int sanitizedIndex = 0;
    for(int i=0; i<strlen(url); i++){
        char c = url[i]; 
        if((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9') || c=='.' 
            || c=='/' || c==':' || c=='-' || c==' '){
            sanitizedURL[sanitizedIndex++] = c;
        }
    }
    sanitizedURL[sanitizedIndex] = '\0';
    return sanitizedURL;
}

int main(){
    char url[MAX_URL_LENGTH], c;
    printf("Enter a URL to sanitize: ");
    int index = 0;
    while((c=getchar()) != '\n' && index < MAX_URL_LENGTH){
        url[index++] = c;
    }
    url[index] = '\0';
    char* sanitizedURL = sanitizeURL(url);
    printf("Sanitized URL: %s\n", sanitizedURL);
    free(sanitizedURL);
    return 0;
}