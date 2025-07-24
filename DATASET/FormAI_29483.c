//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* sanitize_url(char* url){
    int i, j;
    int len = strlen(url);
    char* sanitized_url = (char*) calloc(len + 1, sizeof(char));

    for(i = 0, j = 0; i < len; i++){
        if(isalnum(url[i]) || url[i] == '/' || url[i] == '.' || url[i] == '-'){
            sanitized_url[j] = url[i];
            j++;
        }
    }

    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main(){
    char url[100];
    printf("Enter a URL to sanitize: ");
    fgets(url, 100, stdin);

    char* sanitized_url = sanitize_url(url);

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}