//FormAI DATASET v1.0 Category: File system simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 50
#define MAX_FILES 100

// defining a data structure for file system's file
struct file {
    char name[MAX_NAME_LENGTH];
    int size;
    char content[MAX_NAME_LENGTH];
};

// defining a data structure for file system's directory
struct directory {
    char name[MAX_NAME_LENGTH];
    int num_files;
    struct file files[MAX_FILES];
};

// function to add a file to a directory
void add_file(struct directory* dir, char* name, int size, char* content) {
    if (dir->num_files >= MAX_FILES) {
        printf("Error: directory is full!\n");
        return;
    }
    struct file new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    strcpy(new_file.content, content);
    dir->files[dir->num_files] = new_file;
    dir->num_files++;
}

int main() {
    // creating directories
    struct directory root;
    struct directory documents;
    struct directory pictures;
    struct directory videos;

    strcpy(root.name, "Root");
    strcpy(documents.name, "Documents");
    strcpy(pictures.name, "Pictures");
    strcpy(videos.name, "Videos");

    // adding files to directories
    add_file(&documents, "notes.txt", 100, "These are my notes.");
    add_file(&pictures, "beach.jpg", 500, "aGkgdGhpcyBpcyBhIGJlYWNoLmpwZw==");
    add_file(&videos, "cat.avi", 1000, "aGVsbG8gd29ybGQK");

    // adding directories to root directory
    struct directory children[3] = {documents, pictures, videos};
    root.num_files = 3;
    memcpy(root.files, children, sizeof(children));

    // printing file system structure
    printf("%s\n", root.name);
    for (int i=0; i<root.num_files; i++) {
        printf("|-- %s\n", root.files[i].name);
    }
    printf("\n%s\n", documents.name);
    for (int i=0; i<documents.num_files; i++) {
        printf("|-- %s\n", documents.files[i].name);
    }
    printf("\n%s\n", pictures.name);
    for (int i=0; i<pictures.num_files; i++) {
        printf("|-- %s\n", pictures.files[i].name);
    }
    printf("\n%s\n", videos.name);
    for (int i=0; i<videos.num_files; i++) {
        printf("|-- %s\n", videos.files[i].name);
    }

    return 0;
}