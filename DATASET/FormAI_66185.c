//FormAI DATASET v1.0 Category: File system simulation ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_DIR_SIZE 10
#define MAX_FILE_SIZE 20

struct directory {
    char name[MAX_DIR_SIZE];
    struct file *files[MAX_FILE_SIZE];
    int file_count;
    struct directory *subdirs[MAX_DIR_SIZE];
    int subdir_count;
};

struct file {
    char name[MAX_FILE_SIZE];
    int size;
    char *data;
};

void create_file(struct directory *dir, char *name, int size, char *data) {
    struct file *file = (struct file*) malloc(sizeof(struct file));
    strcpy(file->name, name);
    file->size = size;
    file->data = (char*) malloc(size);
    strcpy(file->data, data);
    dir->files[dir->file_count++] = file;
}

void create_subdir(struct directory *dir, char *name) {
    struct directory *subdir = (struct directory*) malloc(sizeof(struct directory));
    strcpy(subdir->name, name);
    dir->subdirs[dir->subdir_count++] = subdir;
}

void list_files(struct directory *dir) {
    printf("Files in %s:\n", dir->name);
    for (int i=0; i<dir->file_count; i++) {
        printf("%s (%d bytes)\n", dir->files[i]->name, dir->files[i]->size);
    }
}

void list_subdirs(struct directory *dir) {
    printf("Subdirectories in %s:\n", dir->name);
    for (int i=0; i<dir->subdir_count; i++) {
        printf("%s\n", dir->subdirs[i]->name);
    }
}

void list_all(struct directory *dir) {
    list_files(dir);
    list_subdirs(dir);
    for (int i=0; i<dir->subdir_count; i++) {
        list_all(dir->subdirs[i]);
    }
}

int main() {
    struct directory root;
    strcpy(root.name, "/");
    root.file_count = 0;
    root.subdir_count = 0;
    create_file(&root, "file1.txt", 10, "hello");
    create_file(&root, "file2.txt", 15, "world");
    create_subdir(&root, "dir1");
    create_subdir(&root, "dir2");
    struct directory *dir1 = root.subdirs[0];
    struct directory *dir2 = root.subdirs[1];
    create_file(dir1, "file3.txt", 20, "this is");
    create_file(dir1, "file4.txt", 25, "a test");
    create_subdir(dir1, "dir3");
    create_subdir(dir2, "dir4");
    list_all(&root);
    return 0;
}