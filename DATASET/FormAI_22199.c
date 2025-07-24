//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: thoughtful
#include <stdio.h>
#include <string.h>

void sanitize(char* url) {
    if (strstr(url, "http://") != NULL) { // check if url starts with http://
        memmove(url, url+7, strlen(url)); // remove http:// from url
    }
    
    for (int i = 0; i < strlen(url); i++) {
        if (url[i] == '%') { // check for % symbol in url
            if (i+2 >= strlen(url)) { // check if there is enough room for two hex digits after %
                continue;
            }
            if ((url[i+1] >= '0' && url[i+1] <= '9') || (url[i+1] >= 'a' && url[i+1] <= 'f') || (url[i+1] >= 'A' && url[i+1] <= 'F')) { // check if next character is a valid hex digit
                if ((url[i+2] >= '0' && url[i+2] <= '9') || (url[i+2] >= 'a' && url[i+2] <= 'f') || (url[i+2] >= 'A' && url[i+2] <= 'F')) { // check if the character after next is a valid hex digit
                    memmove(url+i, url+i+3, strlen(url)-i-2); // remove % and the two hex digits from url
                }
            }
        }
    }
}

int main() {
    char url[100] = "http://www.example.com/index.html?a=b%c3%a9%e4%b8%8d"; // example url with encoded characters
    
    printf("Original url: %s\n", url);
    
    sanitize(url);
    
    printf("Sanitized url: %s\n", url);
    
    return 0;
}