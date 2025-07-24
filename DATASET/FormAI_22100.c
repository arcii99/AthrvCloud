//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 1000

bool isInvalid(char c){
    if(c == '\'' || c == '\"' || c == '(' || c == ')' || c == '[' || 
       c == ']' || c == '{' || c == '}' || c == '<' || c == '>' ||
       c == '`' || c == ';' || c == '\\' || c == '|' || c == '&' || 
       c == '$' || c == '#' || c == '@' || c == '%' || c == '^' || 
       c == '*' || c == '+' || c == '=' || c == '?' || c == '/')
        return true;
    else
        return false;
}

char* sanitizeUrl(char* url){
    char* sanitizedUrl = (char*)malloc(MAX_URL_LENGTH*sizeof(char));
    int j=0;
    
    for(int i=0;i<strlen(url);i++){
        if(isInvalid(url[i])){
            continue;
        }
        sanitizedUrl[j] = url[i];
        j++;
    }
    sanitizedUrl[j] = '\0';
    return sanitizedUrl;
}

int main(){
    char url[MAX_URL_LENGTH], *sanitizedUrl;

    printf("Enter the URL to be sanitized: ");
    scanf("%s", url);

    sanitizedUrl = sanitizeUrl(url);

    printf("\nSanitized URL: %s\n", sanitizedUrl);

    free(sanitizedUrl);
    return 0;
}