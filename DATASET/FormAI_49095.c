//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sanitize_url(char *url){
    char *result = (char *)calloc(strlen(url) + 1, sizeof(char));
    int i = 0, j = 0;
    while(url[i]){
        if(url[i] == '.' || url[i] == '/' || isalnum(url[i])){
            result[j] = url[i];
            j++;
        }
        i++;
    }
    result[j] = '\0';
    strcpy(url, result);
    free(result);
}

int main(){
    char url[100];
    printf("Enter the URL to sanitize:\n");
    scanf("%s", url);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}