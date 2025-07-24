//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to remove unwanted characters from URL
char *sanitizeURL(char *url) {
    char *cleanURL = (char*)malloc(sizeof(char) * strlen(url)); // creating a new string to store the clean version of the URL
    int j = 0;
    for(int i = 0; i < strlen(url); i++) {
        if((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9') || url[i] == '.' || url[i] == '/' || url[i] == ':' || url[i] == '?' || url[i] == '&' || url[i] == '=') {
            cleanURL[j++] = url[i];
        }
    }
    cleanURL[j] = '\0'; // null terminating the new string
    return cleanURL;
}

int main() {
    char url[100];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);
    char *cleanURL = sanitizeURL(url);
    printf("Clean URL: %s\n", cleanURL);
    free(cleanURL); // freeing the memory allocated for the new string
    
    return 0;
}