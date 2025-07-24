//FormAI DATASET v1.0 Category: File system simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_FILE_SYSTEM_SIZE 100
#define MAX_FILE_NAME_LENGTH 20
#define MAX_FILE_NUMBER 10

// Struct for the file system
typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char* content;
} File;

// Array to hold all the files in the system
File fileSystem[MAX_FILE_NUMBER];

// Function declarations
void initializeFileSystem();
void createFile(char name[], int size);
void deleteFile(char name[]);
File* findFileByName(char name[]);
void writeFileContent(char name[], char content[]);
void readFileContent(char name[]);

int main() {
    initializeFileSystem();
    createFile("file1.txt", 50);
    createFile("file2.txt", 100);
    writeFileContent("file1.txt", "This is the content of file 1.");
    readFileContent("file1.txt");
    printf("\nDeleting file1.txt\n");
    deleteFile("file1.txt");
    readFileContent("file1.txt");
    return 0;
}

// Initialize the file system
void initializeFileSystem() {
    int i;
    for (i = 0; i < MAX_FILE_NUMBER; i++) {
        fileSystem[i].name[0] = '\0';
        fileSystem[i].size = 0;
        fileSystem[i].content = NULL;
    }
}

// Create a new file of given size
void createFile(char name[], int size) {
    File* existingFile = findFileByName(name);
    if (existingFile != NULL) {
        printf("Error: A file with this name already exists.\n");
        return;
    }
    int i;
    for (i = 0; i < MAX_FILE_NUMBER; i++) {
        if (fileSystem[i].name[0] == '\0') {
            strcpy(fileSystem[i].name, name);
            fileSystem[i].size = size;
            fileSystem[i].content = (char*) malloc(sizeof(char) * size);
            printf("File %s created.\n", name);
            return;
        }
    }
    printf("Error: File system is full.\n");
}

// Delete a file with the given name
void deleteFile(char name[]) {
    File* existingFile = findFileByName(name);
    if (existingFile == NULL) {
        printf("Error: File not found.\n");
        return;
    }
    existingFile->name[0] = '\0';
    existingFile->size = 0;
    free(existingFile->content);
    existingFile->content = NULL;
    printf("File %s deleted.\n", name);
}

// Find a file in the system by name
File* findFileByName(char name[]) {
    int i;
    for (i = 0; i < MAX_FILE_NUMBER; i++) {
        if (strcmp(fileSystem[i].name, name) == 0) {
            return &fileSystem[i];
        }
    }
    return NULL;
}

// Write content to a file with the given name
void writeFileContent(char name[], char content[]) {
    File* existingFile = findFileByName(name);
    if (existingFile == NULL) {
        printf("Error: File not found.\n");
        return;
    }
    if (strlen(content) > existingFile->size) {
        printf("Error: File size is too small.\n");
        return;
    }
    strcpy(existingFile->content, content);
    printf("Content written to file %s.\n", name);
}

// Read content from a file with the given name
void readFileContent(char name[]) {
    File* existingFile = findFileByName(name);
    if (existingFile == NULL) {
        printf("Error: File not found.\n");
        return;
    }
    printf("Content of file %s: %s\n", name, existingFile->content);
}