//FormAI DATASET v1.0 Category: File system simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for file system
#define MAX_FILES 100
#define MAX_NAME_LENGTH 20
#define MAX_CONTENT_LENGTH 500

// Define a struct for files
struct file {
    char name[MAX_NAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];
};

// Define the file system
struct file_system {
    struct file files[MAX_FILES];
    int num_files;
};

// Function to create a new file
struct file create_file(char *name, char *content) {
    struct file new_file;
    strcpy(new_file.name, name);
    strcpy(new_file.content, content);
    return new_file;
}

int main() {
    // Create a new file system
    struct file_system my_files;
    my_files.num_files = 0;

    // Add some files to the file system
    my_files.files[0] = create_file("file1.txt", "This is the first file.");
    my_files.num_files++;
    my_files.files[1] = create_file("file2.txt", "This is the second file.");
    my_files.num_files++;

    // Print out the files in the file system
    for (int i = 0; i < my_files.num_files; i++) {
        printf("File %d:\n", i+1);
        printf("Name: %s\n", my_files.files[i].name);
        printf("Content: %s\n", my_files.files[i].content);
    }

    return 0;
}