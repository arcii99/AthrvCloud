//FormAI DATASET v1.0 Category: Data recovery tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024 // Set block size as 1024 bytes

// Structure for metadata 
struct Metadata {
    int block_num; // Block number where the data is present
    int data_size; // Size of the original data
};

// Function to read metadata from given block number
struct Metadata read_metadata(int block_num, FILE* disk_file) {
    struct Metadata metadata;
    fseek(disk_file, block_num * BLOCK_SIZE, SEEK_SET); // Move file pointer to given block
    fread(&metadata, sizeof(struct Metadata), 1, disk_file); // Read metadata from block
    return metadata;
}

// Function to recover data from given block number
void recover_data(int block_num, char* output_file, FILE* disk_file) {
    struct Metadata metadata = read_metadata(block_num, disk_file); // Read metadata
    int data_size = metadata.data_size; // Get size of original data
    int num_blocks = data_size / BLOCK_SIZE + 1; // Calculate the number of blocks required
    FILE* output = fopen(output_file, "wb"); // Open output file in binary mode
    char* recovered_data = malloc(num_blocks * BLOCK_SIZE); // Allocate memory for recovered data

    // Read data from each block and concatenate them
    for (int i = 0; i < num_blocks; i++) {
        fseek(disk_file, (metadata.block_num + i + 1) * BLOCK_SIZE, SEEK_SET); // Move file pointer to next block
        fread(&recovered_data[i * BLOCK_SIZE], BLOCK_SIZE, 1, disk_file); // Read and store data from block
    }

    // Write recovered data to output file and free memory
    fwrite(recovered_data, 1, data_size, output);
    free(recovered_data);
    fclose(output);
}

int main() {
    FILE* disk_file = fopen("disk.img", "rb"); // Open disk image file in binary mode
    char* output_file = "recovered_data.txt"; // Set output file name
    recover_data(10, output_file, disk_file); // Example: recover data from block 10

    fclose(disk_file); // Close disk image file
    return 0;
}