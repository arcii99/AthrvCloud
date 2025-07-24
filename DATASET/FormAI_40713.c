//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length of URL
#define MAX_LENGTH 100

// Function to sanitize the URL
void sanitize_url(char url[]) {
    // Replace any occurrences of "http://" with "safe://"
    char* unsafe_protocol = "http://";
    char* safe_protocol = "safe://";
    char* substring = strstr(url, unsafe_protocol);
    if (substring != NULL) {
        memmove(substring + strlen(safe_protocol), substring + strlen(unsafe_protocol), strlen(substring + strlen(unsafe_protocol)) + 1);
        strncpy(substring, safe_protocol, strlen(safe_protocol));
    }
    
    // Replace any occurrences of "../" with ""
    char* unsafe_path = "../";
    char* substring2 = strstr(url, unsafe_path);
    if (substring2 != NULL) {
        memmove(substring2, substring2 + strlen(unsafe_path), strlen(substring2 + strlen(unsafe_path)) + 1);
    }
    
    // Replace any occurrences of "/../" with "/"
    char* unsafe_path2 = "/../";
    char* substring3 = strstr(url, unsafe_path2);
    if (substring3 != NULL) {
        memmove(substring3, substring3 + strlen(unsafe_path2) - 1, strlen(substring3 + strlen(unsafe_path2)) + 1);
    }
}

int main() {
    char url[MAX_LENGTH];
    
    // Get URL from user input
    printf("Enter URL to sanitize:\n");
    fgets(url, MAX_LENGTH, stdin);
    url[strcspn(url, "\n")] = 0; // Remove newline character from user input
    
    // Sanitize the URL
    sanitize_url(url);
    
    // Print out sanitized URL
    printf("Sanitized URL: %s\n", url);
    
    return 0;
}