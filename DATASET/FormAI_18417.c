//FormAI DATASET v1.0 Category: File system simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of files in the file system
#define MAX_FILES 10

// Define a file struct to store file information
typedef struct {
    int file_id;
    int file_size;
    bool is_allocated;
} file_t;

// Define a file system struct to store file system information
typedef struct {
    file_t files[MAX_FILES];
    int total_space;
    int space_allocated;
} file_system_t;

// Initialize a file system with the given total space
void init_file_system(file_system_t *fs, int total_space) {
    // Initialize all files to have a size of 0 and to be unallocated
    for (int i = 0; i < MAX_FILES; i++) {
        fs->files[i].file_id = i;
        fs->files[i].file_size = 0;
        fs->files[i].is_allocated = false;
    }

    // Set the total space and allocated space in the file system
    fs->total_space = total_space;
    fs->space_allocated = 0;
}

// Allocate space for a file
bool allocate_file_space(file_system_t *fs, int file_id, int file_size) {
    // Check if the file is already allocated or if there is not enough space
    if (fs->files[file_id].is_allocated || fs->space_allocated + file_size > fs->total_space) {
        return false;
    }

    // Set the file size and mark the file as allocated
    fs->files[file_id].file_size = file_size;
    fs->files[file_id].is_allocated = true;

    // Update the amount of space allocated in the file system
    fs->space_allocated += file_size;

    return true;
}

// Deallocate space for a file
void deallocate_file_space(file_system_t *fs, int file_id) {
    // Check if the file is allocated
    if (!fs->files[file_id].is_allocated) {
        return;
    }

    // Reset the file size and mark the file as unallocated
    fs->files[file_id].file_size = 0;
    fs->files[file_id].is_allocated = false;

    // Update the amount of space allocated in the file system
    fs->space_allocated -= fs->files[file_id].file_size;
}

int main() {
    // Initialize a file system with a total space of 100
    file_system_t fs;
    init_file_system(&fs, 100);

    // Allocate space for files of size 10, 20, and 30
    allocate_file_space(&fs, 0, 10);
    allocate_file_space(&fs, 1, 20);
    allocate_file_space(&fs, 2, 30);

    // Deallocate space for the second file
    deallocate_file_space(&fs, 1);

    // Print the status of each file
    for (int i = 0; i < MAX_FILES; i++) {
        printf("File %d: size=%d allocated=%d\n", fs.files[i].file_id, fs.files[i].file_size, fs.files[i].is_allocated);
    }

    return 0;
}