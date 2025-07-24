//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: dynamic
#include <stdio.h>
#include <string.h>

// function to sanitize a URL
char* sanitize_url(char* url) {
    char sanitized_url[1000] = "";
    int n = strlen(url);
    
    // loop through each character of the URL
    for (int i = 0; i < n; i++) {
        if (url[i] == ' ') {
            strcat(sanitized_url, "%20"); // replace space with %20
        } else if (url[i] < 33 || url[i] > 126) {
            char ascii[5];
            sprintf(ascii, "%%%02X", url[i]); // convert non-alphanumeric characters to %XX format
            strcat(sanitized_url, ascii);
        } else {
            char c[2];
            c[0] = url[i];
            c[1] = '\0';
            strcat(sanitized_url, c); // copy all other characters as is
        }
    }
    
    return sanitized_url;
}

int main() {
    char url[1000];
    printf("Enter a URL to sanitize: ");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = '\0'; // remove newline character at end of input
    
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    
    return 0;
}