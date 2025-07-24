//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

// Cyberpunk-style URL sanitizer function
void sanitize(char* url) {
    char* sanitized_url = malloc(strlen(url) + 1); // Allocate memory for the sanitized URL
    
    for (int i = 0; i < strlen(url); i++) {
        // Replace spaces with '%20'
        if (url[i] == ' ') {
            strcat(sanitized_url, "%20");
        } 
        // Remove all characters except for alphanumeric and hyphen characters
        else if ((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9') || url[i] == '-') {
            char* c = malloc(sizeof(char));
            c[0] = url[i];
            strcat(sanitized_url, c);
            free(c);
        }
    }
    
    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);
    
    // Free the memory allocated for the sanitized URL
    free(sanitized_url);
}

int main() {
    char url[256] = "https://www.example.com/a b_c/d-e?f=g+h#i"; // Example URL with spaces and non-alphanumeric characters
    
    printf("Original URL: %s\n", url);
    
    sanitize(url);
    
    return 0;
}