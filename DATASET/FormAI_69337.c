//FormAI DATASET v1.0 Category: File system simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of files the file system can store
#define MAX_FILES 10

// Structure definition for a file
typedef struct file {
    char name[20];
    int size;
} File;

// Structure definition for the file system
typedef struct file_system {
    File files[MAX_FILES];
    int num_files;
    int total_size;
} FileSystem;

// Function to initialize a file system
void init_file_system(FileSystem *fs) {
    fs->num_files = 0;
    fs->total_size = 0;
}

// Function to add a file to the file system
void add_file(FileSystem *fs, char *name, int size) {
    // Check if the file system has reached its maximum capacity
    if (fs->num_files >= MAX_FILES) {
        printf("Error: File system is full\n");
        return;
    }
    // Check if the file already exists in the file system
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            printf("Error: File already exists in file system\n");
            return;
        }
    }
    // Add the file to the file system
    File new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    fs->files[fs->num_files] = new_file;
    fs->num_files++;
    fs->total_size += size;
}

// Function to delete a file from the file system
void delete_file(FileSystem *fs, char *name) {
    // Check if the file exists in the file system
    int index = -1;
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: File not found in file system\n");
        return;
    }
    // Delete the file from the file system
    fs->total_size -= fs->files[index].size;
    for (int i = index; i < fs->num_files - 1; i++) {
        fs->files[i] = fs->files[i+1];
    }
    fs->num_files--;
}

// Function to display the contents of the file system
void display_file_system(FileSystem *fs) {
    printf("Total size: %d\n", fs->total_size);
    printf("Number of files: %d\n", fs->num_files);
    printf("Files:\n");
    for (int i = 0; i < fs->num_files; i++) {
        printf("%s (%d bytes)\n", fs->files[i].name, fs->files[i].size);
    }
}

int main() {
    FileSystem fs;
    init_file_system(&fs);
    
    // Add some files to the file system
    add_file(&fs, "file1.txt", 100);
    add_file(&fs, "file2.txt", 200);
    add_file(&fs, "file3.txt", 300);
    add_file(&fs, "file4.txt", 400);
    add_file(&fs, "file5.txt", 500);
    
    // Display the contents of the file system
    display_file_system(&fs);
    
    // Delete a file from the file system
    delete_file(&fs, "file3.txt");
    
    // Display the contents of the file system again
    display_file_system(&fs);
    
    return 0;
}