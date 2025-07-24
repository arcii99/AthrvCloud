//FormAI DATASET v1.0 Category: Browser Plugin ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Define constant for maximum length of URL string
#define MAX_URL_LENGTH 1024

/* Function to check if a string is a valid URL */
bool is_valid_url(char* url) {
    // Check if string starts with "http://" or "https://"
    if (strncmp(url, "http://", 7) == 0 || strncmp(url, "https://", 8) == 0) {
        // Check if string contains only valid characters
        for (int i = 0; i < strlen(url); i++) {
            if (!isalnum(url[i]) && url[i] != '.' && url[i] != '/' && url[i] != '-' && url[i] != '_') {
                return false;
            }
        }
        return true;
    }
    return false;
}

/* Browser plugin function to open a new tab with a given URL */
void open_new_tab(char* url) {
    if (!is_valid_url(url)) {
        printf("Error: Invalid URL\n");
        return;
    }

    // Allocate memory for new tab
    char* new_tab = (char*) malloc(MAX_URL_LENGTH * sizeof(char));
    strcpy(new_tab, url);

    // Print message to confirm new tab creation
    printf("New tab opened with URL: %s\n", new_tab);

    // Free memory
    free(new_tab);
}

/* Main function to test browser plugin */
int main() {
    // Test opening new tab with valid URL
    open_new_tab("https://www.google.com");

    // Test opening new tab with invalid URL
    open_new_tab("random text");

    return 0;
}