//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sanitizeURL(char *url) {
    int i, j;
    char temp[strlen(url)+1];

    for(i=0, j=0; i<strlen(url); i++) {
        if(isalnum(url[i]) || url[i]=='.' || url[i]=='-' || url[i]=='/') {
            temp[j++] = url[i];
        }
    }
    temp[j] = '\0';

    if(temp[0]=='/') {
        strcpy(url, "http://example.com");
        strcat(url, temp);
    }
    else if(strncmp(temp, "http://", 7) != 0) {
        strcpy(url, "http://");
        strcat(url, temp);
    }
    else {
        strcpy(url, temp);
    }
}

int main() {
    char url[100];

    printf("Enter a URL: ");
    scanf("%s", url);

    sanitizeURL(url);
    printf("Sanitized URL: %s\n", url);

    return 0;
}