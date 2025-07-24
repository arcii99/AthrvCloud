//FormAI DATASET v1.0 Category: HTML beautifier ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000000

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Invalid Input.\nUsage: %s inputfile.html\n", argv[0]); // Error handling when user does not input the correct number of arguments
        return EXIT_FAILURE;
    }

    FILE* input_file = fopen(argv[1], "r"); // Open the input file
    if(input_file == NULL) {
        printf("File failed to open.\n");
        return EXIT_FAILURE;
    }

    char *buffer = (char *)malloc(BUFFER_SIZE * sizeof(char)); // Allocate memory for the buffer
    if(buffer == NULL) {
        printf("Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    char *output_buffer = (char *)malloc(BUFFER_SIZE * sizeof(char)); // Allocate memory for the output buffer
    if(output_buffer == NULL) {
        printf("Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    memset(buffer, '\0', BUFFER_SIZE); // Initialize all buffer elements to null character
    memset(output_buffer, '\0', BUFFER_SIZE); // Initialize all output buffer elements to null character

    fread(buffer, sizeof(char), BUFFER_SIZE, input_file); // Read input file into buffer

    fclose(input_file); // Close input file

    int in_tag = 0, i = 0, j = 0, k = 0;
    char current_char = '\0', next_char = '\0';

    while(buffer[i] != '\0') { // Loop through the buffer until null character is found
        current_char = buffer[i];
        next_char = buffer[i+1];

        if(current_char == '<' && next_char != '/') { // Check if character is a tag opening
            in_tag = 1;
        }

        if(in_tag) { // Check if inside a tag
            output_buffer[j++] = current_char; // Add current character to output buffer
        } else {
            if(current_char == '>') { // Check if character is a tag closing
                output_buffer[j++] = current_char; // Add current character to output buffer
                output_buffer[j++] = '\n'; // Add newline character to output buffer
                for(k = 0; k < i/2; k++) { // Add tabs for indentation
                    output_buffer[j++] = '\t';
                }
            } else {
                output_buffer[j++] = current_char; // Add current character to output buffer
            }
        }

        if(current_char == '>' && next_char == '/') { // Check if character is a self-closing tag
            output_buffer[j++] = current_char; // Add current character to output buffer
            output_buffer[j++] = next_char; // Add next character to output buffer
            output_buffer[j++] = '\n'; // Add newline character to output buffer
            for(k = 0; k < i/2; k++) { // Add tabs for indentation
                output_buffer[j++] = '\t';
            }
            i++; // Skip next character
        }

        if(current_char == '>' && next_char != '/') { // Check if character is a tag closing
            in_tag = 0;
        }

        i++; // Increment character index
    }

    FILE* output_file = fopen("output.html", "w"); // Open the output file
    if(output_file == NULL) {
        printf("File failed to open.\n");
        return EXIT_FAILURE;
    }

    fwrite(output_buffer, sizeof(char), strlen(output_buffer), output_file); // Write output buffer to output file

    fclose(output_file); // Close output file

    free(buffer); // Deallocate buffer memory
    free(output_buffer); // Deallocate output buffer memory

    return EXIT_SUCCESS;
}