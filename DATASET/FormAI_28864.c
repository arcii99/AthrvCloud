//FormAI DATASET v1.0 Category: File system simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for file system
#define MAX_FILES 100
#define MAX_FILENAME 50
#define MAX_FILE_SIZE 1024

// Define a structure for a file
typedef struct File {
    char filename[MAX_FILENAME];
    int size;
    char data[MAX_FILE_SIZE];
} File;

// Define array of files for file system
File files[MAX_FILES];

// Define a function to create a file
void createFile(char* filename, char* data) {
    // Find an empty spot in the array of files
    int i;
    for (i = 0; i < MAX_FILES; i++) {
        if (files[i].size == 0) {
            // Create the new file
            strcpy(files[i].filename, filename);
            files[i].size = strlen(data) + 1;
            strcpy(files[i].data, data);
            printf("File created: %s\n", filename);
            return;
        }
    }
    // If we reach here, we couldn't find an empty spot
    printf("Error: Maximum number of files exceeded\n");
}

// Define a function to delete a file
void deleteFile(char* filename) {
    // Find the file in the array of files
    int i;
    for (i = 0; i < MAX_FILES; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            // Delete the file
            files[i].size = 0;
            printf("File deleted: %s\n", filename);
            return;
        }
    }
    // If we reach here, we couldn't find the file
    printf("Error: File not found\n");
}

// Define a function to get the contents of a file
char* readFile(char* filename) {
    // Find the file in the array of files
    int i;
    for (i = 0; i < MAX_FILES; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            // Return the contents of the file
            return files[i].data;
        }
    }
    // If we reach here, we couldn't find the file
    return "Error: File not found";
}

int main() {
    // Create some files
    createFile("file1.txt", "This is the contents of file1");
    createFile("file2.txt", "This is the contents of file2");
    
    // Read a file
    char* contents = readFile("file1.txt");
    printf("%s\n", contents);
    
    // Delete a file
    deleteFile("file2.txt");
    
    return 0;
}