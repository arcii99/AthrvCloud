//FormAI DATASET v1.0 Category: File system simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024 
// Block Size: The size of each block in bytes.
#define FILENAME_SIZE 16 
// Filename Size: Maximum size of filename can be 16 bytes.
#define MAX_FILES 16 
// Maximum Files: Maximum number of files in the file system.
#define MAX_BLOCKS 4096 
// Maximum Blocks: Number of maximum blocks in the file system.

// Structure for each file information i.e inode.
typedef struct inode_t {
    unsigned int size; 
    // File size in bytes.
    unsigned short blocks[8]; 
    // Blocks occupied by the file. Maximum blocks per file = 8
} inode;

// Structure for each block in the file system.
typedef struct block_t {
    char data[BLOCK_SIZE]; 
    // Data in the block.
} block;

// Structure for the virtual file system.
typedef struct file_system_t {
    inode inodes[MAX_FILES]; 
    // Array of inodes for each file in the file system.
    block blocks[MAX_BLOCKS]; 
    // Array of blocks in the file system.
    unsigned short free_blocks[MAX_BLOCKS]; 
    // Array of free blocks in the file system.
    unsigned int num_free_blocks; 
    // Number of free blocks in the file system.
} file_system;

// Function Prototype Definition
int create_file(file_system *, char *);
int write_file(file_system *, char *, char *);
int read_file(file_system *, char *);

int main(void) {
    file_system fs; 
    // Creating an instance of file_system
    memset(&fs, 0, sizeof(fs)); 
    // Initializes the memory area to 0s.

    create_file(&fs, "file1.txt"); 
    // Create a file i.e simulate "file1.txt" in the virtual file system.
    write_file(&fs, "file1.txt", "Hello, world!"); 
    // Write content to the created file.
    read_file(&fs, "file1.txt"); 
    // Read the written file content.

    return EXIT_SUCCESS;
}

// Function to create a file in the virtual file system.
int create_file(file_system *fs, char *filename) {
    int i, j; 
    inode *free_inode = NULL;
    unsigned short block_index;

    // Finding a free inode for the new file.
    for (i = 0; i < MAX_FILES; ++i) {
        if (fs->inodes[i].size == 0) {
            free_inode = &fs->inodes[i];
            break;
        }
    }

    if (free_inode == NULL) {
        printf("Error: Max files limit reached!\n");
        return EXIT_FAILURE;
    }

    // Finding a free block for the new file.
    if (fs->num_free_blocks == 0) {
        printf("Error: No free blocks available!\n");
        return EXIT_FAILURE;
    }

    for (i = 0; i < MAX_BLOCKS; ++i) {
        if (fs->free_blocks[i] == 0) {
            block_index = i;
            fs->num_free_blocks--;
            break;
        }
    }

    // Initializing the inode for the new file.
    free_inode->size = 0; 
    memset(free_inode->blocks, 0, sizeof(free_inode->blocks));
    free_inode->blocks[0] = block_index;

    // Initializing the block for the new file.
    memset(fs->blocks[block_index].data, 0, BLOCK_SIZE);
    strncpy(fs->blocks[block_index].data, filename, FILENAME_SIZE);

    printf("File created: %s\n", filename);
    return EXIT_SUCCESS;
}

// Function to write data to a file in the virtual file system.
int write_file(file_system *fs, char *filename, char *data) {
    int i, j; 
    inode *file_inode = NULL;
    block *file_block = NULL;
    unsigned short block_index;

    // Finding the inode for the specified file.
    for (i = 0; i < MAX_FILES; ++i) {
        if (strcmp(fs->blocks[fs->inodes[i].blocks[0]].data, filename) == 0) {
            file_inode = &fs->inodes[i];
            break;
        }
    }

    if (file_inode == NULL || data == NULL) {
        printf("Error: File not found!\n");
        return EXIT_FAILURE;
    }

    // Writing data to the file.
    for (i = 0; i < 8; ++i) {
        if (file_inode->blocks[i] == 0) {
            if (fs->num_free_blocks == 0) {
                printf("Error: No free blocks available!\n");
                return EXIT_FAILURE;
            }

            for (j = 0; j < MAX_BLOCKS; ++j) {
                if (fs->free_blocks[j] == 0) {
                    block_index = j;
                    fs->num_free_blocks--;
                    break;
                }
            }

            file_block = &fs->blocks[block_index];
            file_inode->blocks[i] = block_index;
        } else {
            file_block = &fs->blocks[file_inode->blocks[i]];
        }

        strncpy(file_block->data, data + (i * BLOCK_SIZE), BLOCK_SIZE);
        file_inode->size += BLOCK_SIZE;
    }

    printf("Data written to file: %s\n", filename);
    return EXIT_SUCCESS;
}

// Function to read data from a file in the virtual file system.
int read_file(file_system *fs, char *filename) {
    int i; 
    inode *file_inode = NULL; 
    block *file_block = NULL; 
    char buffer[BLOCK_SIZE * 8 + 1]; 
    // MAX_BLOCKS = 8;
    unsigned int size = 0;

    // Finding the inode for the specified file.
    for (i = 0; i < MAX_FILES; ++i) {
        if (strcmp(fs->blocks[fs->inodes[i].blocks[0]].data, filename) == 0) {
            file_inode = &fs->inodes[i];
            break;
        }
    }

    if (file_inode == NULL) {
        printf("Error: File not found!\n");
        return EXIT_FAILURE;
    }

    memset(buffer, 0, sizeof(buffer)); 
    // Initializing the buffer with 0s.

    // Reading data from the file.
    for (i = 0; i < 8; ++i) {
        if (file_inode->blocks[i] == 0) {
            break;
        } else {
            file_block = &fs->blocks[file_inode->blocks[i]];
            strncat(buffer, file_block->data, BLOCK_SIZE);
            size += BLOCK_SIZE;
        }
    }

    printf("File content read: %s (%d bytes)\n%s\n", filename, size, buffer);
    return EXIT_SUCCESS;
}