//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: automated
#include <stdio.h>
#include <string.h>

/**
* This program implements a basic digital watermarking technique
* by adding a unique string to the end of a given text file.
*/

int main(int argc, char *argv[]) {

    // Check if input arguments are correct
    if (argc != 3) {
        printf("Usage: %s <input_file> <watermark_string>\n", argv[0]);
        return 1;
    }

    // Open the input file in read-only mode
    FILE *in_file = fopen(argv[1], "r");
    if (!in_file) {
        printf("Could not open input file '%s'\n", argv[1]);
        return 2;
    }

    // Open a new file for writing the watermarked text
    char out_file_name[100];
    sprintf(out_file_name, "%s_watermarked.txt", argv[1]);
    FILE *out_file = fopen(out_file_name, "w");
    if (!out_file) {
        printf("Could not open output file '%s'\n", out_file_name);
        return 3;
    }

    // Read the entire input file into a buffer
    char buffer[1024];
    size_t bytes_read = fread(buffer, sizeof(char), sizeof(buffer), in_file);
    buffer[bytes_read] = '\0';
    fclose(in_file);

    // Append the watermark string to the buffer
    strcat(buffer, argv[2]);

    // Write the watermarked text to the output file
    fwrite(buffer, sizeof(char), strlen(buffer), out_file);
    fclose(out_file);

    printf("Successfully watermarked file '%s'\n", argv[1]);
    return 0;
}