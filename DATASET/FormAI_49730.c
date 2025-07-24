//FormAI DATASET v1.0 Category: File system simulation ; Style: grateful
#include<stdio.h>
#include<stdlib.h>

#define BLOCK_SIZE 512

typedef struct super_block {
    int block_count;
    int free_block_count;
    int next_free_block;
} super_block;

typedef struct file_metadata {
    char file_name[20];
    int start_block;
    int file_size;
} file_metadata;

int main() {
    FILE* disk;
    super_block sb;
    file_metadata metadata[10];
    int i, available_blocks;
    char buffer[BLOCK_SIZE];

    // Create a new disk image file
    disk = fopen("disk.img", "w+");
    if(disk == NULL) {
        printf("Error creating virtual disk\n");
        return -1;
    }

    // Initialize the super block
    sb.block_count = 100;
    sb.free_block_count = 100;
    sb.next_free_block = 0;

    // Write the super block to the disk
    fwrite(&sb, sizeof(super_block), 1, disk);

    // Reserve the first 10 blocks for metadata storage
    for(i = 0; i < 10; i++) {
        fwrite(buffer, BLOCK_SIZE, 1, disk);
    }

    // Calculate the number of available blocks
    available_blocks = sb.block_count - 10;

    // Initialize the metadata for the available files
    for(i = 0; i < 5; i++) {
        sprintf(metadata[i].file_name, "file_%d", i);
        metadata[i].start_block = 10 + i * 5;
        metadata[i].file_size = 1024;
        available_blocks -= 5;
    }

    // Write the metadata to the disk
    fseek(disk, BLOCK_SIZE, SEEK_SET);
    fwrite(metadata, sizeof(file_metadata), 5, disk);

    // Initialize the free block list
    for(i = 10 + 5 * 5; i < sb.block_count; i += 5) {
        // Store the address of the next free block in the first 4 bytes of the block
        *((int*) buffer) = i + 5;
        fwrite(buffer, BLOCK_SIZE, 1, disk);
    }
    *((int*) buffer) = -1; // Mark the last free block
    fwrite(buffer, BLOCK_SIZE, 1, disk);

    // Update the free block count and next free block pointer in the super block
    sb.free_block_count = available_blocks;
    sb.next_free_block = 10 + 5 * 5;

    // Write the updated super block to the disk
    fseek(disk, 0, SEEK_SET);
    fwrite(&sb, sizeof(super_block), 1, disk);

    fclose(disk);

    return 0;
}