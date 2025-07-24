//FormAI DATASET v1.0 Category: File system simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20

// Define a struct for the file
typedef struct {
    char name[MAX_FILENAME_LENGTH];
    int size;
} File;

// Define a struct for the file system
typedef struct {
    int total_size;
    int used_size;
    int num_files;
    File files[10];
} FileSystem;

// Function to create a new file in the file system
void create_file(FileSystem *fs, char *filename, int size) {
    // Check if the file system has enough space
    if (fs->total_size - fs->used_size < size) {
        printf("Error: Not enough space in the file system\n");
        return;
    }
    
    // Check if the file already exists
    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            printf("Error: File already exists\n");
            return;
        }
    }
    
    // Create the file and add it to the file system
    File new_file;
    strcpy(new_file.name, filename);
    new_file.size = size;
    
    fs->files[fs->num_files] = new_file;
    fs->num_files++;
    fs->used_size += size;
}

// Function to delete a file from the file system
void delete_file(FileSystem *fs, char *filename) {
    // Find the file in the file system
    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            // Remove the file from the file system
            fs->used_size -= fs->files[i].size;
            memmove(fs->files + i, fs->files + i + 1, sizeof(File) * (fs->num_files - i - 1));
            fs->num_files--;
            return;
        }
    }
    
    // If the file was not found, print an error message
    printf("Error: File not found\n");
}

// Function to print the current state of the file system
void print_file_system(FileSystem *fs) {
    printf("Total disk space: %d\n", fs->total_size);
    printf("Used disk space: %d\n", fs->used_size);
    printf("Free disk space: %d\n", fs->total_size - fs->used_size);
    printf("Number of files: %d\n", fs->num_files);
    printf("Files:\n");
    int i;
    for (i = 0; i < fs->num_files; i++) {
        printf("  %s (%d bytes)\n", fs->files[i].name, fs->files[i].size);
    }
}

int main() {
    // Create a file system with 1000 bytes of space
    FileSystem fs = {1000, 0, 0};
    
    // Create some files
    create_file(&fs, "file1.txt", 100);
    create_file(&fs, "file2.txt", 200);
    create_file(&fs, "file3.txt", 300);
    
    // Print the state of the file system
    print_file_system(&fs);
    
    // Delete a file
    delete_file(&fs, "file2.txt");
    
    // Print the state of the file system again
    print_file_system(&fs);

    return 0;
}