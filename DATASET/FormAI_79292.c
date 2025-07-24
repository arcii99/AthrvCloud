//FormAI DATASET v1.0 Category: File system simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 256 // Block size in bytes
#define NUM_BLOCKS 1024 // Number of blocks in the file system
#define MAX_FILES 16 // Maximum number of files the file system can support

struct Superblock {
    int block_size;
    int num_blocks;
    int num_free_blocks;
    int free_block_list[NUM_BLOCKS]; // Array of block indices that are free
};

struct Inode {
    int file_size;
    int block_ptrs[6]; // Pointers to data blocks. Only using direct pointers for simplicity.
};

struct Directory_entry {
    char name[32];
    int inode_index;
};

struct File_system {
    struct Superblock sb;
    struct Inode inode_table[MAX_FILES];
    struct Directory_entry dir_table[MAX_FILES];
    char data[NUM_BLOCKS][BLOCK_SIZE]; // Data blocks
};

void initialize_file_system(struct File_system *fs) {
    // Set up the superblock
    fs->sb.block_size = BLOCK_SIZE;
    fs->sb.num_blocks = NUM_BLOCKS;
    fs->sb.num_free_blocks = NUM_BLOCKS;
    for (int i = 0; i < NUM_BLOCKS; i++) {
        fs->sb.free_block_list[i] = i;
    }

    // Set up the inode table
    for (int i = 0; i < MAX_FILES; i++) {
        fs->inode_table[i].file_size = 0;
        for (int j = 0; j < 6; j++) {
            fs->inode_table[i].block_ptrs[j] = -1;
        }
    }

    // Set up the directory table
    for (int i = 0; i < MAX_FILES; i++) {
        strcpy(fs->dir_table[i].name, "");
        fs->dir_table[i].inode_index = -1;
    }
}

int allocate_block(struct File_system *fs) {
    if (fs->sb.num_free_blocks > 0) {
        int block_index = fs->sb.free_block_list[fs->sb.num_free_blocks - 1];
        fs->sb.num_free_blocks--;
        return block_index;
    } else {
        printf("Error: no free blocks available\n");
        return -1;
    }
}

void free_block(struct File_system *fs, int block_index) {
    fs->sb.free_block_list[fs->sb.num_free_blocks] = block_index;
    fs->sb.num_free_blocks++;
}

int create_file(struct File_system *fs, char *name) {
    // Check if file already exists
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(fs->dir_table[i].name, name) == 0) {
            printf("Error: file %s already exists\n", name);
            return -1;
        }
    }

    // Allocate an inode and data block for the new file
    int inode_index = -1;
    int data_block_index = -1;
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->inode_table[i].file_size == 0) { // Find first free inode
            fs->inode_table[i].file_size = 0;
            for (int j = 0; j < 6; j++) {
                fs->inode_table[i].block_ptrs[j] = -1;
            }
            inode_index = i;
            break;
        }
    }
    if (inode_index == -1) {
        printf("Error: maximum number of files reached\n");
        return -1;
    }
    data_block_index = allocate_block(fs);
    if (data_block_index == -1) {
        return -1;
    }

    // Add the new file to the directory table
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->dir_table[i].inode_index == -1) { // Find first free directory entry
            strcpy(fs->dir_table[i].name, name);
            fs->dir_table[i].inode_index = inode_index;
            break;
        }
    }

    // Update the inode for the new file
    fs->inode_table[inode_index].block_ptrs[0] = data_block_index;

    return inode_index;
}

void delete_file(struct File_system *fs, char *name) {
    int inode_index = -1;
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(fs->dir_table[i].name, name) == 0) {
            inode_index = fs->dir_table[i].inode_index;
            fs->dir_table[i].inode_index = -1; // Remove directory entry
            strcpy(fs->dir_table[i].name, "");
            break;
        }
    }
    if (inode_index == -1) {
        printf("Error: file %s not found\n", name);
        return;
    }
    for (int i = 0; i < 6; i++) {
        if (fs->inode_table[inode_index].block_ptrs[i] != -1) {
            free_block(fs, fs->inode_table[inode_index].block_ptrs[i]); // Free data block
        }
    }
    fs->inode_table[inode_index].file_size = 0; // Free inode
}

void write_file(struct File_system *fs, char *name, char *data, int length) {
    int inode_index = -1;
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(fs->dir_table[i].name, name) == 0) {
            inode_index = fs->dir_table[i].inode_index;
            break;
        }
    }
    if (inode_index == -1) {
        printf("Error: file %s not found\n", name);
        return;
    }
    int block_index = fs->inode_table[inode_index].block_ptrs[0];
    for (int i = 0; i < length; i++) {
        int byte_index = fs->inode_table[inode_index].file_size % BLOCK_SIZE;
        if (byte_index == 0 && fs->inode_table[inode_index].file_size > 0) { // Allocate a new block if necessary
            int new_block_index = allocate_block(fs);
            if (new_block_index == -1) {
                return;
            }
            block_index = new_block_index;
            fs->inode_table[inode_index].block_ptrs[0] = new_block_index;
        }
        fs->data[block_index][byte_index] = data[i];
        fs->inode_table[inode_index].file_size++;
    }
}

void read_file(struct File_system *fs, char *name) {
    int inode_index = -1;
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(fs->dir_table[i].name, name) == 0) {
            inode_index = fs->dir_table[i].inode_index;
            break;
        }
    }
    if (inode_index == -1) {
        printf("Error: file %s not found\n", name);
        return;
    }
    int block_index = fs->inode_table[inode_index].block_ptrs[0];
    for (int i = 0; i < fs->inode_table[inode_index].file_size; i++) {
        int byte_index = i % BLOCK_SIZE;
        if (byte_index == 0 && i > 0) { // Move to the next block if necessary
            block_index = fs->data[block_index][BLOCK_SIZE - 1];
        }
        printf("%c", fs->data[block_index][byte_index]);
    }
    printf("\n");
}

int main() {
    struct File_system fs;
    initialize_file_system(&fs);

    int inode_index = create_file(&fs, "test.txt");
    if (inode_index == -1) {
        return 1;
    }
    write_file(&fs, "test.txt", "This is a test file.", 20);
    read_file(&fs, "test.txt");

    delete_file(&fs, "test.txt");

    return 0;
}