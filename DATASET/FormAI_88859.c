//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program is a unique C URL Sanitizer that takes a URL input from the user and removes any suspicious or malicious characters */
int main()
{
    char url[100];
    printf("Welcome to the Unique C URL Sanitizer!\n");

    printf("Please enter the URL you want to sanitize: ");
    scanf("%s", url);

    int length = strlen(url);
    
    // Check for suspicious characters like quotes, semicolons, question marks, and brackets
    for(int i=0; i<length; i++) {
        if(url[i] == '\"' || url[i] == '\'' || url[i] == ';' || url[i] == '?' || url[i] == '(' || url[i] == ')') {
            printf("Suspicious character detected! URL is not safe.\n");
            exit(0); // Exit the program if a suspicious character is detected
        }
    }

    // Remove any double slashes
    char* double_slash = strstr(url, "//");
    if(double_slash != NULL) {
        char* temp = strdup(double_slash+2); // Create a copy of the string after the double slashes
        strcpy(double_slash, "/"); // Copy a single slash over the double slashes
        strcat(url, temp); // Concatenate the rest of the string back to the URL
        free(temp); // Free the temporary string
    }

    // Remove any trailing slash
    length = strlen(url);
    if(url[length-1] == '/') {
        url[length-1] = '\0'; // Set the last character to null to remove the trailing slash
    }
    
    printf("Sanitized URL: %s\n", url);
    
    return 0;
}