//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defining function to sanitize URL
char *urlSanitizer(char *url) {
    char *cleanURL = malloc(strlen(url) + 1); //Allocating memory for clean URL
    int i, j = 0; 
    
    //Iterating through URL characters
    for(i = 0; url[i] != '\0'; i++) {
        if((url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= 'a' && url[i] <= 'z') || 
            (url[i] >= '0' && url[i] <= '9') || url[i] == '-' || url[i] == '.' || 
            url[i] == '~' || url[i] == '_' || url[i] == '/') {
            cleanURL[j] = url[i]; //Adding valid characters to clean URL
            j++;
        }
    }
    cleanURL[j] = '\0'; //Setting null character in the end
    
    //Returning sanitized URL
    return cleanURL;
}
 
int main() {
    char url[100];
    printf("Enter a URL: ");
    scanf("%s", url);
    char *sanitizedUrl = urlSanitizer(url); //Calling URL sanitizing function
    printf("The sanitized URL is: %s", sanitizedUrl);
    free(sanitizedUrl); //Freeing memory allocated for clean URL
    return 0;
}