//FormAI DATASET v1.0 Category: File system simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 50
#define MAX_NAME_LENGTH 20

// Declaration of the file structure
typedef struct file {
    char name[MAX_NAME_LENGTH];
    struct file *sub_files[MAX_FILES];
    int num_sub_files;
} file;

// Declaration of the functions
void add_file(char *, file *);
void remove_file(char *, file *);
void list_files(file *, int);

// Definition of the add_file function
void add_file(char *name, file *dir) {
    if (dir->num_sub_files >= MAX_FILES) {
        printf("Error: directory full\n");
        return;
    }
    file *new_file = (file *) malloc(sizeof(file));
    strcpy(new_file->name, name);
    new_file->num_sub_files = 0;
    dir->sub_files[dir->num_sub_files] = new_file;
    dir->num_sub_files++;
    printf("File %s added successfully\n", name);
}

// Definition of the remove_file function
void remove_file(char *name, file *dir) {
    int i, j;
    for (i = 0; i < dir->num_sub_files; i++) {
        if (strcmp(name, dir->sub_files[i]->name) == 0) {
            for (j = i; j < dir->num_sub_files - 1; j++) {
                dir->sub_files[j] = dir->sub_files[j + 1];
            }
            dir->num_sub_files--;
            printf("File %s removed successfully\n", name);
            return;
        }
    }
    printf("Error: file not found\n");
}

// Definition of the list_files function
void list_files(file *dir, int level) {
    int i, j;
    for (i = 0; i < level; i++) {
        printf(" ");
    }
    printf("%s\n", dir->name);
    for (j = 0; j < dir->num_sub_files; j++) {
        list_files(dir->sub_files[j], level + 1);
    }
}

// Main function
int main() {
    
    // Create the root directory
    file root;
    strcpy(root.name, "root");
    root.num_sub_files = 0;
    
    // Add files to the root directory
    add_file("file1", &root);
    add_file("file2", &root);
    add_file("file3", &root);
    
    // List files in the root directory
    printf("Root directory:\n");
    list_files(&root, 0);
    
    // Remove a file from the root directory
    remove_file("file2", &root);
    
    // List files in the root directory after removal
    printf("Root directory after file2 removed:\n");
    list_files(&root, 0);
    
    return 0;
}