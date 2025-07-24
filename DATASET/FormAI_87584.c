//FormAI DATASET v1.0 Category: File system simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define BLOCKSIZE 512
#define NUM_BLOCKS 1024
#define NUM_FILES 64
#define FILENAME_SIZE 20

// Superblock struct
struct superblock {
    int num_blocks;
    int blocksize;
    int num_files;
};

// Inode struct
struct inode {
    int file_size;
    int num_blocks;
    int blocks[NUM_BLOCKS];
};

// Directory Entry struct
struct dir_entry {
    char filename[FILENAME_SIZE];
    int inode;
};

// File System struct
struct file_system {
    struct superblock super;
    struct inode inodes[NUM_FILES];
    struct dir_entry dirs[NUM_FILES];
    char data[NUM_BLOCKS][BLOCKSIZE];
};

// Global variables
struct file_system fs;
int num_free_blocks = NUM_BLOCKS;

// Function prototypes
void format_fs();
int create_file(char* filename, int filesize);
int delete_file(char* filename);
void write_file(char* filename, char* data, int datasize);
void read_file(char* filename, char* buf, int bufsize);
void list_files();
void disk_usage();

int main() {
    // Random seed for file creation
    srand(time(NULL));

    // Format file system before use
    format_fs();

    // Create dummy files
    create_file("file1.txt", 1024);
    create_file("file2.txt", 2048);
    create_file("file3.txt", 4096);

    // List all files in file system
    list_files();

    // Delete some files
    delete_file("file2.txt");
    delete_file("file3.txt");

    // List all files in file system
    list_files();

    // Write some data to remaining file
    write_file("file1.txt", "Hello world!", 12);

    // Read data from remaining file
    char buf[20];
    read_file("file1.txt", buf, 20);
    printf("%s\n", buf);

    // Show disk usage statistics
    disk_usage();

    return 0;
}

// Format the file system
void format_fs() {
    // Set superblock values
    fs.super.num_blocks = NUM_BLOCKS;
    fs.super.blocksize = BLOCKSIZE;
    fs.super.num_files = NUM_FILES;

    // Reset all inodes and directory entries
    memset(fs.inodes, 0, sizeof(fs.inodes));
    memset(fs.dirs, 0, sizeof(fs.dirs));

    // Reset all data blocks
    memset(fs.data, 0, sizeof(fs.data));

    // Calculate free blocks
    num_free_blocks = NUM_BLOCKS - NUM_FILES - 1;
}

// Create a file with given filename and filesize
int create_file(char* filename, int filesize) {
    // Check if file already exists
    for (int i=0; i<fs.super.num_files; i++) {
        if (strcmp(fs.dirs[i].filename, filename) == 0) {
            printf("File %s already exists!\n", filename);
            return -1;
        }
    }

    // Find first empty directory entry
    int dirent = -1;
    for (int i=0; i<fs.super.num_files; i++) {
        if (fs.dirs[i].inode == 0) {
            dirent = i;
            break;
        }
    }
    if (dirent == -1) {
        printf("No more directory entries available!\n");
        return -1;
    }

    // Find required number of blocks
    int num_blocks = (filesize + BLOCKSIZE - 1) / BLOCKSIZE;
    if (num_blocks > num_free_blocks) {
        printf("Not enough disk space available!\n");
        return -1;
    }
    num_free_blocks -= num_blocks;

    // Allocate blocks for the file
    int inode = -1;
    for (int i=0; i<fs.super.num_files; i++) {
        if (fs.inodes[i].num_blocks == 0) {
            fs.inodes[i].file_size = filesize;
            fs.inodes[i].num_blocks = num_blocks;
            inode = i;
            break;
        }
    }
    if (inode == -1) {
        printf("No more inodes available!\n");
        return -1;
    }
    for (int i=0; i<num_blocks; i++) {
        int block = -1;
        for (int j=0; j<fs.super.num_blocks; j++) {
            if (fs.data[j][0] == '\0') {
                block = j;
                break;
            }
        }
        if (block == -1) {
            printf("No more data blocks available!\n");
            return -1;
        }
        fs.data[block][0] = '1';
        fs.inodes[inode].blocks[i] = block;
    }

    // Update directory entry
    strcpy(fs.dirs[dirent].filename, filename);
    fs.dirs[dirent].inode = inode;

    printf("File %s created successfully!\n", filename);
    return 0;
}

