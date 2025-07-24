//FormAI DATASET v1.0 Category: File system simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 64
#define MAX_PATH_LEN 256
#define MAX_FILES 100

// Define the file structure
typedef struct file {
    char name[MAX_NAME_LEN];
    int size;
    char content[MAX_PATH_LEN];
} file_t;

// Define the directory structure
typedef struct directory {
    char name[MAX_NAME_LEN];
    int num_files;
    file_t files[MAX_FILES];
} directory_t;

// Define the root directory
directory_t root_dir = {
    .name = "/",
    .num_files = 0,
    .files = {}
};

// Function to add a file to a directory
void add_file(directory_t *dir, char *name, int size, char *content) {
    if (dir->num_files >= MAX_FILES) {
        printf("Directory full!\n");
        return;
    }
    file_t new_file = {
        .size = size,
    };
    strcpy(new_file.name, name);
    strcpy(new_file.content, content);
    dir->files[dir->num_files++] = new_file;
}

// Function to find a file in a directory
file_t *find_file(directory_t *dir, char *name) {
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            return &dir->files[i];
        }
    }
    return NULL;
}

// Function to print the contents of a directory
void print_dir(directory_t *dir, char *path) {
    printf("%s:\n", path);
    for (int i = 0; i < dir->num_files; i++) {
        printf("%s\n", dir->files[i].name);
    }
}

// Main function
int main() {
    directory_t home_dir = {
        .name = "home",
        .num_files = 0,
        .files = {}
    };
    directory_t user_dir = {
        .name = "user",
        .num_files = 0,
        .files = {}
    };
    add_file(&root_dir, "home", 0, "");
    add_file(&root_dir, "user", 0, "");
    add_file(&home_dir, "file1.txt", 10, "Hello, world!");
    add_file(&home_dir, "file2.txt", 5, "Wow!");
    add_file(&user_dir, "file3.txt", 7, "Goodbye...");
    
    char path[MAX_PATH_LEN];
    strcpy(path, "/home");
    print_dir(find_file(find_file(&root_dir, "home"), "user"), path);
    
    return 0;
}