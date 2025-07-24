//FormAI DATASET v1.0 Category: Compression algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_CODE_LENGTH 20

typedef struct {
    unsigned int code;
    unsigned int length;
} Code;

// Utility function to check if a code is already present in a code table
int code_in_table(const Code *table, size_t size, const Code *code) {
    for (size_t i = 0; i < size; i++) {
        if (table[i].code == code->code && table[i].length == code->length) {
            return 1;
        }
    }
    return 0;
}

// Compress a string using a simple naive compression algorithm
int compress(const char *in_data, size_t in_size, char *out_data, size_t out_size) {
    Code code_table[256];
    size_t code_count = 0;
    int code_length = 1;
    unsigned int code = 0;

    // Initialize code table with single-character codes
    for (unsigned int i = 0; i < 256; i++) {
        code_table[i].code = i;
        code_table[i].length = 1;
        code_count++;
    }

    // Process input string
    for (size_t i = 0; i < in_size; i++) {
        unsigned int next_char = in_data[i];

        // Look for longest code in table that matches
        for (int len = code_length; len >= 1; len--) {
            unsigned int prefix = code << (len - 1);
            unsigned int mask = (1 << len) - 1;

            for (unsigned int j = 0; j < code_count; j++) {
                if (code_table[j].length == len && (code_table[j].code & mask) == prefix) {
                    // Match found, update code and continue
                    code = (code << len) | (next_char & ((1 << len) - 1));
                    code_length += 1;

                    break;
                }
            }
        }

        // Check if new code needs to be added to table
        if (code_length > MAX_CODE_LENGTH || !code_in_table(code_table, code_count, &(Code){code, code_length})) {
            // Write current code to output stream
            if (out_size < (code_length + 7) / 8) {
                return -1;  // Output buffer full!
            }

            for (int i = code_length - 1; i >= 0; i--) {
                out_data[0] |= ((code >> i) & 1) << (7 - (out_size * 8) - out_data[1]);
                out_data[1]++;

                if (out_data[1] == 8) {
                    out_data += 2;
                    out_size--;
                }
            }

            // Add new code to table
            if (code_count < (1 << MAX_CODE_LENGTH)) {
                code_table[code_count] = (Code){code, code_length};
                code_count++;
            }

            // Reset code to next character
            code = next_char;
            code_length = 1;
        }
    }

    // Write final code to output stream
    if (out_size < (code_length + 7) / 8) {
        return -1;  // Output buffer full!
    }

    for (int i = code_length - 1; i >= 0; i--) {
        out_data[0] |= ((code >> i) & 1) << (7 - (out_size * 8) - out_data[1]);
        out_data[1]++;

        if (out_data[1] == 8) {
            out_data += 2;
            out_size--;
        }
    }

    return (out_data - out_size) - out_data;
}

int main() {
    char input_string[BUFFER_SIZE] = "hello world!";
    char compressed_data[BUFFER_SIZE] = {0};
    char decompressed_string[BUFFER_SIZE] = {0};

    printf("Original length: %lu\nData to compress: %s\n", strlen(input_string), input_string);

    int compressed_size = compress(input_string, strlen(input_string), compressed_data, BUFFER_SIZE);
    printf("Compressed length: %d\n", compressed_size);

    // TODO: Implement decompression
    //int decompressed_size = decompress(compressed_data, compressed_size, decompressed_string, BUFFER_SIZE);
    //printf("Decompressed length: %d\nDecompressed string: %s\n", decompressed_size, decompressed_string);

    return 0;
}