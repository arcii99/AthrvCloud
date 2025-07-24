//FormAI DATASET v1.0 Category: Compression algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main function that performs compression
void compress(char* input_string) {

    int len = strlen(input_string);
  
    // Creating an array with the same size as the input string
    char* compressed_string = (char*)malloc(sizeof(char) * (len + 1));
  
    // Initializing the compressed string with the first character of the input string
    compressed_string[0] = input_string[0];
    int count = 1;
    int j = 0;
  
    // Iterating over the input string and compressing it
    for (int i = 1; i < len; i++) {
        if (input_string[i] == input_string[i - 1]) {
            count++; // If the current character is the same as the previous one, increase the count
        } else {
            compressed_string[++j] = count + '0'; // Write the count to the output string
            compressed_string[++j] = input_string[i];
            count = 1; // Reset count to prepare for the next character
        }
    }
  
    // Writing the last count and character to the output string
    compressed_string[++j] = count + '0';
    compressed_string[++j] = '\0';
  
    // Printing the compressed string
    printf("Original String: %s\n", input_string);
    printf("Compressed String: %s\n", compressed_string);
}

// Driver function
int main() {
    char input_string[] = "aaabbccdd";
    compress(input_string);
    return 0;
}