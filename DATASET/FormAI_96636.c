//FormAI DATASET v1.0 Category: File system simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// C File System Simulation Program

// File structure to hold file information
typedef struct {
    char name[20]; // Name of the file
    int size;      // Size of the file in bytes
    char data[100]; // Data in the file (for this simulation, we'll limit to 100 characters)
} file_t;

// Directory structure to hold directory information
typedef struct {
    char name[20]; // Name of the directory
    int num_files; // Number of files in the directory
    file_t files[10]; // Array of files in the directory (for this simulation, we'll limit to 10 files)
} directory_t;

// Function prototypes
void create_directory(directory_t *dir, char *name);
void create_file(directory_t *dir, char *filename, int size, char *data);
void print_directory(directory_t dir);

// Main function
int main() {
    directory_t root; // Root directory
    create_directory(&root, "root"); // Create root directory
    create_file(&root, "file1", 50, "This is file 1."); // Create file1 in root
    create_file(&root, "file2", 75, "This is file 2."); // Create file2 in root
    directory_t dir1; // New directory in root
    create_directory(&dir1, "dir1"); // Create directory in root
    create_file(&dir1, "file3", 30, "This is file 3."); // Create file3 in dir1
    create_file(&dir1, "file4", 80, "This is file 4."); // Create file4 in dir1
    directory_t dir2; // Another new directory in root
    create_directory(&dir2, "dir2"); // Create directory in root
    create_file(&dir2, "file5", 60, "This is file 5."); // Create file5 in dir2
    create_file(&dir2, "file6", 20, "This is file 6."); // Create file6 in dir2

    // Print the root directory
    printf("Directory: %s\n", root.name);
    print_directory(root);

    return 0;
}

// Function to create a new directory
void create_directory(directory_t *dir, char *name) {
    strcpy(dir->name, name); // Set the directory name
    dir->num_files = 0; // Initialize the number of files to 0
}

// Function to create a new file
void create_file(directory_t *dir, char *filename, int size, char *data) {
    // Create file structure
    file_t new_file;
    strcpy(new_file.name, filename);
    new_file.size = size;
    strcpy(new_file.data, data);
    // Add file to directory
    int num_files = dir->num_files; // Current number of files in directory
    if (num_files < 10) { // Limit directory to 10 files
        dir->files[num_files] = new_file; // Add new file to directory
        dir->num_files++; // Increment number of files in directory
    }
}

// Function to print a directory and its files
void print_directory(directory_t dir) {
    printf("Files:\n");
    for (int i = 0; i < dir.num_files; i++) {
        printf("%s (%d bytes): %s\n", dir.files[i].name, dir.files[i].size, dir.files[i].data);
    }
}