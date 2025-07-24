//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: funny
#include <stdio.h>
#include <string.h>

void sanitize(char* url){
    int len = strlen(url);
    
    // remove any spaces
    for(int i = 0; i < len; i++){
        if(url[i] == ' '){
            for(int j = i; j < len - 1; j++){
                url[j] = url[j+1];
            }
            i--;
            len--;
        }
    }
    
    // remove any trailing slashes
    if(url[len-1] == '/'){
        url[len-1] = '\0';
        len--;
    }
    
    // ensure http/https protocol is specified
    if(strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0){
        char buffer[len+9];
        snprintf(buffer, len+9, "http://%s", url);
        strcpy(url, buffer);
    }
}

int main(){
    char url[100];
    printf("Enter a URL to sanitize: ");
    fgets(url, 100, stdin);
    sanitize(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}