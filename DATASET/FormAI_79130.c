//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: thoughtful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LENGTH 200

char* sanitise_url(char* url){
    // if url has http or https then remove it
    if(strstr(url, "http://") != NULL || strstr(url, "https://") != NULL) {
        url += 7;
    }

    // remove any forward slashes at the end of url
    while(url[strlen(url) - 1] == '/') {
        url[strlen(url) - 1] = '\0';
    }

    // remove any parameters from the url
    char* param_start = strstr(url, "?");
    if(param_start != NULL) {
        *param_start = '\0';
    }

    // remove any fragements from the url
    char* frag_start = strstr(url, "#");
    if(frag_start != NULL) {
        *frag_start = '\0';
    }

    return url;
}

int main() {
    char input_url[MAX_LENGTH];
    printf("Enter URL to be sanitised: ");
    scanf("%s", input_url);

    char* sanitised_url = sanitise_url(input_url);
    printf("Sanitised URL: %s\n", sanitised_url);
    
    return 0;
}