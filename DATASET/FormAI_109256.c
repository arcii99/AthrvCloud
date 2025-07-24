//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: modular
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char* sanitizeURL(char* url);

int main(){
    char url[1000]; //Maximum length of a URL is 2000 characters
    printf("Enter URL: ");
    scanf("%s", url);
    printf("Sanitized URL: %s\n", sanitizeURL(url));
    return 0;
}

//Function to sanitize the given URL to ensure that it is safe to use
char* sanitizeURL(char* url){
    //Removing any spaces from the beginning or the end of the URL
    char* sanitized = strdup(url);
    sanitized[strcspn(sanitized, "\n")] = '\0'; //Removing trailing newline character
    char* temp1 = sanitized;
    while(isspace(*temp1)) temp1++;
    char* temp2 = sanitized + strlen(sanitized) - 1;
    while(temp2 > temp1 && isspace(*temp2)) temp2--;
    *(temp2+1) = '\0';

    //Replacing any instances of the string "../" with an empty string
    char* strToFind = "../";
    char* temp3 = sanitized;
    while(temp3 = strstr(temp3, strToFind)){
        strcpy(temp3, temp3+strlen(strToFind));
    }

    //Returning the sanitized URL
    return sanitized;
}