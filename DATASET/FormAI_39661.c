//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: cheerful
#include <stdio.h>
#include <string.h>

//Function to remove unwanted characters
void sanitizeUrl(char *url){
    char *ptrUrl = url;
    while(*ptrUrl != '\0'){
        //Only letters and digits allowed
        if(!((*ptrUrl >= 'a' && *ptrUrl <= 'z') || (*ptrUrl >= 'A' && *ptrUrl <= 'Z') || (*ptrUrl >= '0' && *ptrUrl <= '9'))){
            *ptrUrl = '-';
        }
        ptrUrl++;
    }
}

int main(){
    char originalUrl[1000], sanitizedUrl[1000];
    printf("Welcome to the URL Sanitizer program!\n\n");
    printf("Please enter your URL: ");
    scanf("%s", originalUrl);
    printf("You entered: %s\n", originalUrl);
    
    strcpy(sanitizedUrl, originalUrl);
    sanitizeUrl(sanitizedUrl);
    
    printf("Your sanitized URL: %s\n", sanitizedUrl);
    printf("\nThank you for using our program!\n");
    return 0;
}