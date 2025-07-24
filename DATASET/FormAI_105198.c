//FormAI DATASET v1.0 Category: File system simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 256

// Define struct for file
struct File {
    char filename[MAX_FILENAME_LENGTH];
    int size;
};

// Define struct for file system
struct FileSystem {
    struct File files[MAX_FILES];
    int num_files;
    int total_size;
};

// Function to add a new file to the file system
void add_file(struct FileSystem *file_system, char *filename, int size) {
    if (file_system->num_files >= MAX_FILES) {
        printf("File system is full!\n");
        return;
    }

    strcpy(file_system->files[file_system->num_files].filename, filename);
    file_system->files[file_system->num_files].size = size;
    file_system->num_files++;
    file_system->total_size += size;

    printf("Added file %s with size %d\n", filename, size);
}

// Function to remove an existing file from the file system
void remove_file(struct FileSystem *file_system, char *filename) {
    int index = -1;

    for (int i = 0; i < file_system->num_files; i++) {
        if (strcmp(file_system->files[i].filename, filename) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("File not found!\n");
        return;
    }

    int size = file_system->files[index].size;
    for (int i = index; i < file_system->num_files - 1; i++) {
        strcpy(file_system->files[i].filename, file_system->files[i + 1].filename);
        file_system->files[i].size = file_system->files[i + 1].size;
    }

    file_system->num_files--;
    file_system->total_size -= size;

    printf("Removed file %s with size %d\n", filename, size);
}

// Function to display the contents of the file system
void list_files(struct FileSystem *file_system) {
    printf("Total size of file system: %d\n", file_system->total_size);

    for (int i = 0; i < file_system->num_files; i++) {
        printf("%s\t%d\n", file_system->files[i].filename, file_system->files[i].size);
    }
}

// Main function
int main() {
    struct FileSystem file_system = {0};

    add_file(&file_system, "file1.txt", 100);
    add_file(&file_system, "file2.txt", 200);
    list_files(&file_system);

    remove_file(&file_system, "file1.txt");
    list_files(&file_system);

    return 0;
}