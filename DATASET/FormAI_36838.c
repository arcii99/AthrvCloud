//FormAI DATASET v1.0 Category: File system simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 1000
#define MAX_FILE_NAME 100
#define MAX_FILE_SIZE 1000

// Structure to represent a file
struct File {
    char name[MAX_FILE_NAME];
    int size;
    char content[MAX_FILE_SIZE];
};

// Global file system array
struct File file_system[MAX_FILES];
int total_files = 0;

// Function to check if file with given name already exists
int file_exists(char* name) {
    for (int i = 0; i < total_files; i++) {
        if (strcmp(name, file_system[i].name) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to create a new file
void create_file(char* name, char* content) {
    // Check if file with given name already exists
    if (file_exists(name)) {
        printf("File with name '%s' already exists!\n", name);
        return;
    }

    // Create new file and add to file system
    struct File new_file;
    strcpy(new_file.name, name);
    new_file.size = strlen(content);
    strcpy(new_file.content, content);
    file_system[total_files++] = new_file;

    printf("File '%s' created successfully!\n", name);
}

// Function to delete a file
void delete_file(char* name) {
    // Check if file with given name exists
    int index = -1;
    for (int i = 0; i < total_files; i++) {
        if (strcmp(name, file_system[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("File with name '%s' not found!\n", name);
        return;
    }

    // Delete file and shift files to fill gap
    for (int i = index; i < total_files-1; i++) {
        file_system[i] = file_system[i+1];
    }
    total_files--;

    printf("File '%s' deleted successfully!\n", name);
}

// Function to read content of a file
void read_file(char* name) {
    // Check if file with given name exists
    int index = -1;
    for (int i = 0; i < total_files; i++) {
        if (strcmp(name, file_system[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("File with name '%s' not found!\n", name);
        return;
    }

    // Print file content
    printf("Content of file '%s':\n", name);
    printf("%s\n", file_system[index].content);
}

int main() {
    // Example usage of file system
    create_file("file1.txt", "This is the content of file1.txt");
    create_file("file2.txt", "This is the content of file2.txt");

    read_file("file1.txt");
    read_file("file2.txt");

    delete_file("file1.txt");
    read_file("file1.txt");

    return 0;
}