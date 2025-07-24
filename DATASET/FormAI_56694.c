//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: configurable
#include<stdio.h>
#include<string.h>

#define MAX_URL_LENGTH 100   // Maximum length of URL allowed

void sanitize(char* url){
    char temp_url[MAX_URL_LENGTH];      //Temporary buffer to store URL

    char* p1 = strstr(url, "://");      //Find scheme
    if(p1 == NULL) return;              //Invalid URL
    p1+=3;
    char* p2 = strchr(p1, '/');         //Find host
    if(p2 == NULL) return;              //Invalid URL
    *p2 = '\0';                         //Terminate host
    char* p3 = strchr(p1, ':');         //Find port
    int port;
    if(p3 != NULL && p3 < p2){
        *p3 = '\0';                     //Terminate port
        port = atoi(p3+1);
    } 
    else port = 80;                     //Default port is 80

    sprintf(temp_url, "%s:%d%s", p1, port, p2);
    strcpy(url, temp_url);              //Copy sanitized URL back to original URL
}

int main(){
    char url[MAX_URL_LENGTH];

    printf("Enter URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = '\0';     //Remove trailing newline from input
    
    sanitize(url);                      //Sanitize URL

    printf("Sanitized URL: %s\n", url);

    return 0;
}