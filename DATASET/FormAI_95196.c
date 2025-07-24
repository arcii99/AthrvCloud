//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#define MAX_SIZE 1000

// Compresses the input string using the RLE algorithm
int compress(char input[], int length, char output[]) {
    int count = 1, output_index = 0;
    char current = input[0];
    
    for (int i=1; i<length; i++) {
        if (input[i] == current) {
            count++;
        } else {
            // Append the current character and its count to the output string
            output[output_index] = current;
            output[output_index+1] = count + '0';
            count = 1;
            output_index += 2;
            current = input[i];
        }
    }
    
    // Append the last character and its count to the output string
    output[output_index] = current;
    output[output_index+1] = count + '0';
    output_index += 2;

    // Terminate the output string with a null character
    output[output_index] = '\0';

    return output_index;
}

// Decompresses the input string using the RLE algorithm
int decompress(char input[], int length, char output[]) {
    int output_index = 0;
    
    for (int i=0; i<length; i+=2) {
        char current = input[i];
        int count = input[i+1] - '0';
        
        // Append the current character count number of times to the output string
        for (int j=0; j<count; j++) {
            output[output_index++] = current;
        }
    }

    // Terminate the output string with a null character
    output[output_index] = '\0';

    return output_index;
}

int main() {
    char input[MAX_SIZE];
    char output[MAX_SIZE];
    int length, compressed_length, decompressed_length;

    // Read input string from the user
    printf("Enter the string to compress: ");
    fgets(input, sizeof(input), stdin);
    length = strlen(input)-1;

    // Compress the input string
    compressed_length = compress(input, length, output);

    // Print the compressed string and its length
    printf("Compressed string: %s\n", output);
    printf("Compressed length: %d\n", compressed_length);

    // Decompress the compressed string
    decompressed_length = decompress(output, compressed_length, input);

    // Print the decompressed string and its length
    printf("Decompressed string: %s\n", input);
    printf("Decompressed length: %d\n", decompressed_length);

    return 0;
}