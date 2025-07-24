//FormAI DATASET v1.0 Category: File system simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 4096  // maximum file size in bytes
#define MAX_FILENAME_LENGTH 32  // maximum length of a file name
#define MAX_FILES 16  // maximum number of files that can be stored


typedef struct {
    char name[MAX_FILENAME_LENGTH];
    int size;
    char data[MAX_FILE_SIZE];
} file;


typedef struct {
    file files[MAX_FILES];
    int num_files;
} file_system;


// function to create a new file
void create_file(file_system* fs, char* name, char* data, int size) {
    // check if file already exists
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            printf("File '%s' already exists.\n", name);
            return;
        }
    }
    
    // check if enough space to store the file
    if (fs->num_files >= MAX_FILES) {
        printf("Cannot create file '%s', maximum number of files reached.\n", name);
        return;
    }
    
    // create new file
    file f;
    strcpy(f.name, name);
    f.size = size;
    memcpy(f.data, data, size);
    fs->files[fs->num_files] = f;
    fs->num_files++;
    printf("File '%s' created successfully.\n", name);
}


// function to read a file
void read_file(file_system* fs, char* name) {
    // find file by name
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            printf("File '%s' contents:\n%s\n", name, fs->files[i].data);
            return;
        }
    }
    
    // file not found
    printf("File '%s' not found.\n", name);
}


// function to delete a file
void delete_file(file_system* fs, char* name) {
    // find file by name
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            // shift all remaining files to the left to fill the space
            for (int j = i; j < fs->num_files-1; j++) {
                fs->files[j] = fs->files[j+1];
            }
            fs->num_files--;
            printf("File '%s' deleted successfully.\n", name);
            return;
        }
    }
    
    // file not found
    printf("File '%s' not found.\n", name);
}


int main() {
    // initialize file system
    file_system fs;
    fs.num_files = 0;
    
    // create files
    create_file(&fs, "file1.txt", "This is file 1.", 16);
    create_file(&fs, "file2.txt", "This is file 2.", 16);
    create_file(&fs, "file3.txt", "This is file 3.", 16);
    
    // read files
    read_file(&fs, "file2.txt");
    read_file(&fs, "file4.txt");
    
    // delete files
    delete_file(&fs, "file2.txt");
    delete_file(&fs, "file4.txt");
    
    return 0;
}