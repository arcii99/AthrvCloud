//FormAI DATASET v1.0 Category: String manipulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100 // Maximum string length

void deleteDuplicates(char *str);

int main() {
    // Create and initialize the original string
    char str[MAX_LEN] = "Jabberwocky was a poem written by Lewis Carroll";
    
    // Print the original string
    printf("Original string:\n%s\n\n", str);
    
    // Call the function to delete duplicates and print the modified string
    deleteDuplicates(str);
    printf("Modified string:\n%s\n", str);
    
    return 0;
}

// Function to delete duplicates in a C string
void deleteDuplicates(char *str) {
    // Create a boolean array to keep track of each character in the string
    int charSet[256] = {0}; // All elements initialized to 0
    
    // Get the length of the string
    int len = strlen(str);
    
    // Iterate through each character in the string
    int i, j = 0;
    for (i = 0; i < len; i++) {
        // Get the ASCII value of the current character
        int val = (int) str[i];
        // Check if the character has already been encountered
        if (charSet[val] == 0) {
            // If not, assign it to the current position
            str[j] = str[i];
            // Mark the character as encountered
            charSet[val] = 1;
            // Move to the next position in the string
            j++;
        }
    }
    // Add the null terminating character to the end of the modified string
    str[j] = '\0';
}