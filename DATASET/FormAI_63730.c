//FormAI DATASET v1.0 Category: Compression algorithms ; Style: creative
/* 
   A creative C compression algorithm that works by converting all
   alphanumeric characters to their corresponding ASCII codes.
   
   Here, we use the following compression rules:
   * If a block of characters consists entirely of digits, they are truncated
     to the first two digits and the remaining digits are discarded.
   * If a block of characters consists entirely of letters (in either case),
     they are replaced by their corresponding ASCII codes.
   * All other characters are left as-is.
   
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to compress a string
void compress(char* buffer) {
    // Pointers to the start and end of each block of characters
    char *block_start = buffer;
    char *current = buffer;
    
    // Loop through each character in the string
    while (*current) {
        // If the current character is the same as the previous one, continue
        if (current > buffer && *current == *(current-1)) {
            current++;
            continue;
        }
        
        // Check if we have a block of digits
        if (isdigit(*current)) {
            // Truncate to the first two digits
            *block_start++ = *current++;
            if (isdigit(*current)) {
                *block_start++ = *current++;
            }
            // Discard the remaining digits
            while (isdigit(*current)) {
                current++;
            }
        }
        // Check if we have a block of letters
        else if (isalpha(*current)) {
            // Replace with ASCII codes
            while (isalpha(*current)) {
                *block_start++ = (char) ((int) *current++);
            }
        }
        // All other characters are left as-is
        else {
            *block_start++ = *current++;
        }
    }
    // Terminate the compressed string
    *block_start = '\0';
}

int main() {
    char input[100];
    char compressed[100];
    printf("Enter a string to compress: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character from input
    
    printf("Input string: %s\n", input);
    
    // Compress the string
    strcpy(compressed, input);
    compress(compressed);
    
    printf("Compressed string: %s\n", compressed);
    
    return 0;
}