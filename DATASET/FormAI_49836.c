//FormAI DATASET v1.0 Category: Compression algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
*   Introducing the LZ77 Algorithm Implementation in C
*/

// Define the size of the sliding window and the buffer
#define WINDOW_SIZE 10
#define BUFFER_SIZE 20

void lz77Compress(char *input, char *output) {
    int length = strlen(input); // Get the length of the input string
    int pos = 0; // Initialize the position of the input pointer
    int i, j = 0; // Plain counters
    while(pos < length) { // While we have not yet read the entire input string
        int start = (pos < WINDOW_SIZE) ? 0 : pos - WINDOW_SIZE; // Calculate the starting position
        int end = (pos + BUFFER_SIZE < length) ? pos + BUFFER_SIZE : length; // Calculate the ending position

        int match_length = 0; // Initialize the length of the match
        int match_pos = 0; // Initialize the position of the match
        for(i = start; i < pos; i++) { // Iterate through the sliding window
            for(j = 0; pos + j < end; j++) { // Iterate through the buffer
                if(input[i+j] != input[pos+j]) { // If the characters do not match
                    break;
                }
            }
            if(j > match_length) { // If our match is better than the previous best match
                match_length = j; // Update the length of the match
                match_pos = i; // Update the position of the match
            }
        }

        if(match_length > 0) { // If we found a match
            output[pos++] = (char) ((match_pos >> 4) & 0xff); // Write the position of the match
            output[pos++] = (char) (((match_pos & 0xf) << 4) | (match_length & 0xf)); // Write the length of the match
        } else { // If we did not find a match
            output[pos++] = input[pos-1]; // Write the current character as a literal
        }
    }
    output[pos] = '\0'; // Terminate the output
}

void lz77Decompress(char *input, char *output) {
    int length = strlen(input); // Get the length of the input string
    int pos = 0; // Initialize the position of the input pointer
    int i = 0, j = 0; // Plain counters
    while(pos < length) { // While we have not yet read the entire input string
        char c = input[pos++]; // Read the next character
        if((c >> 4) == 0x0f) { // If the position is 0xfff (i.e., 1111 1111 1111)
            break; // End the decompression
        }
        int length = (c & 0xf) + 3; // Calculate the length of the match
        int pos = ((c & 0xff) << 4) | ((input[pos] >> 4) & 0xf); // Calculate the position of the match
        for(i = 0; i < length; i++) { // Copy the match to the output string
            output[j++] = output[pos+i];
        }
    }
    output[j] = '\0'; // Terminate the output
}

int main() {
    char input[] = "hello world, hello world, hello world"; // Define the input string
    char compressed[1000]; // Define a buffer for the compressed string
    lz77Compress(input, compressed); // Compress the input string
    printf("Compressed: %s\n", compressed); // Print the compressed string

    char decompressed[1000]; // Define a buffer for the decompressed string
    lz77Decompress(compressed, decompressed); // Decompress the compressed string
    printf("Decompressed: %s\n", decompressed); // Print the decompressed string

    return 0; // Exit the program
}