//FormAI DATASET v1.0 Category: File system simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 20
#define MAX_FILE_SIZE 10000

typedef struct {
    char filename[MAX_FILENAME_SIZE];
    int size;
    int content[MAX_FILE_SIZE];
} File;

typedef struct {
    File* files[MAX_FILE_SIZE];
    int num_files;
} FileSystem;

void initialize(FileSystem* fs) {
    fs->num_files = 0;
}

void create(FileSystem* fs, char* filename, int size) {
    if (fs->num_files >= MAX_FILE_SIZE) {
        fprintf(stderr, "Error: file system full\n");
        return;
    }
    
    File* new_file = malloc(sizeof(File));
    strncpy(new_file->filename, filename, MAX_FILENAME_SIZE-1);
    new_file->filename[MAX_FILENAME_SIZE-1] = '\0';
    new_file->size = size;
    for (int i = 0; i < size; i++) {
        new_file->content[i] = rand() % 256;
    }
    
    fs->files[fs->num_files] = new_file;
    fs->num_files++;
}

void delete(FileSystem* fs, int index) {
    if (index < 0 || index >= fs->num_files) {
        fprintf(stderr, "Error: invalid index\n");
        return;
    }
    
    free(fs->files[index]);
    fs->num_files--;
    for (int i = index; i < fs->num_files; i++) {
        fs->files[i] = fs->files[i+1];
    }
}

void print_file(File* file) {
    printf("%s (%d bytes):", file->filename, file->size);
    for (int i = 0; i < file->size; i++) {
        printf(" %d", file->content[i]);
    }
    printf("\n");
}

void ls(FileSystem* fs) {
    printf("File list (%d files):\n", fs->num_files);
    for (int i = 0; i < fs->num_files; i++) {
        printf("%d. ", i);
        print_file(fs->files[i]);
    }
}

int main() {
    FileSystem my_fs;
    initialize(&my_fs);
    
    create(&my_fs, "file1.txt", 5);
    create(&my_fs, "file2.txt", 10);
    create(&my_fs, "file3.txt", 15);
    ls(&my_fs);
    
    delete(&my_fs, 1);
    printf("After deleting file2.txt:\n");
    ls(&my_fs);
    
    return 0;
}