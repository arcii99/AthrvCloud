//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to sanitize the URL
char* sanitize(char* url) {
    // removing any leading or trailing whitespaces
    url = strdup(url);
    char* end;
    while (isspace(*url)) url++;
    if (*url == 0) // if url is only whitespace
        return "";
    end = url + strlen(url) - 1;
    while (end > url && isspace(*end)) end--;
    *(end+1) = 0;
    
    // adding 'http://' if url does not start with 'http://' or 'https://'
    char* prefix = "http://";
    char* prefix2 = "https://";
    if (strncmp(url, prefix, strlen(prefix)) != 0 && strncmp(url, prefix2, strlen(prefix2)) != 0) {
        char* temp = malloc(strlen(url) + strlen(prefix) + 1);
        strcpy(temp, prefix);
        strcat(temp, url);
        return temp;
    }
    return url;
}

int main() {
    // example usage
    char* url = "  example.com  ";
    printf("Original URL: %s\n", url);
    char* sanitized_url = sanitize(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    
    return 0;
}