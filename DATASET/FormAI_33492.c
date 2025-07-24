//FormAI DATASET v1.0 Category: Image compression ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 8

// Function to compress an image file
int compress_image(char* file_name) {
    // Open the input file in binary read mode
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error: Cannot open file\n");
        return -1;
    }

    // Get the size of the file
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Calculate the size of the output file
    int num_blocks = (file_size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    int original_size = file_size;
    file_size = num_blocks * BLOCK_SIZE;

    // Allocate the input and output buffers
    unsigned char* input_buffer = (unsigned char*)malloc(file_size);
    unsigned char* output_buffer = (unsigned char*)malloc(num_blocks * (BLOCK_SIZE / 2 + 1));
    memset(input_buffer + original_size, 0, file_size - original_size);

    // Read the input file into the input buffer
    fread(input_buffer, 1, original_size, file);
    fclose(file);

    // Compress each block of data
    int i;
    for (i = 0; i < num_blocks; i++) {
        int j, k;
        unsigned char* block_data = input_buffer + i * BLOCK_SIZE;
        int block_median = block_data[BLOCK_SIZE / 2];

        // Subtract the median value from each pixel in the block
        for (j = 0; j < BLOCK_SIZE; j++) {
            block_data[j] -= block_median;
        }

        // Write the block median to the output buffer
        output_buffer[i * (BLOCK_SIZE / 2 + 1)] = (unsigned char)block_median;

        // Run-length encode the block data and write it to the output buffer
        j = 0;
        k = 1;
        while (k < BLOCK_SIZE) {
            int count = 1;
            while (k < BLOCK_SIZE && block_data[k] == block_data[k - 1]) {
                count++;
                k++;
            }
            output_buffer[i * (BLOCK_SIZE / 2 + 1) + j + 1] = (unsigned char)count;
            output_buffer[i * (BLOCK_SIZE / 2 + 1) + j + 2] = block_data[k - 1];
            j += 2;
            k++;
        }
        output_buffer[i * (BLOCK_SIZE / 2 + 1) + j + 1] = 0;
    }

    // Open the output file in binary write mode and write the compressed data
    char output_file_name[256];
    sprintf(output_file_name, "%s.cmp", file_name);
    file = fopen(output_file_name, "wb");
    if (file == NULL) {
        printf("Error: Cannot create file\n");
        free(input_buffer);
        free(output_buffer);
        return -1;
    }
    fwrite(&original_size, sizeof(int), 1, file);
    fwrite(output_buffer, 1, num_blocks * (BLOCK_SIZE / 2 + 1), file);
    fclose(file);

    // Free the input and output buffers
    free(input_buffer);
    free(output_buffer);

    printf("Image compression successful\n");
    return 0;
}

int main() {
    printf("******************\n");
    printf("SURPRISE! Here's a unique C image compression program you didn't expect.\n");
    printf("This program compresses an image file by subtracting the median value of each pixel block\n");
    printf("and then run-length encoding the resulting values.\n");
    printf("To use this program, simply call the compress_image function and pass in the path to the image file.\n");
    printf("Have fun compressing your images!\n");
    printf("******************\n");
    return 0;
}