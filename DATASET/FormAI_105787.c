//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: cheerful
#include <stdio.h>
#include <string.h>

void sanitize(char *url) {
    char temp[strlen(url)]; // allocate space for temporary string
    
    strcpy(temp, url); // make a copy of the original URL
    
    int i, j = 0;
    for (i = 0; i < strlen(temp); i++) {
        if (temp[i] == ' ') { // replace spaces with %20
            url[j++] = '%';
            url[j++] = '2';
            url[j++] = '0';
        } else if (temp[i] != '\r' && temp[i] != '\n') { // ignore newline characters
            url[j++] = temp[i];
        }
    }
    url[j] = '\0'; // add null terminator after last character
}

int main() {
    char url[1000];
    
    printf("Welcome to the URL Sanitizer!\n\n");
    printf("Enter a URL to sanitize:\n");
    fgets(url, sizeof(url), stdin);
    
    printf("\nSanitizing URL...\n\n");
    
    sanitize(url);
    
    printf("Sanitized URL: %s\n", url);
    
    return 0;
}