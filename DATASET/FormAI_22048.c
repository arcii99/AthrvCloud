//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* This function will sanitize the URL */
char* sanitize_url(char* url){
    /* Allocate memory to store the sanitized URL */
    char *sanitized_url = (char*)calloc(strlen(url)+1, sizeof(char));
    int j = 0;
    
    /* Convert the URL to lowercase */
    for(int i=0; url[i]; i++){
        sanitized_url[j++] = tolower(url[i]);
    }
    sanitized_url[j] = '\0';

    /* Check for any trailing slashes */
    if(sanitized_url[strlen(sanitized_url)-1] == '/')
        sanitized_url[strlen(sanitized_url)-1] = '\0';

    /* Check for any special characters and replace them with a hyphen */
    for(int i=0; sanitized_url[i]; i++){
        if(!isalnum(sanitized_url[i]) && sanitized_url[i] != '-' && sanitized_url[i] != '_'){
            sanitized_url[i] = '-';
        }
    }

    return sanitized_url;
}

int main(){
    char url[100];

    /* Get the URL from the user */
    printf("Enter a URL: ");
    scanf("%s", url);

    /* Sanitize the URL */
    char *sanitized_url = sanitize_url(url);

    /* Display the sanitized URL */
    printf("Sanitized URL: %s\n", sanitized_url);

    /* Free the allocated memory */
    free(sanitized_url);

    return 0;
}