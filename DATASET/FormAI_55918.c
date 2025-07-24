//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: systematic
#include <stdio.h>
#include <string.h>

void sanitize_url(char *url){
    int length = strlen(url);
    char sanitized_url[length + 1];
    int j = 0;
    for(int i = 0; i < length; i++){
        if(url[i] == ' '){
            sanitized_url[j] = '%';
            sanitized_url[j+1] = '2';
            sanitized_url[j+2] = '0';
            j +=3;
        }
        else{
            sanitized_url[j] = url[i];
            j++;
        }
    }
    sanitized_url[j] = '\0';
    strcpy(url, sanitized_url);
}

int main(){
    char url[100];
    printf("Enter URL to sanitize (max 100 characters): ");
    fgets(url, 100, stdin);
    sanitize_url(url);
    printf("Sanitized URL: %s", url);
    return 0;
}