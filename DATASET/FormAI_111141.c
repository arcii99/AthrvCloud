//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void urlSanitizer(char *url);

int main(){

    char url[100];
    
    printf("Enter a URL:");
    fgets(url, 100, stdin);         // Taking input from user
    
    urlSanitizer(url);              // Calling urlSanitizer function
    
    printf("\nSanitized URL is: %s\n", url);
    
    return 0;
}

/* Function to sanitize URL*/
void urlSanitizer(char *url){
    
    int i, j = 0;
    char tempStr[100];
    
    for(i=0; i<strlen(url); i++){
        
        if(url[i] == '?')
            break;
        else
            tempStr[i] = url[i];
    }
    tempStr[i] = '\0';
    
    for(i=0; i<strlen(tempStr); i++){
        
        if(tempStr[i] == '/' && tempStr[i+1] == '/')
            continue;
        else
            url[j++] = tempStr[i];
    }
    url[j] = '\0';
    
    for(i=0,j=0; i<strlen(url); i++){
        if(j==0 && url[i] == 'h'){
            url[j++] = url[i];
            continue;
        }
        if(j==1 && url[i] == 't'){
            url[j++] = url[i];
            continue;
        }
        if(j==2 && url[i] == 't'){
            url[j++] = url[i];
            continue;
        }
        if(j==3 && url[i] == 'p'){
            url[j++] = url[i];
            continue;
        }
        if(j==4 && url[i] == 's'){
            url[j++] = url[i];
            break;
            //Considering only "http://" or "https://"
        }
    }
    url[j++] = '/';
    
    for(i=0; i<strlen(tempStr); i++){
        
        if(tempStr[i] == '?' )
            break;
        else if(tempStr[i] == '/')
            continue;
        else if(tempStr[i] == ' ')
            url[j++] = '%';     //Replacing whitespace with '%'
        else
            url[j++] = tempStr[i];
    }
    url[j] = '\0';
}