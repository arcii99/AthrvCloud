//FormAI DATASET v1.0 Category: File system simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_FILES 100

// Create a file structure to represent each file in the file system
typedef struct {
    char name[MAX_NAME_LENGTH];
    int size;
} File;

// Create a file system structure to hold the files
typedef struct {
    File files[MAX_FILES];
    int num_files;
    int total_size;
} FileSystem;

// Initialize a new file system
void init_file_system(FileSystem* fs) {
    fs->num_files = 0;
    fs->total_size = 0;
}

// Add a new file to the file system
void add_file(FileSystem* fs, const char* name, int size) {
    if (fs->num_files >= MAX_FILES) {
        fprintf(stderr, "Error: file system full\n");
        return;
    }

    // Create a new file
    File f;
    strncpy(f.name, name, MAX_NAME_LENGTH);
    f.size = size;

    // Add the new file to the file system
    fs->files[fs->num_files] = f;
    fs->num_files++;
    fs->total_size += size;
}

// Print the contents of the file system
void print_file_system(FileSystem* fs) {
    printf("%d files in file system\n", fs->num_files);
    printf("Total size: %d bytes\n", fs->total_size);

    for (int i = 0; i < fs->num_files; i++) {
        printf("File %d: %s (%d bytes)\n", i + 1, fs->files[i].name, fs->files[i].size);
    }
}

int main() {
    FileSystem fs;
    init_file_system(&fs);

    add_file(&fs, "file1.txt", 100);
    add_file(&fs, "file2.txt", 200);
    add_file(&fs, "file3.txt", 50);

    print_file_system(&fs);

    return 0;
}