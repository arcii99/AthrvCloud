//FormAI DATASET v1.0 Category: File Encyptor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_FILESIZE 1048576 // 1 MB

int main() {
    char filename[MAX_FILENAME_LENGTH];
    FILE *input_file, *output_file;
    unsigned char *buffer;
    long long file_size;
    int i, offset;

    // Get input filename from user
    printf("Enter input filename: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0;

    // Open input file
    input_file = fopen(filename, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file\n");
        return 1;
    }

    // Get file size
    fseek(input_file, 0, SEEK_END);
    file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    // Check if file is too large
    if (file_size > MAX_FILESIZE) {
        printf("Error: File is too large\n");
        fclose(input_file);
        return 1;
    }

    // Allocate memory for file buffer
    buffer = (unsigned char*) malloc(file_size);
    if (buffer == NULL) {
        printf("Error: Out of memory\n");
        fclose(input_file);
        return 1;
    }

    // Read file into buffer
    fread(buffer, file_size, 1, input_file);
    fclose(input_file);

    // Encrypt buffer
    offset = 0;
    for (i = 0; i < file_size; i++) {
        buffer[i] ^= (offset & 0xff);
        offset++;
    }

    // Get output filename from user
    printf("Enter output filename: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0;

    // Open output file
    output_file = fopen(filename, "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file\n");
        free(buffer);
        return 1;
    }

    // Write encrypted buffer to file
    fwrite(buffer, file_size, 1, output_file);
    fclose(output_file);

    // Free memory
    free(buffer);

    printf("File encryption complete\n");

    return 0;
}