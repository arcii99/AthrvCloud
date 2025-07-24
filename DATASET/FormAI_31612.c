//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: mathematical
#include <stdio.h>
#include <string.h>

#define MAX_URL_LENGTH 1000

int main() {
    char url[MAX_URL_LENGTH], sanitizedUrl[MAX_URL_LENGTH];
    int j = 0;

    printf("Enter a URL: ");
    scanf("%s", url);

    printf("Sanitizing...\n");
    
    //Mathematical approach to sanitize URL
    for(int i = 0; i < strlen(url); i++) {
        if(url[i] >= 'a' && url[i] <= 'z') { //If a lowercase letter is found
            sanitizedUrl[j] = url[i] - ('a' - 'A'); //Convert it to uppercase
            j++;
        }
        else if(url[i] >= 'A' && url[i] <= 'Z' || url[i] >= '0' && url[i] <= '9') { //If uppercase letter or number is found
            sanitizedUrl[j] = url[i];
            j++;
        }
        else if(url[i] == ':' && url[i+1] == '/' && url[i+2] == '/') { //If the URL begins with "http://" or "https://"
            sanitizedUrl[j] = url[i];
            sanitizedUrl[j+1] = url[i+1];
            sanitizedUrl[j+2] = url[i+2];
            j+=3;
            i+=2;
        }
    }
    sanitizedUrl[j] = '\0'; //Null terminate sanitized URL

    printf("The sanitized URL is: %s", sanitizedUrl);

    return 0;
}