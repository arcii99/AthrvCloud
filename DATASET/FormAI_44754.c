//FormAI DATASET v1.0 Category: Compression algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void compress(char *input, char *output) {
    char buffer[8] = {'\0'};
    int buffer_index = 0;
    int num_bits_written = 0;
    int compressed_index = 0;
    char compressed[MAX_SIZE] = {'\0'};
    int input_length = strlen(input);
    for (int i = 0; i < input_length; i++) {
        int c = input[i];
        for (int j = 7; j >= 0; j--) {
            if ((c >> j) & 1) {
                buffer[buffer_index] = '1';
            } else {
                buffer[buffer_index] = '0';
            }
            buffer_index++;
            if (buffer_index == 8) {
                compressed[compressed_index] = strtol(buffer, NULL, 2);
                compressed_index++;
                buffer_index = 0;
                num_bits_written += 8;
                if (num_bits_written % 512 == 0 && compressed_index < MAX_SIZE - 1) {
                    compressed[compressed_index] = '\n';
                    compressed_index++;
                }
            }
        }
    }
    if (buffer_index > 0) {
        for (int j = buffer_index; j < 8; j++) {
            buffer[j] = '0';
        }
        compressed[compressed_index] = strtol(buffer, NULL, 2);
        compressed_index++;
        num_bits_written += buffer_index;
    }
    output = compressed;
    printf("Original length: %d\n", input_length);
    printf("Compressed length: %d\n", compressed_index);
    printf("Compression ratio: %f\n", (float) input_length / compressed_index);
}

int main() {
    char *input = "This is a sentence that will be compressed using a unique compression algorithm.";
    char *output;
    compress(input, output);
    printf("Compressed string:\n%s\n", output);
    return 0;
}