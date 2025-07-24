//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: energetic
#include <stdio.h>
#include <string.h>

// Declare the function that will sanitize the URL
void sanitizeUrl(char* url);

// Main function
int main(void) {

    // Declare a char array to store the URL
    char url[100];

    // Prompt the user to input a URL
    printf("Enter a URL: ");
    scanf("%s", url);
        
    // Sanitize the URL
    sanitizeUrl(url);

    // Print the sanitized URL
    printf("The sanitized URL is: %s\n", url);

    return 0;
}

// Define the function that will sanitize the URL
void sanitizeUrl(char* url) {

    // If the URL starts with http:// or https://, remove it
    if (strstr(url, "http://") != NULL || strstr(url, "https://") != NULL) {
        memmove(url, url+strlen("http://"), strlen(url)-strlen("http://")+1);
    }

    // If the URL ends with a backslash, remove it
    if (url[strlen(url)-1] == '/') {
        url[strlen(url)-1] = '\0';
    }

    // If the URL contains any spaces, remove them
    char* ptr = url;
    while (*ptr != '\0') {
        if (*ptr == ' ') {
            memmove(ptr, ptr+1, strlen(ptr));
        } else {
            ptr++;
        }
    }
}