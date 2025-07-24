//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//function to sanitize URL
void sanitize_url(char *url) {
    int len = strlen(url);
    char sanitized_url[len];
    int index = 0;

    for(int i=0; i<len; i++) {
        if(isalnum(url[i])) { //if the character is alphanumeric
            sanitized_url[index++] = url[i];
        }
        else if(url[i] == ':' || url[i] == '/' || url[i] == '.') { //if the character is a colon, forward slash or dot
            sanitized_url[index++] = url[i];
        }
    }
    //add terminating null character
    sanitized_url[index] = '\0';

    //copy the sanitized URL to original URL
    strcpy(url, sanitized_url);
}

int main() {
    char url[100];
    printf("Enter a URL: ");
    scanf("%s", url);

    //sanitize the URL
    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);
    return 0;
}