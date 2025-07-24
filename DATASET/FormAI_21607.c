//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize URL
char* sanitize_url(char* url) {
    char* sanitized_url = malloc(strlen(url)+1); // allocate memory for sanitized URL
    int i, j=0;
    for(i=0; i<strlen(url); i++) {
        if(isalnum(url[i])) { // check if character is alpha-numeric
            sanitized_url[j] = url[i];
            j++;
        } else if(url[i] == '.') { // check if character is a period
            if(j == 0 || sanitized_url[j-1] == '-') { // if period is the first character or follows a hyphen, skip
                continue;
            } else {
                sanitized_url[j] = url[i];
                j++;
            }
        } else if(url[i] == '/') { // check if character is a forward slash
            if(j == 0 || sanitized_url[j-1] == '-') { // if forward slash is the first character or follows a hyphen, skip
                continue;
            } else {
                sanitized_url[j] = '-';
                j++;
            }
        }
    }
    sanitized_url[j] = '\0'; // add null terminator to end of sanitized URL
    return sanitized_url;
}

int main() {
    char* url = "https://www.example.com/my-page.html";
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}