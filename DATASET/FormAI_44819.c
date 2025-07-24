//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: real-life
#include <stdio.h>
#include <string.h>

/*
Function to remove all non-alphanumeric characters from a given URL string
*/
void sanitizeURL(char *url) {
    int i, j;
    int len = strlen(url);

    for(i = 0, j = 0; i < len; i++) {
        if(isalnum(url[i])) {
            url[j++] = url[i];
        }
    }
    url[j] = '\0';  // Add a null terminator to the end of the sanitized URL
}

/*
Main function to test the URL sanitizer
*/
int main() {
    char url[100];

    // Get the URL as input from the user
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);

    // Sanitize the URL and print the sanitized version
    sanitizeURL(url);
    printf("Sanitized URL: %s\n", url);

    return 0;
}