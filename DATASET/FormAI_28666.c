//FormAI DATASET v1.0 Category: Compression algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE (MAX_INPUT_SIZE / 2)

// Run-length encoding (RLE) compression algorithm
void rle_compress(char* input, char* output) {
    int input_length = strlen(input);
    int output_index = 0;
    char current_char = input[0];
    int count = 1;
    
    // Loop through input string
    for (int i = 1; i < input_length; i++) {
        if (input[i] == current_char) {
            // Same character as before, increase count
            count++;
        } else {
            // New character, write to output
            output[output_index++] = current_char;
            output[output_index++] = count + '0';
            current_char = input[i];
            count = 1;
        }
    }
    
    // Write last character and its count to output
    output[output_index++] = current_char;
    output[output_index++] = count + '0';
    output[output_index] = '\0';
}

// Run-length decoding (RLD) decompression algorithm
void rld_decompress(char* input, char* output) {
    int input_length = strlen(input);
    int output_index = 0;
    
    // Loop through input string
    for (int i = 0; i < input_length; i += 2) {
        char current_char = input[i];
        int count = input[i+1] - '0';
        
        // Repeat character count times and write to output
        for (int j = 0; j < count; j++) {
            output[output_index++] = current_char;
        }
    }
    
    output[output_index] = '\0';
}

int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_OUTPUT_SIZE];
    
    // Get input string from user
    printf("Enter a string to compress:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);
    strtok(input, "\n"); // Remove trailing newline
    
    // Compress input string
    rle_compress(input, output);
    printf("Compressed string: %s\n", output);
    
    // Decompress compressed string
    rld_decompress(output, input);
    printf("Decompressed string: %s\n", input);
    
    return 0;
}