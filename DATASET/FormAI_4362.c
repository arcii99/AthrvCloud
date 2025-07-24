//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: standalone
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// Function to clean URL of any malicious content
void clean_URL(char* url) {
    int n = strlen(url), i;
    int flag = 0, index = 0;
    char* newURL = (char*)calloc(n+1, sizeof(char));
 
    for (i = 0; i < n; i++) {
        // Check for any malicious content
        if(!isalnum(url[i]) && url[i] != '.' && url[i] != '/' && url[i] != ':' && url[i] != '-') {
            flag = 1;
            continue;
        }
        newURL[index++] = url[i];
    }
    
    if(flag) {
        printf("WARNING: The given URL contains some malicious content and has been cleaned accordingly.\n\n");
    }
    printf("The sanitized URL is: %s\n", newURL);
}
 

int main() {
    char url[100];
    printf("Enter a URL: ");
    scanf("%s", url);
    printf("\n");
    
    clean_URL(url);
 
    return 0;
}