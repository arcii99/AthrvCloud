//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 256

int main()
{
    char url[MAX_URL_LENGTH];
    char sanitizedUrl[MAX_URL_LENGTH];
    printf("Enter URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Check if given URL contains 'http://' or not
    if (strncmp(url, "http://", 7) != 0) 
        strcpy(sanitizedUrl, "http://");
    else 
        strcpy(sanitizedUrl, "");
    
    // Remove the 'http://' part to extract the domain name
    char* domainName = strtok(url, "/");
    domainName = strtok(NULL, "/");
    strcat(sanitizedUrl, domainName);
    
    // Check if there is any query string in the given URL
    char* queryString = strchr(url, '?');
    if (queryString) {
        strcat(sanitizedUrl, "/");
        strcat(sanitizedUrl, queryString);
    }

    printf("Sanitized URL: %s\n", sanitizedUrl);
    return 0;
}