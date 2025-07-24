//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
    
    char url[100];
    printf("Please enter a URL to sanitize: ");
    scanf("%s", url);
    printf("\nSanitizing: %s", url);
    // Begin the sanitization process
    char sanitized_url[100];
    int sanitized_index = 0;
    for (int i = 0; i < strlen(url); i++) {
        char current_char = url[i];
        // If the character is not a space, add it to the sanitized URL
        if (current_char != ' ') {
            sanitized_url[sanitized_index] = current_char;
            sanitized_index++;
        }
        // If the character is a space, replace it with a hyphen in the sanitized URL
        else {
            sanitized_url[sanitized_index] = '-';
            sanitized_index++;
        }
    }
    printf("\nSanitized URL: %s", sanitized_url);
    return 0;
}