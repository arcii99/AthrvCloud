//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Function to check if a character is a valid character for a URL 
 * Returns 1 if the character is valid, returns 0 otherwise
 */
int is_valid_character(char c){
    if(isalnum(c) || c == '.' || c == '/' || c == ':' || c == '?' || c == '=' || c == '&' || c == '-') {
        return 1;
    }
    return 0;
}

/*
 * Function to remove any unwanted characters from a string
 * Returns the sanitized version of the string
 */
char* sanitize_url(char* url){
    int length = strlen(url);
    char* sanitized_url = (char*)malloc(sizeof(char) * (length + 1));
    int j = 0; // Index for sanitized_url
    for(int i = 0; i < length; i++){
        if(is_valid_character(url[i])){
            sanitized_url[j] = url[i];
            j++;
        }
    }
    sanitized_url[j] = '\0'; // Add the null character to the end of sanitized_url
    return sanitized_url;
}

int main(){
    char* url = "https://www.google.com/search?q=c+url+sanitizer&oq=c+url+sanitizer&aqs=chrome..69i57j0i22i30j0i390l2.5511j0j7&sourceid=chrome&ie=UTF-8";
    char* sanitized_url = sanitize_url(url);
    printf("The original URL: %s\n", url);
    printf("The sanitized URL: %s\n", sanitized_url);
    free(sanitized_url); // Remember to free the memory allocated by malloc
    return 0;
}