//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#define MAX_URL_LENGTH 100

// Function to sanitize URL by removing special characters
void sanitize_url(char *url){
    int i, j;
    for (i = 0, j = 0; url[i]; i++) {
        // Check for alphanumeric characters or '/'
        if (isalnum(url[i]) || url[i] == '/') {
            url[j++] = url[i];
        }
        // Convert spaces to '%20'
        if (url[i] == ' ') {
            url[j++] = '%';
            url[j++] = '2';
            url[j++] = '0';
        }
    }
    url[j] = '\0'; // Add null character to end the string
}

// Main function to get user input and call the sanitize_url function
int main(){
    char url[MAX_URL_LENGTH];
    printf("Enter the URL: ");
    fgets(url, MAX_URL_LENGTH, stdin); // Get input from user
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}