//FormAI DATASET v1.0 Category: Browser Plugin ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Example of a C Browser Plugin that detects the presence of a specific string on a web page

// Function to detect the presence of a specific string on a web page
bool detect_string(char* page_source, char* search_string) {
    // Loop through each character in the page source
    for (int i = 0; page_source[i] != '\0'; i++) {
        // Check if the search string is present at this position in the page source
        bool found = true;
        for (int j = 0; search_string[j] != '\0'; j++) {
            if (page_source[i+j] != search_string[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            // If the search string is found, return true
            return true;
        }
    }
    // If the search string is not found, return false
    return false;
}

// Entry point
int main() {
    // Some example page source
    char page_source[] = "<html><head><title>Example Page</title></head><body><h1>Hello, World!</h1></body></html>";
    // The search string to detect
    char search_string[] = "Hello, World!";
    // Check if the search string is present in the page source
    bool found = detect_string(page_source, search_string);
    // Output the result
    if (found) {
        printf("The search string was found.\n");
    } else {
        printf("The search string was not found.\n");
    }
    // Return success
    return 0;
}