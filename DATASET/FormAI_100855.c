//FormAI DATASET v1.0 Category: File system simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define BLOCK_SIZE 512
#define NUM_BLOCKS 100
#define FILE_NAME_SIZE 32
#define MAX_FILES 10

// Represents the file system block
typedef struct {
    char data[BLOCK_SIZE];
} Block;

// Represents the file system
typedef struct {
    Block blocks[NUM_BLOCKS];
    bool block_allocated[NUM_BLOCKS];
    int num_files;
    char file_names[MAX_FILES][FILE_NAME_SIZE];
    int file_blocks[MAX_FILES];
} FileSystem;

// Initializes the file system
void init_file_system(FileSystem* fs) {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        memset(fs->blocks[i].data, 0, BLOCK_SIZE);
        fs->block_allocated[i] = false;
    }
    fs->num_files = 0;
}

// Finds an available block in the file system
int find_free_block(FileSystem* fs) {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (!fs->block_allocated[i]) {
            fs->block_allocated[i] = true;
            return i;
        }
    }
    return -1;
}

// Creates a new file in the file system
void create_file(FileSystem* fs, char* file_name, char* data) {
    if (fs->num_files >= MAX_FILES) {
        printf("Error: Maximum number of files reached\n");
        return;
    }
    int block_idx = find_free_block(fs);
    if (block_idx == -1) {
        printf("Error: File system is full\n");
        return;
    }
    strcpy(fs->file_names[fs->num_files], file_name);
    fs->file_blocks[fs->num_files] = block_idx;
    strcpy(fs->blocks[block_idx].data, data);
    fs->num_files++;
}

// Deletes a file from the file system
void delete_file(FileSystem* fs, char* file_name) {
    int file_idx = -1;
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(file_name, fs->file_names[i]) == 0) {
            file_idx = i;
            break;
        }
    }
    if (file_idx == -1) {
        printf("Error: File not found\n");
        return;
    }
    int block_idx = fs->file_blocks[file_idx];
    fs->block_allocated[block_idx] = false;
    strcpy(fs->file_names[file_idx], "");
    fs->num_files--;
}

// Reads data from a file in the file system
void read_file(FileSystem* fs, char* file_name, char* output) {
    int file_idx = -1;
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(file_name, fs->file_names[i]) == 0) {
            file_idx = i;
            break;
        }
    }
    if (file_idx == -1) {
        printf("Error: File not found\n");
        return;
    }
    int block_idx = fs->file_blocks[file_idx];
    strcpy(output, fs->blocks[block_idx].data);
}

// Writes data to a file in the file system
void write_file(FileSystem* fs, char* file_name, char* data) {
    int file_idx = -1;
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(file_name, fs->file_names[i]) == 0) {
            file_idx = i;
            break;
        }
    }
    if (file_idx == -1) {
        printf("Error: File not found\n");
        return;
    }
    int block_idx = fs->file_blocks[file_idx];
    strcpy(fs->blocks[block_idx].data, data);
}

int main() {
    FileSystem fs;
    char filename[FILE_NAME_SIZE];
    char data[BLOCK_SIZE];
    char output[BLOCK_SIZE];

    init_file_system(&fs);

    // Create a file
    strcpy(filename, "file1");
    strcpy(data, "This is file 1");
    create_file(&fs, filename, data);

    // Read from a file
    strcpy(filename, "file1");
    read_file(&fs, filename, output);
    printf("File contents: %s\n", output);

    // Write to a file
    strcpy(filename, "file1");
    strcpy(data, "Updated content for file 1");
    write_file(&fs, filename, data);

    // Read from a file again
    strcpy(filename, "file1");
    read_file(&fs, filename, output);
    printf("Updated file contents: %s\n", output);

    // Delete a file
    strcpy(filename, "file1");
    delete_file(&fs, filename);

    return 0;
}