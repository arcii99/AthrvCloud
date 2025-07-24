//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char url[1000];
    
    printf("Please enter a URL to sanitize: ");
    scanf("%s", url);

    // Iterate through each char of the URL
    for (int i = 0; i < strlen(url); i++) {

        // Check if the char is a space
        if (url[i] == ' ') {

            // Replace space with %20
            url[i] = '%';
            url[++i] = '2';
            url[++i] = '0';
            
        } else if (!isalnum(url[i]) && url[i] != '/' && url[i] != '.' && url[i] != ':' && url[i] != '-') {

            // Remove any non-alphanumeric, non-/./:/- char
            for (int j = i; j < strlen(url); j++)
                url[j] = url[j+1];
            i--;
            
        } else if (url[i] == '.' || url[i] == '/') {
            
            // Check for .. and //
            if(i != 0 && url[i-1] == '.' && i != (strlen(url) - 1) && url[i+1] == '.')
                i--;
            else if(i != 0 && url[i-1] == '/' && i != (strlen(url) - 1) && url[i+1] == '/')
                i--;
        }
        
    }

    printf("Sanitized URL: %s\n", url);
    return 0;
}