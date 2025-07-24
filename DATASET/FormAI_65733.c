//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to sanitize URL
char *sanitize_url(char *url){
    char *sanitized_url = malloc(1024 * sizeof(char)); // Dynamically allocate memory for the sanitized URL
    int i, j;
    char c;

    // Loop through each character in the URL
    for(i=0, j=0; i<strlen(url); i++){
        c = url[i];

        if(c == ' '){ // Replace spaces with '%20'
            sanitized_url[j++] = '%';
            sanitized_url[j++] = '2';
            sanitized_url[j] = '0';
        }
        else if(c == '<' || c == '>' || c == '"' || c == '{' || c == '}' || c == '|'){ // Remove invalid characters
            continue;
        }
        else{ // Copy valid characters
            sanitized_url[j] = c;
        }

        j++; // Increment sanitized URL index
    }

    sanitized_url[j] = '\0'; // Add string terminator at the end of the sanitized URL
    
    return sanitized_url;
}

// Main function
int main(){
    char url[1024], *sanitized_url;

    printf("Enter URL to sanitize: ");
    gets(url); // Get input URL from user

    sanitized_url = sanitize_url(url); // Sanitize the URL

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url); // Free dynamically allocated memory for the sanitized URL

    return 0;
}