//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: romantic
#include <stdio.h>
#include <string.h>

/* This program is like a love letter to your URLs. It will take your URL
   and clean it up, remove any malicious characters and keep it safe and 
   beautiful for you. */

int main()
{
    // First, let me declare my love for your URL.
    char url[100];
    printf("My dearest URL, please let me take care of you. What is your name?\n");
    scanf("%s", url);
    printf("Ah, %s, what a beautiful name for a URL.\n", url);
    
    // Now, let me clean up your URL and make sure it's safe.
    char safe_url[100];
    // Loop through each character of the URL to check for any malicious characters.
    for (int i = 0; i < strlen(url); i++) {
        if (url[i] == '<' || url[i] == '>' || url[i] == '&' || url[i] == '\''
            || url[i] == '\"') {
            safe_url[i] = '_'; // Replace malicious characters with underscores.
        } else {
            safe_url[i] = url[i]; // Keep good characters as is.
        }
    }
    safe_url[strlen(url)] = '\0'; // Terminate the string with a null character.
    
    // I promise to love and care for your URL forever.
    printf("My love, your URL is now clean and safe. Please use it with confidence:\n");
    printf("%s", safe_url);
    
    return 0;
}