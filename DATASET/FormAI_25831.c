//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sanitizeUrl(char *url){
    char *sanitizedUrl = (char *)malloc(2000 * sizeof(char)); //allocate memory for sanitized url
    int j = 0; //counter for sanitized url
    int length = strlen(url);
    for(int i = 0; i < length; i++){
        if(url[i] == '<' || url[i] == '>' || url[i] == '\'' || url[i] == '\"' || url[i] == '#'){
            //skip characters that can potentially be harmful in an URL
            continue;
        }
        sanitizedUrl[j++] = url[i];
    }
    sanitizedUrl[j] = '\0'; //add null character to end string
    return sanitizedUrl;
}

int main(){
    char url[2000];
    printf("Enter an URL to be sanitized: ");
    fflush(stdin);
    fgets(url, 2000, stdin);
    char *sanitizedUrl = sanitizeUrl(url);
    printf("Sanitized URL: %s", sanitizedUrl);
    free(sanitizedUrl); //free memory allocated to sanitized url
    return 0;
}