//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* urlSanitizer(char *url) {
    int len = strlen(url);
    int newlen = 0;
    for(int i = 0; i < len; i++) {
        if(isalnum(url[i]) || url[i] == '.' || url[i] == '/' || url[i] == '-')
            newlen++;
    }
    char *newurl = malloc(sizeof(char) * (newlen+1));
    if (newurl == NULL) {
        printf("Error: Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    newlen = 0;
    for(int j = 0; j < len; j++) {     
        if(isalnum(url[j]) || url[j] == '.' || url[j] == '/' || url[j] == '-') {
            newurl[newlen] = url[j];
            newlen++;
        }
    }
    newurl[newlen] = '\0';
    return newurl;
}

int main() {
    char myurl[100] = "h@ttps://en*wikipedia. o_r_g//wiki/C_(programming_language)";
    printf("Original URL: %s\n", myurl);
    char *cleanurl = urlSanitizer(myurl);
    printf("Sanitized URL: %s\n", cleanurl);
    free(cleanurl);
}