//FormAI DATASET v1.0 Category: File system simulation ; Style: satisfied
/*
 * C File System Simulation Program
 * Author: [Your Name]
 * Date: [Current Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 25
#define MAX_FILE_SIZE 100
#define MAX_NUM_FILES 10

typedef struct { // File structure
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char data[MAX_FILE_SIZE];
} File;

typedef struct { // Directory structure
    File files[MAX_NUM_FILES];
    int num_files;
} Directory;

/* Function Prototypes */
void create_file(Directory *dir, char *name, int size);
void delete_file(Directory *dir, char *name);
void list_files(Directory *dir);
void read_file(Directory *dir, char *name);
void write_file(Directory *dir, char *name, char *data);

int main() {
    Directory dir;
    dir.num_files = 0;

    create_file(&dir, "file1.txt", 50);
    create_file(&dir, "file2.txt", 25);
    create_file(&dir, "file3.txt", 75);
    list_files(&dir);

    write_file(&dir, "file2.txt", "This is some new text!");
    read_file(&dir, "file2.txt");

    delete_file(&dir, "file2.txt");
    list_files(&dir);

    return 0;
}

/* Functions */

/* Creates a new file in the directory with the given name and size */
void create_file(Directory *dir, char *name, int size) {
    if (dir->num_files == MAX_NUM_FILES) {
        printf("Error: Directory is full\n");
        return;
    }

    File new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    memset(new_file.data, 0, MAX_FILE_SIZE); // Initialize data as empty

    dir->files[dir->num_files] = new_file;
    dir->num_files++;

    printf("Created file '%s' with a size of %d bytes\n", name, size);
}

/* Deletes the file with the given name from the directory */
void delete_file(Directory *dir, char *name) {
    int index_to_delete = -1;
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            index_to_delete = i;
            break; // Found the file to delete
        }
    }

    if (index_to_delete == -1) {
        printf("Error: File '%s' not found\n", name);
        return;
    }

    printf("Deleted file '%s'\n", name);

    // Shift all files to the right of the deleted file to the left
    for (int i = index_to_delete; i < dir->num_files - 1; i++) {
        dir->files[i] = dir->files[i+1];
    }

    dir->num_files--;
}

/* Lists all files in the directory */
void list_files(Directory *dir) {
    printf("Files in directory:\n");
    for (int i = 0; i < dir->num_files; i++) {
        printf("- %s (%d bytes)\n", dir->files[i].name, dir->files[i].size);
    }
}

/* Reads the contents of the file with the given name */
void read_file(Directory *dir, char *name) {
    File *file_to_read = NULL;
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            file_to_read = &(dir->files[i]);
            break; // Found the file to read
        }
    }

    if (file_to_read == NULL) {
        printf("Error: File '%s' not found\n", name);
        return;
    }

    printf("Contents of file '%s':\n%s\n", name, file_to_read->data);
}

/* Overwrites the contents of the file with the given data */
void write_file(Directory *dir, char *name, char *data) {
    File *file_to_write = NULL;
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            file_to_write = &(dir->files[i]);
            break; // Found the file to write to
        }
    }

    if (file_to_write == NULL) {
        printf("Error: File '%s' not found\n", name);
        return;
    }

    int data_length = strlen(data);
    if (data_length > MAX_FILE_SIZE) {
        printf("Error: Data exceeds maximum file size of %d bytes\n", MAX_FILE_SIZE);
        return;
    }

    strcpy(file_to_write->data, data);
    printf("Wrote data to file '%s'\n", name);
}