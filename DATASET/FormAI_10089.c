//FormAI DATASET v1.0 Category: File system simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILENAME_LEN 100
#define MAX_DIR_NAME_LEN 50
#define MAX_FILE_SIZE 1000

// File structure
typedef struct file {
    char *filename;
    char *contents;
    int size;
} File;

// Directory structure
typedef struct dir {
    char *dirname;
    File **files; // array of pointers to files
    int num_files;
    struct dir **subdirs; // array of pointers to subdirectories
    int num_subdirs;
} Dir;

// Utility function to create a new file
File *create_file(char *filename, char *contents) {
    File *f = (File*) malloc(sizeof(File));
    f->filename = (char*) malloc(MAX_FILENAME_LEN * sizeof(char));
    strcpy(f->filename, filename);
    f->contents = (char*) malloc(MAX_FILE_SIZE * sizeof(char));
    strcpy(f->contents, contents);
    f->size = strlen(f->contents);
    return f;
}

// Utility function to create a new directory
Dir *create_dir(char *dirname) {
    Dir *d = (Dir*) malloc(sizeof(Dir));
    d->dirname = (char*) malloc(MAX_DIR_NAME_LEN * sizeof(char));
    strcpy(d->dirname, dirname);
    d->files = (File**) malloc(100 * sizeof(File*));
    d->num_files = 0;
    d->subdirs = (Dir**) malloc(100 * sizeof(Dir*));
    d->num_subdirs = 0;
    return d;
}

// Utility function to add a file to a directory
void add_file_to_dir(Dir *dir, File *file) {
    dir->files[dir->num_files] = file;
    dir->num_files++;
}

// Utility function to add a subdirectory to a directory
void add_subdir_to_dir(Dir *dir, Dir *subdir) {
    dir->subdirs[dir->num_subdirs] = subdir;
    dir->num_subdirs++;
}

// Recursive function to search for a file in a directory and subdirectories
File *find_file(Dir *dir, char *filename) {
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i]->filename, filename) == 0) {
            return dir->files[i];
        }
    }

    for (int i = 0; i < dir->num_subdirs; i++) {
        File *f = find_file(dir->subdirs[i], filename);
        if (f != NULL) {
            return f;
        }
    }

    return NULL;
}

// Recursive function to print the contents of a directory and its subdirectories
void print_dir_contents(Dir *dir, int level) {
    for (int i = 0; i < level; i++) {
        printf("|   ");
    }
    printf("%s/\n", dir->dirname);

    for (int i = 0; i < dir->num_files; i++) {
        for (int j = 0; j < level + 1; j++) {
            printf("|   ");
        }
        printf("%s (%d bytes)\n", dir->files[i]->filename, dir->files[i]->size);
    }

    for (int i = 0; i < dir->num_subdirs; i++) {
        print_dir_contents(dir->subdirs[i], level + 1);
    }
}

int main() {
    Dir *root = create_dir("root");
    Dir *dir1 = create_dir("dir1");
    Dir *dir2 = create_dir("dir2");
    Dir *subdir1 = create_dir("subdir1");

    File *file1 = create_file("file1.txt", "This is the contents of file1.");
    File *file2 = create_file("file2.txt", "This is the contents of file2.");
    File *file3 = create_file("file3.txt", "This is the contents of file3.");
    File *file4 = create_file("file4.txt", "This is the contents of file4.");

    add_file_to_dir(root, file1);
    add_file_to_dir(root, file2);
    add_subdir_to_dir(root, dir1);
    add_subdir_to_dir(root, dir2);
    add_file_to_dir(dir1, file3);
    add_subdir_to_dir(dir1, subdir1);
    add_file_to_dir(subdir1, file4);

    File *found_file = find_file(root, "file3.txt");
    if (found_file != NULL) {
        printf("%s\n", found_file->contents);
    }

    print_dir_contents(root, 0);

    return 0;
}