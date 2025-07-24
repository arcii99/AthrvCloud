//FormAI DATASET v1.0 Category: File system simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_FILE_SIZE 1000

// Structure for the file
struct file {
    char file_name[MAX_FILE_NAME];
    char file_contents[MAX_FILE_SIZE];
    int file_size;
};

// Structure for the file system
struct file_system {
    struct file files[MAX_FILE_SIZE];
    int num_files;
    int size;
};

// Function to create a file in the file system
void create_file(struct file_system *fs, char *name, char *contents, int size) {
    // Check if there is still space left in the file system
    if (fs->size + size > MAX_FILE_SIZE * MAX_FILE_SIZE) {
        printf("File system is full.\n");
        return;
    }

    // Check if a file with the same name already exists in the file system
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].file_name, name) == 0) {
            printf("File %s already exists.\n", name);
            return;
        }
    }

    // Create the file and add it to the file system
    struct file new_file;
    strcpy(new_file.file_name, name);
    strcpy(new_file.file_contents, contents);
    new_file.file_size = size;

    fs->files[fs->num_files++] = new_file;
    fs->size += size;

    printf("File %s created.\n", name);
}

// Function to view the contents of a file
void view_file(struct file_system *fs, char *name) {
    // Check if the file exists in the file system
    int found = 0;

    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].file_name, name) == 0) {
            printf("%s\n", fs->files[i].file_contents);
            found = 1;
        }
    }

    if (!found) {
        printf("File %s does not exist.\n", name);
    }
}

// Function to delete a file from the file system
void delete_file(struct file_system *fs, char *name) {
    // Check if the file exists in the file system
    int found = 0;
    
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].file_name, name) == 0) {
            fs->size -= fs->files[i].file_size;

            // Remove the file from the array
            for (int j = i; j < fs->num_files - 1; j++) {
                fs->files[j] = fs->files[j + 1];
            }

            fs->num_files--;
            found = 1;

            printf("File %s deleted.\n", name);
        }
    }

    if (!found) {
        printf("File %s does not exist.\n", name);
    }
}

int main() {
    struct file_system fs;
    fs.num_files = 0;
    fs.size = 0;

    // Create some test files
    char file1_contents[MAX_FILE_SIZE] = "Hello, world!";
    create_file(&fs, "file1.txt", file1_contents, strlen(file1_contents));

    char file2_contents[MAX_FILE_SIZE] = "This is a test.";
    create_file(&fs, "file2.txt", file2_contents, strlen(file2_contents));

    // View the contents of file1.txt
    view_file(&fs, "file1.txt");

    // Delete file2.txt
    delete_file(&fs, "file2.txt");

    return 0;
}