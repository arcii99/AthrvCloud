//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: immersive
#include <stdio.h>
#include <string.h>

//function to sanitize URL
char* sanitizeURL(char *url){

    //converting the URL to lowercase
    int i;
    for(i=0; url[i]; i++){
        url[i] = tolower(url[i]);
    }

    //removing the http:// and https:// from the URL
    char *cleanURL = strstr(url, "http://");
    if(cleanURL != NULL){
        cleanURL += strlen("http://");
    }
    else{
        cleanURL = strstr(url, "https://");
        if(cleanURL != NULL){
            cleanURL += strlen("https://");
        }
        else{
            cleanURL = url;
        }
    }

    //removing any path from the URL, if present
    char *path = strstr(cleanURL, "/");
    if(path != NULL){
        *path = '\0';
    }
    
    return cleanURL;
}

int main(){
    
    char url[100];
    printf("Enter the URL to be sanitized: ");
    scanf("%s", url);

    char *cleanURL = sanitizeURL(url);
    printf("Sanitized URL: %s", cleanURL);

    return 0;
}