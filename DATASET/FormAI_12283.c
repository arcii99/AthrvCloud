//FormAI DATASET v1.0 Category: Compression algorithms ; Style: content
// This compression algorithm converts long strings of the same character
// into a shorter representation of that character followed by a count
//
// For example, the string "aaaaaabbbbccccddddd" could be compressed to "a6b4c4d5"
//
// This implementation uses an array to store the data and does not involve any file I/O

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000 // maximum length of the input string
#define MAX_OUTPUT 2000 // maximum length of the compressed string

void compress(char* input_string, char* output_string);

int main() {
    char input[MAX_LENGTH];
    char output[MAX_OUTPUT];

    printf("Enter a string to compress: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // remove trailing newline character

    compress(input, output);

    printf("Compressed string: %s\n", output);
    return 0;
}

void compress(char* input_string, char* output_string) {
    int input_len = strlen(input_string);
    int output_index = 0;

    for (int i = 0; i < input_len; i++) {
        char current_char = input_string[i];
        int char_count = 1;

        while (i + 1 < input_len && input_string[i+1] == current_char) {
            i++;
            char_count++;
        }

        if (char_count == 1) {
            output_string[output_index++] = current_char;
        } else {
            output_string[output_index++] = current_char;
            output_string[output_index++] = '0' + char_count;
        }
    }

    output_string[output_index] = '\0';
}