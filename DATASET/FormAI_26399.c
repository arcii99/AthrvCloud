//FormAI DATASET v1.0 Category: File system simulation ; Style: future-proof
// A future-proof C file system simulation program example
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100 // Maximum number of files
#define MAX_NAME_SIZE 25 // Maximum file name size

// Defining the file structure
typedef struct {
    char name[MAX_NAME_SIZE]; // File name
    int size; // File size
    int blocks; // Number of blocks occupied by the file
    int starting_block; // Index of the starting block in the file system
} File;

// Defining the block structure
typedef struct {
    int index; // Index of the block in the file system
    int is_free; // 1 if the block is free, 0 otherwise
} Block;

// Defining the file system structure
typedef struct {
    Block blocks[MAX_FILES]; // Array of blocks in the file system
    File files[MAX_FILES]; // Array of files in the file system
    int num_blocks; // Total number of blocks in the file system
    int num_files; // Total number of files in the file system
} FileSystem;

/**
 * Initializes the file system
 * @param fs The file system instance to initialize
 * @param num_blocks The total number of blocks in the file system
 */
void initialize_file_system(FileSystem* fs, int num_blocks) {
    // Setting the total number of blocks in the file system
    fs->num_blocks = num_blocks;

    // Setting all blocks to be initially free
    for (int i = 0; i < MAX_FILES; i++) {
        fs->blocks[i].index = i;
        fs->blocks[i].is_free = 1;
    }

    // Setting the total number of files to be 0 initially
    fs->num_files = 0;
}

/**
 * Adds a new file to the file system
 * @param fs The file system instance to add the file to
 * @param name The name of the file to add
 * @param size The size of the file to add
 * @return 1 if the file was added successfully, 0 otherwise
 */
int add_file(FileSystem* fs, char* name, int size) {
    // Checking if there is enough space in the file system for the new file
    int free_space = 0;
    for (int i = 0; i < fs->num_blocks; i++) {
        if (fs->blocks[i].is_free) {
            free_space++;
            if (free_space >= size) {
                break;
            }
        }
    }
    if (free_space < size) {
        return 0; // Not enough free space in the file system
    }

    // Adding the file to the file system
    int blocks_needed = size;
    int starting_block = -1;
    for (int i = 0; i < fs->num_blocks; i++) {
        if (fs->blocks[i].is_free) {
            if (starting_block == -1) {
                starting_block = i;
            }
            fs->blocks[i].is_free = 0;
            blocks_needed--;
        }
        if (blocks_needed == 0) {
            break;
        }
    }

    // Creating the file structure and adding it to the file system
    File new_file = {
        .size = size,
        .blocks = size,
        .starting_block = starting_block,
    };
    strncpy(new_file.name, name, MAX_NAME_SIZE - 1);
    new_file.name[MAX_NAME_SIZE - 1] = '\0';
    fs->files[fs->num_files] = new_file;
    fs->num_files++;

    return 1;
}

/**
 * Lists all files in the file system
 * @param fs The file system instance to list the files from
 */
void list_files(FileSystem* fs) {
    for (int i = 0; i < fs->num_files; i++) {
        printf("%s (%d bytes, %d blocks)\n", fs->files[i].name, fs->files[i].size, fs->files[i].blocks);
    }
}

/**
 * Deletes a file from the file system
 * @param fs The file system instance to delete the file from
 * @param name The name of the file to delete
 * @return 1 if the file was deleted successfully, 0 otherwise
 */
int delete_file(FileSystem* fs, char* name) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            // Freeing the blocks occupied by the file
            for (int j = fs->files[i].starting_block; j < fs->files[i].starting_block + fs->files[i].blocks; j++) {
                fs->blocks[j].is_free = 1;
            }
            // Removing the file from the file system
            for (int j = i + 1; j < fs->num_files; j++) {
                fs->files[j - 1] = fs->files[j];
            }
            fs->num_files--;
            return 1;
        }
    }
    return 0; // File not found in the file system
}

int main() {
    // Initializing the file system with 100 blocks
    FileSystem fs;
    initialize_file_system(&fs, 100);
    
    // Adding some example files
    add_file(&fs, "file1.txt", 5);
    add_file(&fs, "file2.txt", 8);
    add_file(&fs, "file3.txt", 15);
    add_file(&fs, "file4.txt", 20);

    // Listing all files in the file system
    printf("Files in file system:\n");
    list_files(&fs);
    
    // Deleting a file from the file system
    printf("\nDeleting file file2.txt...\n");
    delete_file(&fs, "file2.txt");

    // Listing all files in the file system again
    printf("\nFiles in file system after deletion:\n");
    list_files(&fs);

    return 0;
}