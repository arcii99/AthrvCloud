//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

//Function to sanitize urls and remove dangerous codes
void urlSanitizer(char *url) {
    char tempUrl[1000];
    memset(tempUrl, '\0', sizeof(tempUrl)); //clear the tempUrl array
    
    int len = strlen(url);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (url[i] != '<' && url[i] != '>' && url[i] != ';' && url[i] != '\"' && url[i] != '\'' && url[i] != '(' && url[i] != ')' && url[i] != '[' && url[i] != ']' && url[i] != '{' && url[i] != '}') {
            tempUrl[j++] = url[i]; //copy the character into the tempUrl array
        }
    }
    strcpy(url, tempUrl); //copy the sanitized url back into the original url array
}

int main() {
    printf("Welcome to URL Sanitizer!");

    char url[1000];
    printf("\nEnter the URL:");
    fgets(url, sizeof(url), stdin);

    urlSanitizer(url);

    printf("\nThe sanitized URL is: %s", url);
    
    return 0;
}