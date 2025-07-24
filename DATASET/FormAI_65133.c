//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Constants for compression algorithm
#define MAX_CODE_LENGTH 12
#define MAX_TABLE_SIZE 4096

// Struct for dictionary used in compression
struct dictionary {
    int code;
    char sequence[MAX_CODE_LENGTH];
};

// Function to initialize dictionary with single-character codes
void initializeDictionary(struct dictionary table[]) {
    for (int i = 0; i < 256; i++) {
        table[i].code = i;
        sprintf(table[i].sequence, "%c", i);
    }
}

// Function to search dictionary for given sequence and return its code
int searchDictionary(struct dictionary table[], char sequence[]) {
    for (int i = 0; i < MAX_TABLE_SIZE; i++) {
        if (strcmp(table[i].sequence, sequence) == 0) {
            return table[i].code;
        }
    }
    return -1;
}

// Function to add new sequence to dictionary with next available code
void addToDictionary(struct dictionary table[], int code, char sequence[]) {
    strcpy(table[code].sequence, sequence);
    table[code].code = code;
}

// Main compression function using LZW algorithm
unsigned char* compress(unsigned char* input, int length, int* compressed_length) {
    // Initialize dictionary
    struct dictionary table[MAX_TABLE_SIZE];
    initializeDictionary(table);

    // Initialize variables
    char current_sequence[MAX_CODE_LENGTH] = "";
    char next_character[MAX_CODE_LENGTH] = "";
    int current_code = -1;
    int next_code = 256;
    int output_code_length = 0;
    int output_bit_count = 0;
    unsigned char* output = (unsigned char*) malloc((length * 3) / 2);

    // Loop through input
    for (int i = 0; i < length; i++) {
        sprintf(next_character, "%c", input[i]);
        strcat(current_sequence, next_character);
        current_code = searchDictionary(table, current_sequence);
        if (current_code != -1) {
            // Sequence already in dictionary
            strcpy(current_sequence, current_sequence);
        } else {
            // Sequence not in dictionary
            addToDictionary(table, next_code++, current_sequence);
            current_code = searchDictionary(table, current_sequence);
            strcpy(current_sequence, next_character);
        }
        // Check if code length exceeds output buffer size
        if (output_code_length + 2 >= (length * 3) / 2) {
            printf("Output buffer full, compression stopped.\n");
            break;
        }
        // Write code to output buffer
        output_bit_count += 12;
        if (output_bit_count > 7) {
            output[output_code_length++] = (unsigned char) (current_code >> (output_bit_count - 8));
            output_bit_count -= 8;
        }
        output[output_code_length] = (unsigned char) ((current_code & ((1 << output_bit_count) - 1)) << (8 - output_bit_count));
    }
    // Set final compressed length
    *compressed_length = output_code_length + 1;
    // Add end-of-data code
    output_bit_count += 12;
    if (output_bit_count > 7) {
        output[output_code_length++] = (unsigned char) (current_code >> (output_bit_count - 8));
        output_bit_count -= 8;
    }
    output[output_code_length] = (unsigned char) ((current_code & ((1 << output_bit_count) - 1)) << (8 - output_bit_count));
    // Free memory and return output buffer
    free(table);
    return output;
}

// Main function for testing compression
int main() {
    // Initialize input and compressed output arrays
    unsigned char input[] = "It is my belief, Watson, founded upon my experience, that the lowest and vilest alleys in London do not present a more dreadful record of sin than does the smiling and beautiful countryside.";
    int input_length = strlen(input);
    int compressed_length = 0;
    unsigned char* compressed_output = compress(input, input_length, &compressed_length);

    // Print output to console
    printf("Original length: %d bytes\n", input_length);
    printf("Compressed length: %d bytes\n", compressed_length);
    printf("Compressed output: ");
    for (int i = 0; i < compressed_length; i++) {
        printf("%02x", compressed_output[i]);
    }
    printf("\n");

    // Free compressed output memory
    free(compressed_output);
    return 0;
}