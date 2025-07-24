//FormAI DATASET v1.0 Category: Text Summarizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 2000
#define MAX_OUTPUT_SIZE 1000

int main() {
    // Initialize variables
    char input[MAX_INPUT_SIZE], output[MAX_OUTPUT_SIZE], buffer[MAX_INPUT_SIZE];
    int input_len = 0, output_len = 0, buffer_len = 0, index = 0;

    // Get user input
    printf("Enter the text you want to summarize:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input_len = strlen(input);

    // Loop through each character in the input
    for (int i = 0; i < input_len; i++) {
        // Check if the character is a letter or number and add it to the buffer
        if (isalnum(input[i])) {
            buffer[buffer_len++] = input[i];
        }
        // If the character is a space or punctuation, add the buffer to the output
        else {
            // Check if the buffer is a keyword
            if (strcmp(buffer, "the") == 0 || strcmp(buffer, "and") == 0 || strcmp(buffer, "of") == 0) {
                // If the buffer is a keyword, skip it and clear the buffer
                memset(buffer, 0, buffer_len);
                buffer_len = 0;
            }
            else {
                // If the buffer is not a keyword, add it to the output
                sprintf(output + output_len, "%s ", buffer);
                output_len += buffer_len + 1;
                memset(buffer, 0, buffer_len);
                buffer_len = 0;
            }
            // Add the current character to the output
            output[output_len++] = input[i];
        }
        // Check if the output has reached the maximum length
        if (output_len >= MAX_OUTPUT_SIZE) {
            break;
        }
    }

    // Print the summarized text
    printf("The summarized text is:\n%s", output);
    return 0;
}