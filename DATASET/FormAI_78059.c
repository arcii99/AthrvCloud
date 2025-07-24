//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to sanitize C URL
void sanitizeURL(char* url){

    char* sanitizedURL = (char*)malloc(strlen(url)+ 1); //Allocate memory for sanitized URL

    int i, j = 0;
    for(i = 0; url[i] != '\0'; i++) {
        if((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9') || url[i] == '.' || url[i] == '/' || url[i] == '-') {
            sanitizedURL[j++] = url[i];  //If the character matches with allowed characters, add it to the sanitized URL
        }
    }
    sanitizedURL[j] = '\0'; 

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitizedURL);

    free(sanitizedURL);   //Free the dynamically allocated memory
}

int main(){

    char url1[] = "http://www.google.com/search?q=sanitizer";
    char url2[] = "https://www.facebook.com/profile.php?id=123456789";
    char url3[] = "ftp://192.168.1.1/files/myfile.txt";
    char url4[] = "http://example.com/about-us/";
    char url5[] = "http://example.com/products/page-1.html";

    sanitizeURL(url1);
    sanitizeURL(url2);
    sanitizeURL(url3);
    sanitizeURL(url4);
    sanitizeURL(url5);

    return 0;
}