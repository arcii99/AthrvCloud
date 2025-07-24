//FormAI DATASET v1.0 Category: File system simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Constants
#define BLOCK_SIZE 512
#define BLOCK_COUNT 4096
#define TOTAL_SIZE BLOCK_SIZE * BLOCK_COUNT

// Define Flags
#define FLAG_FREE 0
#define FLAG_USED 1

// Define FileEntry Structure
typedef struct {
    char filename[20];
    int block_start;
    int block_count;
} FileEntry;

// Define SuperBlock Structure
typedef struct {
    int free_blocks;
    int used_blocks;
    int block_size;
    int block_count;
    FileEntry files[10];
} SuperBlock;

// Define Block Structure
typedef struct {
    char data[BLOCK_SIZE];
    int flag;
} Block;

// Create File System Image
Block file_system_image[BLOCK_COUNT];

// Create SuperBlock and a Pointer to SuperBlock
SuperBlock superblock;
SuperBlock *sb = &superblock;

// Initialize File System
void init_file_system() {
    // Initialize SuperBlock
    sb->free_blocks = BLOCK_COUNT;
    sb->used_blocks = 0;
    sb->block_size = BLOCK_SIZE;
    sb->block_count = BLOCK_COUNT;
    memset(&sb->files, 0, sizeof(sb->files));
    
    // Initialize Blocks
    for(int i=0; i<BLOCK_COUNT; i++) {
        memset(&file_system_image[i].data, 0, sizeof(file_system_image[i].data));
        file_system_image[i].flag = FLAG_FREE;
    }
}

// Print File System Status
void print_file_system_status() {
    printf("Free Blocks: %d\n", sb->free_blocks);
    printf("Used Blocks: %d\n", sb->used_blocks);
    printf("Block Size: %d\n", sb->block_size);
    printf("Block Count: %d\n\n", sb->block_count);
}

// Create File in File System
void create_file(char* filename) {
    int i, j, blocks_needed;
    
    // Calculate Blocks Needed
    blocks_needed = (rand() % 5) + 1; // Randomly select between 1-5 blocks
    
    // Check if Enough Free Blocks are Available
    if(blocks_needed > sb->free_blocks) {
        printf("Error: Not enough free blocks available to create file.\n");
        return;
    }
    
    // Search for Free Blocks and Write File Data
    for(i=0; i<BLOCK_COUNT; i++) {
        if(file_system_image[i].flag == FLAG_FREE) {
            file_system_image[i].flag = FLAG_USED;
            sb->free_blocks--;
            sb->used_blocks++;
            
            // Write Data to Block
            for(j=0; j<sb->block_size; j++) {
                file_system_image[i].data[j] = filename[j % strlen(filename)];
            }
            
            // Create FileEntry
            for(j=0; j<10; j++) {
                if(sb->files[j].block_count == 0) {
                    strcpy(sb->files[j].filename, filename);
                    sb->files[j].block_start = i;
                    sb->files[j].block_count = blocks_needed;
                    break;
                }
            }
            
            // Check if Enough Blocks have been found
            if(--blocks_needed == 0) {
                printf("File Created: %s\n", filename);
                return;
            }
        }
    }
}

// Delete File from File System
void delete_file(char* filename) {
    int i, j, blocks_freed = 0;
    FileEntry file;
    
    // Search for FileEntry
    for(i=0; i<10; i++) {
        if(strcmp(sb->files[i].filename, filename) == 0) {
            file = sb->files[i];
            memset(&sb->files[i], 0, sizeof(sb->files[i]));
            break;
        }
    }
    
    // Check if File Found
    if(i == 10) {
        printf("Error: File not found.\n");
        return;
    }
    
    // Free Allocated Blocks
    for(i=file.block_start; i<file.block_start+file.block_count; i++) {
        file_system_image[i].flag = FLAG_FREE;
        blocks_freed++;
    }
    
    // Update SuperBlock
    sb->free_blocks += blocks_freed;
    sb->used_blocks -= blocks_freed;
    
    printf("File Deleted: %s\n", filename);
}

int main() {
    // Initialize File System
    init_file_system();
    
    // Print File System Status
    print_file_system_status();
    
    // Create Files
    create_file("file1");
    create_file("file2");
    create_file("file3");
    
    // Print File System Status
    print_file_system_status();
    
    // Delete File2
    delete_file("file2");
    
    // Print File System Status
    print_file_system_status();
    
    return 0;
}