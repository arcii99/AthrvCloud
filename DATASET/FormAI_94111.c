//FormAI DATASET v1.0 Category: File system simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 1000 // Maximum number of files the file system can hold.
#define BLOCK_SIZE 1024 // Block size of the file system, each block size is 1024 bytes.

typedef struct {
    char filename[50]; // Name of the file.
    int start_block; // Starting block of the file.
    int num_blocks; // Number of blocks the file occupies.
} File;

File file_system[MAX_FILES];
int num_files = 0;
char disk[MAX_FILES * (BLOCK_SIZE + sizeof(File))];

/**
 * Function that initializes the file system.
*/
void init_file_system() {
    memset(disk, 0, sizeof(disk)); // Clearing the disk.
    num_files = 0; // Resetting the number of files.

    // Initializing file_system array with empty values.
    for (int i = 0; i < MAX_FILES; i++) {
        file_system[i].filename[0] = '\0';
        file_system[i].start_block = 0;
        file_system[i].num_blocks = 0;
    }
}

/**
 * Function that creates a new file in the file system.
 *
 * @param filename - Name of the file to be created.
 * @param num_blocks - Number of blocks the file occupies.
*/
void create_file(char *filename, int num_blocks) {
    // Check if the file system has enough space.
    if ((num_files + 1) * sizeof(File) + num_blocks * BLOCK_SIZE > sizeof(disk)) {
        printf("Error: Not enough space in the file system!\n");
        return;
    }

    // Check if the file name already exists.
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_system[i].filename, filename) == 0) {
            printf("Error: File with name '%s' already exists!\n", filename);
            return;
        }
    }

    // Finding the first available block.
    int start_block = -1;
    for (int i = 0; i < MAX_FILES; i++) {
        if (file_system[i].num_blocks == 0) {
            start_block = i;
            break;
        }
    }

    if (start_block == -1) { // Check if no block is available.
        printf("Error: No block available to allocate file '%s'!\n", filename);
        return;
    }

    // Storing file information in file_system array.
    strcpy(file_system[start_block].filename, filename);
    file_system[start_block].num_blocks = num_blocks;
    file_system[start_block].start_block = num_files + 1;

    // Allocating blocks for the file.
    for (int i = 0; i < num_blocks; i++) {
        memset(&disk[(num_files + 1) * sizeof(File) + i * BLOCK_SIZE], 0, BLOCK_SIZE);
    }

    num_files++;
    printf("File '%s' created successfully!\n", filename);
}

/**
 * Function that reads data from a file.
 *
 * @param filename - Name of the file to be read.
 * @param block_num - Block number from where to start reading.
 * @param num_blocks - Number of blocks to be read.
*/
void read_file(char *filename, int block_num, int num_blocks) {
    int file_index = -1;

    // Finding the given file.
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_system[i].filename, filename) == 0) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) { // Check if file not found.
        printf("Error: File with name '%s' not found!\n", filename);
        return;
    }

    // Checking if the given block is within the file system range.
    if (block_num < 0 || block_num + num_blocks > file_system[file_index].num_blocks) {
        printf("Error: Invalid block range for file '%s'!\n", filename);
        return;
    }

    // Reading file data from disk.
    char *data = &disk[file_system[file_index].start_block * sizeof(File) + block_num * BLOCK_SIZE];
    printf("Data read from file '%s':\n%s\n", filename, data);
}

/**
 * Function that writes data to a file.
 *
 * @param filename - Name of the file to be written.
 * @param block_num - Block number from where to start writing.
 * @param data - Data to be written to the file.
*/
void write_file(char *filename, int block_num, char *data) {
    int file_index = -1;

    // Finding the given file.
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_system[i].filename, filename) == 0) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) { // Check if file not found.
        printf("Error: File with name '%s' not found!\n", filename);
        return;
    }

    // Checking if the given block is within the file system range.
    if (block_num < 0 || block_num + strlen(data) / BLOCK_SIZE > file_system[file_index].num_blocks) {
        printf("Error: Invalid block range for file '%s'!\n", filename);
        return;
    }

    // Writing data to the file.
    char *file_block = &disk[file_system[file_index].start_block * sizeof(File) + block_num * BLOCK_SIZE];
    strcpy(file_block, data);

    printf("Data written to file '%s'!\n", filename);
}

/**
 * Main function that simulates the file system operations.
*/
int main() {
    char filename[50];
    int num_blocks, block_num, num_read_blocks;
    char data[BLOCK_SIZE];

    printf("Initializing the file system...\n");
    init_file_system();

    printf("Creating a new file 'file1' with 3 blocks...\n");
    create_file("file1", 3);

    printf("Creating a new file 'file2' with 2 blocks...\n");
    create_file("file2", 2);

    printf("Writing data to file 'file1'...\n");
    strcpy(data, "This is block 0 of file1.");
    write_file("file1", 0, data);
    strcpy(data, "This is block 1 of file1.");
    write_file("file1", 1, data);
    strcpy(data, "This is block 2 of file1.");
    write_file("file1", 2, data);

    printf("Writing data to file 'file2'...\n");
    strcpy(data, "This is block 0 of file2.");
    write_file("file2", 0, data);
    strcpy(data, "This is block 1 of file2.");
    write_file("file2", 1, data);

    printf("Reading data from file 'file1'...\n");
    read_file("file1", 0, 3);

    printf("Reading data from file 'file2'...\n");
    read_file("file2", 0, 2);

    return 0;
}