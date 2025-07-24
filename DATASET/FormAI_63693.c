//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is alpha-numeric or not
bool isAlphaNumeric(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
        return true;
    }
    return false;
}

// Function to remove any non alpha-numeric characters from the string
void sanitizeURL(char* url){
    int i, j;
    for(i = 0, j = 0; url[i] != '\0'; i++){
        if(isAlphaNumeric(url[i])){
            url[j] = url[i];
            j++;
        }
    }
    url[j] = '\0';
}

int main(){
    char url[100];

    // Get the input from the user
    printf("Enter a URL: ");
    scanf("%s", url);

    // Convert the URL to lowercase
    int i;
    for(i = 0; url[i] != '\0'; i++){
        url[i] = tolower(url[i]);
    }

    // Remove any non alpha-numeric characters from the URL
    sanitizeURL(url);

    // Print the sanitized URL
    printf("The sanitized URL is: %s\n", url);
    
    return 0;
}