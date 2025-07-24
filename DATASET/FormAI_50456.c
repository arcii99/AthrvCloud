//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 100

/**
 * This function removes all the occurrences of characters like =, &, $, # from the URL
 * @param url The URL to be sanitized
 * @return The sanitized URL
 */
char* sanitize_url(char* url) {
    char sanitized_url[MAX_URL_LENGTH];
    int i, j;
    bool invalid_char_exists = false;
    
    for(i = 0, j = 0; i < strlen(url); i++) {
        if(url[i] == '=' || url[i] == '&' || url[i] == '$' || url[i] == '#') {
            invalid_char_exists = true;
        } else {
            sanitized_url[j++] = url[i];
        }
    }
    sanitized_url[j] = '\0';
    
    if(invalid_char_exists) {
        printf("Invalid characters detected and removed from the URL.\n");
        printf("Old URL: %s\n", url);
        printf("New URL: %s\n", sanitized_url);
    } else {
        printf("No invalid characters found in the URL.\n");
    }
    
    return strdup(sanitized_url);
}

int main() {
    char url[MAX_URL_LENGTH];
    char* sanitized_url;
    
    printf("Enter the URL to be sanitized (maximum %d characters):\n", MAX_URL_LENGTH);
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = 0; // removes the newline character from the URL
    
    sanitized_url = sanitize_url(url);
    
    printf("Sanitized URL: %s\n", sanitized_url);
    
    free(sanitized_url);
    
    return 0;
}