// Delete a file with given name
int delete_file(char* filename) {
    // Find directory entry for file
    int dirent = -1;
    for (int i=0; i<fs.super.num_files; i++) {
        if (strcmp(fs.dirs[i].filename, filename) == 0) {
            dirent = i;
            break;
        }
    }
    if (dirent == -1) {
        printf("File %s not found!\n", filename);
        return -1;
    }

    // Free blocks used by file
    int inode = fs.dirs[dirent].inode;
    for (int i=0; i<fs.inodes[inode].num_blocks; i++) {
        fs.data[fs.inodes[inode].blocks[i]][0] = '\0';
    }
    num_free_blocks += fs.inodes[inode].num_blocks;

    // Clear inode and directory entry
    fs.inodes[inode].file_size = 0;
    fs.inodes[inode].num_blocks = 0;
    memset(fs.inodes[inode].blocks, 0, sizeof(fs.inodes[inode].blocks));
    memset(fs.dirs[dirent].filename, 0, sizeof(fs.dirs[dirent].filename));
    fs.dirs[dirent].inode = 0;

    printf("File %s deleted successfully!\n", filename);
    return 0;
}

// Write data to a file
void write_file(char* filename, char* data, int datasize) {
    // Find inode for file
    int inode = -1;
    for (int i=0; i<fs.super.num_files; i++) {
        if (strcmp(fs.dirs[i].filename, filename) == 0) {
            inode = fs.dirs[i].inode;
            break;
        }
    }
    if (inode == -1) {
        printf("File %s not found!\n", filename);
        return;
    }

    // Write data to blocks
    int offset = 0;
    for (int i=0; i<fs.inodes[inode].num_blocks; i++) {
        int block = fs.inodes[inode].blocks[i];
        int bytes_to_copy = BLOCKSIZE - offset;
        if (offset + datasize < BLOCKSIZE) {
            bytes_to_copy = datasize;
        }
        memcpy(fs.data[block] + offset, data, bytes_to_copy);
        offset += bytes_to_copy;
        datasize -= bytes_to_copy;
        if (datasize == 0) {
            break;
        }
    }

    printf("Data written to file %s successfully!\n", filename);
}

// Read data from a file
void read_file(char* filename, char* buf, int bufsize) {
    // Find inode for file
    int inode = -1;
    for (int i=0; i<fs.super.num_files; i++) {
        if (strcmp(fs.dirs[i].filename, filename) == 0) {
            inode = fs.dirs[i].inode;
            break;
        }
    }
    if (inode == -1) {
        printf("File %s not found!\n", filename);
        return;
    }

    // Copy data from blocks to buffer
    int offset = 0;
    for (int i=0; i<fs.inodes[inode].num_blocks; i++) {
        int block = fs.inodes[inode].blocks[i];
        int bytes_to_copy = BLOCKSIZE - offset;
        if (offset + bufsize < BLOCKSIZE) {
            bytes_to_copy = bufsize;
        }
        memcpy(buf, fs.data[block] + offset, bytes_to_copy);
        offset += bytes_to_copy;
        bufsize -= bytes_to_copy;
        if (bufsize == 0) {
            break;
        }
    }

    printf("Data read from file %s successfully!\n", filename);
}

// List all files in file system
void list_files() {
    printf("Files in file system:\n");
    for (int i=0; i<fs.super.num_files; i++) {
        if (fs.dirs[i].inode != 0) {
            printf("%s\n", fs.dirs[i].filename);
        }
    }
}

// Show disk usage statistics
void disk_usage() {
    printf("Disk usage statistics:\n");
    printf("Block size: %d bytes\n", fs.super.blocksize);
    printf("Number of blocks: %d\n", fs.super.num_blocks);
    printf("Number of free blocks: %d\n", num_free_blocks);
    printf("Number of files: %d\n", fs.super.num_files);
}