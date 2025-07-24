//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: enthusiastic
#include<stdio.h>
#include<string.h>

// function to remove special characters from URL string
void sanitize_url(char url[]){
    int i, j = 0; // i will iterate the original URL string, j will be used to store the sanitized string
    for(i = 0; url[i] != '\0'; i++){
        if((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z')
            || (url[i] >= '0' && url[i] <= '9') || url[i] == '.' || url[i] == '/' || url[i] == '?' || url[i] == '='){
            url[j++] = url[i];
        }
    }
    url[j] = '\0'; // add null character at the end of sanitized URL string
}

int main(){
    char url[100];

    printf("Enter URL: ");
    scanf("%s", url); // read URL string from user

    printf("Sanitizing URL...\n");

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url); 

    return 0;
}