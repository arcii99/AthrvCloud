//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

// Data recovery function
int recover_data(FILE* device, char* signature, char* output_directory) {
    int success = 0;
    int block_offset = 0;
    char filename[100];
    
    // Scan the device for the signature
    while (!feof(device)) {
        char block[BLOCK_SIZE];
        size_t signature_length = strlen(signature);
        
        // Read a block from the device
        int bytes_read = fread(block, 1, BLOCK_SIZE, device);
        block_offset += BLOCK_SIZE;
        
        // Check if the signature is found in the block
        char* match = strstr(block, signature);
        if (match != NULL) {
            success = 1;
            int match_offset = match - block;
            
            // Calculate the starting offset of the recovered data
            int data_offset = block_offset - BLOCK_SIZE + match_offset;
            
            // Create the output file
            sprintf(filename, "%s/recovered_data.bin", output_directory);
            FILE* output_file = fopen(filename, "wb");
            
            if (output_file == NULL) {
                printf("Could not create output file.\n");
                success = 0;
                break;
            }
            
            // Write the recovered data to the output file
            fseek(device, data_offset, SEEK_SET);
            while (!feof(device)) {
                char data_block[BLOCK_SIZE];
                int data_bytes_read = fread(data_block, 1, BLOCK_SIZE, device);
                fwrite(data_block, 1, data_bytes_read, output_file);
            }
            
            fclose(output_file);
            break;
        }
    }
    
    if (success) {
        printf("Data recovery successful!\n");
    } else {
        printf("Could not recover data.\n");
    }
    
    return success;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s [device] [output_directory]\n", argv[0]);
        return 0;
    }
    
    char* device_name = argv[1];
    char* output_directory = argv[2];
    
    // Open the device file
    FILE* device = fopen(device_name, "rb");
    
    if (device == NULL) {
        printf("Could not open device: %s\n", device_name);
        return 0;
    }
    
    // Recover the data
    recover_data(device, "my_signature", output_directory);
    
    // Close the device file
    fclose(device);
    
    return 0;
}