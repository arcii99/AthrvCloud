//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: curious
#include <stdio.h>
#include <string.h>

void sanitizeUrl(char *url){
    int i, j;
    char temp[strlen(url)]; // temporary variable to store sanitized url
    
    for(i = j = 0; url[i] != '\0'; i++){
        if(url[i] != ' '){ // if character is not whitespace
            temp[j++] = url[i];
            
            // check for invalid characters such as <, > or &
            if(url[i] == '<' || url[i] == '>' || url[i] == '&'){
                printf("\nInvalid URL character(s) detected: %c\n", url[i]);
                printf("URL sanitized: %s\n", temp);
                return;
            }
        }
        // if character is whitespace, replace with '%20'
        else{
            temp[j++] = '%';
            temp[j++] = '2';
            temp[j++] = '0';
        }
    }
    temp[j] = '\0'; // set null character at end of string
    printf("URL sanitized: %s\n", temp); // print sanitized url
}

int main(){
    char url[100]; // maximum url length of 100 characters
    printf("Enter a URL to be sanitized: ");
    fgets(url, 100, stdin);
    url[strcspn(url, "\n")] = '\0'; // remove newline character
    
    printf("Sanitizing URL...\n");
    sanitizeUrl(url);
    
    return 0;
}