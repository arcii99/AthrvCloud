//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: medieval
#include<stdio.h>
#include<string.h>

int main(){

    char url[100];
    int i, j = 0;
    
    printf("Good Sir/Madam, please enter your URL: ");
    scanf("%s",url);
    
    char sanitizedUrl[100];
    
    for(i = 0; i < strlen(url); i++){
        
        if(url[i] == '<' || url[i] == '>'){
            printf("Sorry, Good Sir/ Madam. Such characters are not permitted in URLs!");
            return 0;
        }
        else if(url[i] == '/' && url[i+1] == '/'){
            i++;
            sanitizedUrl[j] = '/';
            j++;
            sanitizedUrl[j] = '/';
            j++;
        }
        else{
            sanitizedUrl[j] = url[i];
            j++;
        }
    }
    
    sanitizedUrl[j] = '\0';
    
    printf("The sanitized URL is: %s", sanitizedUrl);

    return 0;
}