//FormAI DATASET v1.0 Category: Compression algorithms ; Style: lively
/* Welcome to the world of C Compression, where we make bits smaller but keep them mighty! */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000  // Maximum length of the input string

int main() {
    
    char input[MAX_LENGTH];  // Stores the input string
    char compressed[MAX_LENGTH];  // Stores the compressed string
    char ch, prev_ch = '\0';  // Variables to hold the current and previous characters
    int count = 0, index = 0;  // Count variable holds the character count, index variable holds the compressed string index
    
    printf("Welcome to C Compression!\n\n");
    printf("Enter a string to compress: ");
    fgets(input, MAX_LENGTH, stdin);  // Get input from user
    
    printf("\nOriginal string: %s\n", input);
    
    // Loop through each character in the input string
    for (int i = 0; input[i] != '\0'; i++) {
        ch = input[i];
        
        // If the current character is the same as the previous character
        if (ch == prev_ch) {
            count++;  // Increment the count variable
        } else {
            // If the count variable is greater than 0, add the compressed version to the compressed string
            if (count > 0) {
                compressed[index++] = count + '0';  // Convert the count to a character and add it to the compressed string
            }
            
            compressed[index++] = ch;  // Add the current character to the compressed string
            prev_ch = ch;  // Update the previous character to the current character
            count = 1;  // Reset the count variable to 1
        }
    }
    
    // Add the final count to the compressed string
    if (count > 0) {
        compressed[index++] = count + '0';
    }
    
    compressed[index] = '\0';  // Add the null terminator to the end of the compressed string
    
    printf("\nCompressed string: %s\n", compressed);
    printf("Length of original string: %d\n", strlen(input));
    printf("Length of compressed string: %d\n", strlen(compressed));
    
    // Compare the sizes of the original and compressed strings
    if (strlen(compressed) < strlen(input)) {
        printf("\nCompression successful, the compressed string is smaller than the original!\n");
    } else {
        printf("\nCompression unsuccessful, the compressed string is larger than the original.\n");
    }
    
    return 0;  // Exit the program
}