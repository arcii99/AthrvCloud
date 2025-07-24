//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 100

int main(){
    char url[MAX_URL_LENGTH];
    printf("Enter URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Removing newline character from the end of the input
    url[strcspn(url, "\n")] = 0;

    // Checking if the entered URL already contains http:// or https://
    if(strncmp(url, "http://", 7) && strncmp(url, "https://", 8)){
        printf("Sanitized URL: http://%s\n", url);
    } else {
        printf("Sanitized URL: %s\n", url);
    }
    
    // Removing redundant '/' after the domain name
    char *slash_pos = strstr(url, "//");
    if(slash_pos != NULL){
        slash_pos += 2;
        char *next_slash = strstr(slash_pos, "/");
        if(next_slash != NULL){
            strcpy(slash_pos, next_slash);
        }
    }

    printf("Sanitized URL (extra '/' removed): %s\n", url);

    return 0;
}