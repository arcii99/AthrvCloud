//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: safe
#include<stdio.h>
#include<string.h>

#define MAX_LEN 256 // Maximum length for input URL

// Sanitize Function
char* sanitize_url(char *url) {
    char new_url[MAX_LEN]; // Initialize new URL string to hold final sanitized URL
    int i, j = 0;

    for(i=0; i<strlen(url); i++) {
        // Check for special characters and remove them
        if(url[i] == '\"' || url[i] == '\'' || url[i] == '(' || url[i] == ')' || url[i] == '<' || url[i] == '>' || url[i] == '[' || url[i] == ']' || url[i] == '{' || url[i] == '}' || url[i] == ';' || url[i] == ':' || url[i] == '\\' || url[i] == '|' || url[i] == ',' || url[i] == '`' || url[i] == '^') {
            continue;
        }
        else {
            new_url[j] = url[i]; // Add character to new URL string
            j++;
        }
    }
    new_url[j] = '\0'; // Add null termination

    return new_url;
}

// Main Function
int main() {
    char url[MAX_LEN], *sanitized_url;

    // Take input URL from user
    printf("Enter URL to be sanitized: ");
    fgets(url, MAX_LEN, stdin);

    // Call sanitize_url function
    sanitized_url = sanitize_url(url);

    // Print final sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}