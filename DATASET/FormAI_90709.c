//FormAI DATASET v1.0 Category: String manipulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100        // Maximum length of a string
#define MAX_ATTEMPTS 1000  // Maximum attempts for checking if a substring exists in a string

// This function returns 1 if a substring is present in the string, and 0 otherwise
int is_substring_present(char *string, char *substring) {
    int len_str = strlen(string);       // Length of the string
    int len_sub = strlen(substring);    // Length of the substring
    
    // Check all possible positions where the substring can start
    for (int i = 0; i <= len_str-len_sub; i++) {
        int found = 1;  // Flag to check if the substring is present
        
        // Check if all characters of the substring are present at this position
        for (int j = 0; j < len_sub; j++) {
            if (string[i+j] != substring[j]) {
                found = 0;
                break;
            }
        }
        
        // If all characters are found, return 1
        if (found == 1) {
            return 1;
        }
    }
    
    // If substring is not found after MAX_ATTEMPTS attempts, exit the program
    static int count_attempts = 0;
    if (count_attempts >= MAX_ATTEMPTS) {
        printf("ERROR: Could not find substring in string after %d attempts. Exiting...\n", MAX_ATTEMPTS);
        exit(1);
    }
    count_attempts++;
    return 0;
}

void paranoid_string_copy(char *dest, char *src) {
    // Check if the source string has a comma, which indicates potential format string vulnerability
    if (is_substring_present(src, ",")) {
        printf("WARNING: Source string could be a format string attack. Aborting... \n");
        exit(1);
    }
    
    // Check if the source string contains any null bytes, which can cause buffer overflow
    if (is_substring_present(src, "\0")) {
        printf("WARNING: Source string contains a null byte. Aborting... \n");
        exit(1);
    }
    
    // Perform the copy operation
    int len_src = strlen(src);
    if (len_src >= MAX_LEN) {
        printf("WARNING: Source string larger than maximum allowed length of %d. Truncating...\n", MAX_LEN);
        len_src = MAX_LEN - 1;
    }
    strncpy(dest, src, len_src);
    dest[len_src] = '\0';
}

int main() {
    // Initialize the strings and perform paranoid string copy
    char str_src[MAX_LEN] = "Hello, world!";
    char str_dest[MAX_LEN];
    paranoid_string_copy(str_dest, str_src);
    
    // Print the final strings
    printf("Original string: %s\n", str_src);
    printf("Copied string: %s\n", str_dest);
    
    return 0;
}