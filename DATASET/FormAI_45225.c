//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitizeUrl(char *url) {
    char *invalid = "<>|\"\'";
    char *newUrl = (char *) malloc(strlen(url) * sizeof(char));
    int j = 0;
    for(int i = 0; i < strlen(url); i++) {
        // check if current character is in invalid characters list
        if(strchr(invalid, url[i]) == NULL) {
            // current character is valid, add to new URL
            newUrl[j++] = url[i];
        }
    }
    // add null terminator to new URL
    newUrl[j] = '\0';
    // copy new URL back to original URL
    strcpy(url, newUrl);
}

int main() {
    // get URL from user
    char url[100];
    printf("Please enter a URL: ");
    scanf("%s", url);
    // sanitize URL
    sanitizeUrl(url);
    // print sanitized URL
    printf("Sanitized URL: %s\n", url);
    return 0;
}