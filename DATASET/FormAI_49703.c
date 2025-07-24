//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: safe
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1024

char sanitized_url[MAX_URL_LENGTH];

void sanitize_url(char* url) {
    /* Step 1: Copy the URL to sanitized_url */
    strncpy(sanitized_url, url, MAX_URL_LENGTH);
    
    /* Step 2: Convert the URL to lowercase */
    for(int i = 0; sanitized_url[i]; i++) {
        sanitized_url[i] = tolower(sanitized_url[i]);
    }
    
    /* Step 3: Check if the URL starts with "http://" or "https://" */
    if(strncmp(sanitized_url, "http://", 7) != 0 && strncmp(sanitized_url, "https://", 8) != 0) {
        /* If not, add "http://" to the beginning of the URL */
        memmove(sanitized_url+7, sanitized_url, strlen(sanitized_url)+1);
        strncpy(sanitized_url, "http://", 7);
    }
    
    /* Step 4: Remove any trailing slashes from the URL */
    int length = strlen(sanitized_url);
    while(length > 0 && sanitized_url[length-1] == '/') {
        sanitized_url[length-1] = '\0';
        length = strlen(sanitized_url);
    }
}

int main() {
    char url[MAX_URL_LENGTH];
    
    printf("Enter a URL: ");
    scanf("%s", url);
    
    sanitize_url(url);
    
    printf("Sanitized URL: %s\n", sanitized_url);
    
    return 0;
}