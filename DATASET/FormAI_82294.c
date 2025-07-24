//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: imaginative
#include<stdio.h>
#include<string.h>

//function to sanitize the url
void sanitizeUrl(char *url) {
    char *sanitizedUrl = malloc(strlen(url));       //create allocated memory for sanitized url
    int j = 0;
    int doubleSlashFlag = 0;         //flag to check for double backslash
    int hostFlag = 0;                //flag to check for host name
    for(int i=0; i<strlen(url); i++) {
        if(url[i] == ':') {         //remove port number
            while(url[i] != '/') {
                i++;
            }
        }
        if(url[i] == '/') {         //add a single forward slash
            if(hostFlag == 0) {
                hostFlag = 1;
                sanitizedUrl[j] = url[i];
                j++;
            }
            if(hostFlag == 1 && doubleSlashFlag == 0) {
                doubleSlashFlag = 1;
                sanitizedUrl[j] = '/';
                j++;
            }
            continue;
        }
        if(url[i] == '?' || url[i] == '#') {             //remove query and fragment
            break;
        }
        if(doubleSlashFlag == 1 && url[i] == '/') {      //remove extra forward slash
            continue;
        }
        sanitizedUrl[j] = url[i];           //copy character to sanitized url
        j++;
    }
    sanitizedUrl[j] = '\0';     //add null terminator at end
    printf("Sanitized URL: %s", sanitizedUrl);     //print the sanitized url
}

int main() {
    char url[100];
    printf("Enter a URL to sanitize: ");
    fgets(url, 100, stdin);        //get user input
    sanitizeUrl(url);       //call function to sanitize url
    return 0;
}