//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sanitize(char url[]){
    int i=0, j=0;
    char new_url[strlen(url)+1]; // Create a new string to store the sanitized url
    
    while(url[i]){ // Loop through the string
        if(isalpha(url[i]) || isdigit(url[i]) || url[i]=='/' || url[i]=='.' || url[i]=='-' || url[i]=='_' || url[i]=='~'){
            new_url[j] = url[i]; // If the character is allowed, add it to the new string
            j++;
        }
        else{
            char hex[3]; // If not allowed, convert to hex and add to new string
            sprintf(hex, "%02X", url[i]);
            new_url[j] = '%'; // Add the percent sign
            new_url[j+1] = hex[0]; // Add the first hex value
            new_url[j+2] = hex[1]; // Add the second hex value
            j+=3;
        }
        i++;
    }
    new_url[j] = '\0'; // Add a null terminator to the end of the new string
    strcpy(url, new_url); // Copy the new sanitized url over the original url
}

int main(){
    char url[200];
    
    printf("Enter a URL to sanitize: ");
    fgets(url, 200, stdin);
    url[strcspn(url, "\n")] = '\0'; // Remove newline character from input
    
    sanitize(url);
    
    printf("Sanitized URL: %s\n", url);
    
    return 0;
}