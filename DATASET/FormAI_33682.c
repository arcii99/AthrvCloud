//FormAI DATASET v1.0 Category: File system simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

// Struct for file metadata
typedef struct file {
    char name[20];
    int size;
    char content[100];
    int is_available;
} File;

// Array to keep track of files in the file system
File file_system[MAX_FILES];

// Function to initialize the file system
void init_file_system() {
    for (int i = 0; i < MAX_FILES; i++) {
        file_system[i].is_available = 1;
    }
}

// Function to create a new file
int create_file(char *name, int size, char *content) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (file_system[i].is_available) {
            strcpy(file_system[i].name, name);
            file_system[i].size = size;
            strcpy(file_system[i].content, content);
            file_system[i].is_available = 0;
            return 1;
        }
    }
    printf("Error: maximum number of files reached!");
    return 0;
}

// Function to delete a file
int delete_file(char *name) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (!strcmp(file_system[i].name, name)) {
            file_system[i].is_available = 1;
            return 1;
        }
    }
    printf("Error: file not found!");
    return 0;
}

// Function to read the contents of a file
int read_file(char *name, char *content) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (!strcmp(file_system[i].name, name)) {
            strcpy(content, file_system[i].content);
            return 1;
        }
    }
    printf("Error: file not found!");
    return 0;
}

// Function to write to a file
int write_file(char *name, char *content) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (!strcmp(file_system[i].name, name)) {
            strcpy(file_system[i].content, content);
            return 1;
        }
    }
    printf("Error: file not found!");
    return 0;
}

// Main function to simulate file system
int main() {
    init_file_system();

    // Testing create_file function
    printf("Creating new file...\n");
    create_file("textfile.txt", 50, "Hello, world!");
    printf("File created successfully.\n");

    // Testing read_file function
    printf("Reading file contents...\n");
    char content[100];
    read_file("textfile.txt", content);
    printf("File contents: %s\n", content);

    // Testing write_file function
    printf("Writing to file...\n");
    write_file("textfile.txt", "Goodbye, world!");
    printf("File updated successfully.\n");

    // Testing read_file function again
    printf("Reading file contents...\n");
    read_file("textfile.txt", content);
    printf("File contents: %s\n", content);

    // Testing delete_file function
    printf("Deleting file...\n");
    delete_file("textfile.txt");
    printf("File deleted successfully.\n");

    // Testing read_file function after deletion
    printf("Reading file contents...\n");
    if (read_file("textfile.txt", content)) {
        printf("File contents: %s\n", content);
    }

    return 0;
}