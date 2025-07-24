//FormAI DATASET v1.0 Category: Data recovery tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    
    // Open files
    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("Error: Unable to open %s\n", argv[1]);
        return 1;
    }
    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        printf("Error: Unable to open %s\n", argv[2]);
        fclose(input_file);
        return 1;
    }
    
    // Read data from input file
    char block[BLOCK_SIZE];
    int bytes_read = 0;
    int block_count = 0;
    while ((bytes_read = fread(block, 1, BLOCK_SIZE, input_file))) {
        if (bytes_read == BLOCK_SIZE) {
            // Full block read from input, write to output
            fwrite(block, 1, BLOCK_SIZE, output_file);
        } else {
            // Partial block read from input, process data
            block[bytes_read] = '\0'; // Null terminate
            char *str = strstr(block, "DATA="); // Search for data
            if (str) {
                // Data found, extract and write to output
                str += 5;
                char *end_str = strchr(str, ';');
                if (!end_str) {
                    // Invalid data format, skip
                    continue;
                }
                *end_str = '\0';
                fprintf(output_file, "%s\n", str);
            }
        }
        block_count++;
    }
    
    // Clean up
    fclose(input_file);
    fclose(output_file);
    printf("Processed %d blocks\n", block_count);
    return 0;
}