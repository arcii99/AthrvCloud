//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: light-weight
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char url[100];
    printf("Enter the URL to sanitize: ");
    fgets(url, 100, stdin);

    int i, j;
    char sanitized_url[100];
    for(i=0, j=0; i<strlen(url); i++){
        if(url[i]==' ' || url[i]=='\n') continue;

        if(url[i]=='/' && url[i+1]=='/') continue;

        if(url[i]!=' '){
            sanitized_url[j] = url[i];
            j++;
        }
    }
    sanitized_url[j] = '\0';

    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}