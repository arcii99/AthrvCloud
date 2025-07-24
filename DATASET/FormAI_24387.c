//FormAI DATASET v1.0 Category: File Encyptor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

// Function to encrypt the contents of the input file and write the output to the output file
void encrypt_file(FILE *input_file, FILE *output_file) {
    char buffer[MAX_FILE_SIZE];
    size_t bytes_read = 0;
    unsigned char key = 0x4b; // secret key for encryption

    // Read the contents of the input file into the buffer
    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, input_file)) > 0) {
        // Encrypt the buffer by XOR-ing with the key
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key;
        }

        // Write the encrypted buffer to the output file
        fwrite(buffer, 1, bytes_read, output_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file_path> <output_file_path>\n", argv[0]);
        return 1;
    }

    // Open the input file for reading
    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        printf("Error: unable to open input file '%s'\n", argv[1]);
        return 1;
    }

    // Open the output file for writing
    FILE *output_file = fopen(argv[2], "wb");
    if (!output_file) {
        printf("Error: unable to open output file '%s'\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    // Encrypt the contents of the input file and write to the output file
    encrypt_file(input_file, output_file);

    // Cleanup
    fclose(input_file);
    fclose(output_file);

    return 0;
}