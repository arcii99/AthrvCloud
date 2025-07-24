//FormAI DATASET v1.0 Category: File system simulation ; Style: futuristic
// This is a futuristic C file system simulation example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_FILE_COUNT 10
#define MAX_SIZE 100

// File structure
typedef struct {
    char name[MAX_FILENAME_LENGTH];
    char content[MAX_SIZE];
    int size;
} File;

// File system structure
typedef struct {
    File files[MAX_FILE_COUNT];
    int count;
    int available_index;
} FileSystem;

// Function to initialize the file system
void init_fs(FileSystem *fs) {
    fs->count = 0;
    fs->available_index = 0;
    for (int i = 0; i < MAX_FILE_COUNT; i++) {
        memset(fs->files[i].name, '\0', MAX_FILENAME_LENGTH);
        memset(fs->files[i].content, '\0', MAX_SIZE);
        fs->files[i].size = 0;
    }
}

// Function to add a file to the file system
int add_file(FileSystem *fs, char *filename, char *content) {
    if (fs->count == MAX_FILE_COUNT) {
        printf("File system full!\n");
        return -1;
    }
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(filename, fs->files[i].name) == 0) {
            printf("File name already exists in the system!\n");
            return -1;
        }
    }
    int i = fs->available_index;
    strncpy(fs->files[i].name, filename, MAX_FILENAME_LENGTH);
    strncpy(fs->files[i].content, content, MAX_SIZE);
    fs->files[i].size = strlen(content);
    fs->available_index++;
    fs->count++;
    printf("File added to the system.\n");
    return 0;
}

// Function to delete a file from the file system
int delete_file(FileSystem *fs, char *filename) {
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(filename, fs->files[i].name) == 0) {
            memset(fs->files[i].name, '\0', MAX_FILENAME_LENGTH);
            memset(fs->files[i].content, '\0', MAX_SIZE);
            fs->files[i].size = 0;
            fs->count--;
            printf("File deleted from the system.\n");
            return 0;
        }
    }
    printf("File not found in the system!\n");
    return -1;
}

// Function to display all files in the file system
void display_all_files(FileSystem *fs) {
    if (fs->count == 0) {
        printf("No Files!\n");
        return;
    }
    printf("Total Files: %d\n", fs->count);
    printf("-------------------------\n");
    for (int i = 0; i < fs->count; i++) {
        printf("File Name: %s\n", fs->files[i].name);
        printf("File Size: %d\n", fs->files[i].size);
        printf("-------------------------\n");
    }
}

int main() {
    FileSystem fs;
    init_fs(&fs);

    add_file(&fs, "file1.txt", "This is file 1");
    add_file(&fs, "file2.txt", "This is file 2");
    add_file(&fs, "file3.txt", "This is file 3");
    display_all_files(&fs);

    delete_file(&fs, "file2.txt");
    display_all_files(&fs);

    return 0;
}