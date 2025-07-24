//FormAI DATASET v1.0 Category: File system simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_SIZE 512

/* File structure */
typedef struct {
    char name[20];
    char contents[MAX_FILE_SIZE];
    int size;
} File;

/* Filsystem structure */
typedef struct {
    char name[20];
    File files[MAX_FILES];
    int num_files;
} Filesystem;

/* Helper function to get a file within a filesystem */
File* get_file(Filesystem* fs, char* name) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            return &(fs->files[i]);
        }
    }
    return NULL;
}

/* Helper function to create a file within a filesystem */
void create_file(Filesystem* fs, char* name) {
    if (fs->num_files >= MAX_FILES) {
        printf("Error: filesystem already has %d files\n", MAX_FILES);
        return;
    }

    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            printf("Error: file %s already exists\n", name);
            return;
        }
    }

    strncpy(fs->files[fs->num_files].name, name, 20);
    fs->files[fs->num_files].size = 0;
    fs->num_files++;
}

/* Helper function to write to a file within a filesystem */
void write_file(Filesystem* fs, char* name, char* contents) {
    File* file = get_file(fs, name);
    if (file == NULL) {
        printf("Error: file %s does not exist\n", name);
        return;
    }

    if (strlen(contents) > MAX_FILE_SIZE) {
        printf("Error: file size exceeds maximum size of %d bytes\n", MAX_FILE_SIZE);
        return;
    }

    strncpy(file->contents, contents, MAX_FILE_SIZE);
    file->size = strlen(contents);
}

/* Helper function to read from a file within a filesystem */
char* read_file(Filesystem* fs, char* name) {
    File* file = get_file(fs, name);
    if (file == NULL) {
        printf("Error: file %s does not exist\n", name);
        return NULL;
    }
    return file->contents;
}

int main() {
    // Create a new filesystem
    Filesystem fs;
    strncpy(fs.name, "My Filesystem", 20);
    fs.num_files = 0;

    // Create a new file
    create_file(&fs, "test.txt");

    // Write to the file
    write_file(&fs, "test.txt", "Hello, world!");

    // Read from the file
    char* contents = read_file(&fs, "test.txt");
    printf("%s\n", contents);

    return 0;
}